#include <stdio.h>
#include <Files.h>
#include <Dictionary.h>
#include <stddef.h>
#include "Settings.h"

struct Sub {
    double *sub1;
    double sub2;
    int32_t *sub3;
};

struct Struct1 {
    double option1;
    float option2;
    char option3;
    char *option4;
    struct Sub option5;
    char option6;
    char *option7;
};

#define SUBCOUNT 3
SET_TranslationTable SubTable[SUBCOUNT] = {
    {.name = "Sub1", .type = SET_DATATYPE_DOUBLE, .depth = 1, .offset = offsetof(struct Sub, sub1)},
    {.name = "Sub2", .type = SET_DATATYPE_DOUBLE, .depth = 0, .offset = offsetof(struct Sub, sub2)},
    {.name = "Sub3", .type = SET_DATATYPE_INT32, .depth = 1, .offset = offsetof(struct Sub, sub3)}
};

#define STRUCTCOUNT 7
SET_TranslationTable StructTable[STRUCTCOUNT] = {
    {.name = "Option1", .type = SET_DATATYPE_DOUBLE, .depth = 0, .offset = offsetof(struct Struct1, option1)},
    {.name = "Option2", .type = SET_DATATYPE_FLOAT, .depth = 0, .offset = offsetof(struct Struct1, option2)},
    {.name = "Option3", .type = SET_DATATYPE_CHAR, .depth = 0, .offset = offsetof(struct Struct1, option3)},
    {.name = "Option4", .type = SET_DATATYPE_STR, .depth = 0, .offset = offsetof(struct Struct1, option4)},
    {.name = "Option5", .type = SET_DATATYPE_STRUCT, .depth = 0, .offset = offsetof(struct Struct1, option5), .sub = SubTable, .size = sizeof(SubTable), .count = SUBCOUNT},
    {.name = "Option6", .type = SET_DATATYPE_CHAR, .depth = 0, .offset = offsetof(struct Struct1, option6)},
    {.name = "Option7", .type = SET_DATATYPE_STR, .depth = 0, .offset = offsetof(struct Struct1, option7)}
};

SET_TranslationTable FillTable[STRUCTCOUNT] = {
    {.name = "Option1", .type = SET_DATATYPE_DOUBLE, .depth = 0, .offset = offsetof(struct Struct1, option1)},
    {.name = "Option2", .type = SET_DATATYPE_FLOAT, .depth = 0, .offset = offsetof(struct Struct1, option2)},
    {.name = "Option3", .type = SET_DATATYPE_CHAR, .depth = 0, .offset = offsetof(struct Struct1, option3)},
    {.name = "Option4", .type = SET_DATATYPE_STR, .depth = 0, .offset = offsetof(struct Struct1, option4)},
    {.name = "Option5", .type = SET_DATATYPE_STRUCT, .depth = 0, .offset = offsetof(struct Struct1, option5), .sub = SubTable, .size = sizeof(SubTable), .count = SUBCOUNT},
    {.name = "Option6wrong", .type = SET_DATATYPE_CHAR, .depth = 0, .offset = offsetof(struct Struct1, option6)},
    {.name = "Option7", .type = SET_DATATYPE_STR, .depth = 0, .offset = offsetof(struct Struct1, option7)}
};

SET_TranslationTable EmptyTable[STRUCTCOUNT - 1] = {
    {.name = "Option1", .type = SET_DATATYPE_DOUBLE, .depth = 0, .offset = offsetof(struct Struct1, option1)},
    {.name = "Option3", .type = SET_DATATYPE_CHAR, .depth = 0, .offset = offsetof(struct Struct1, option3)},
    {.name = "Option4", .type = SET_DATATYPE_STR, .depth = 0, .offset = offsetof(struct Struct1, option4)},
    {.name = "Option5", .type = SET_DATATYPE_STRUCT, .depth = 0, .offset = offsetof(struct Struct1, option5), .sub = SubTable, .size = sizeof(SubTable), .count = SUBCOUNT},
    {.name = "Option6", .type = SET_DATATYPE_CHAR, .depth = 0, .offset = offsetof(struct Struct1, option6)},
    {.name = "Option7", .type = SET_DATATYPE_STR, .depth = 0, .offset = offsetof(struct Struct1, option7)}
};

void PrintCodeStruct(SET_CodeStruct * Struct);
void PrintCodeList(SET_CodeList *Struct);
void PrintCodeValue(SET_CodeValue *Struct);
void PrintDataStruct(DIC_Dict *Dict);
void PrintDataList(SET_DataList *List);
void PrintDataValue(SET_Data *Value);
void PrintStruct(struct Struct1 *Struct);

int main(int argc, char **argv)
{
    // Load test, just for testing
    char *Settings = FIL_Load("TestSettings.txt");

    if (Settings == NULL)
    {
        printf("Unable to open file: %s\n", FIL_GetError());
        return 0;
    }

    char *CleanString = _SET_CleanString(Settings);

    if (CleanString == NULL)
    {
        free(Settings);
        printf("Unable to clean string: %s\n", SET_GetError());
        return 0;
    }

    printf("Original string: %s\n\nCleaned String: %s\n\n", Settings, CleanString);
    
    printf("Starting splitting\n\n");
    SET_CodeStruct *SplitString = _SET_SplitString(CleanString);

    if (SplitString == NULL)
    {
        free(Settings);
        free(CleanString);
        printf("Unable to split string: %s\n", SET_GetError());
        return 0;
    }

    PrintCodeStruct(SplitString);

    printf("Successfully split\n\n");

    free(Settings);
    free(CleanString);
    SET_DestroyCodeStruct(SplitString);

    // Test total loading system
    printf("Starting loading\n");

    DIC_Dict *Dict = SET_LoadSettings("TestSettings.txt");

    if (Dict == NULL)
    {
        printf("Unable to load settings: %s\n", SET_GetError());
        return 0;
    }

    printf("Successfully loaded\n\n");

    PrintDataStruct(Dict);

    printf("\n\n");

    // Convert to a struct
    extern SET_TranslationTable StructTable[];

    struct Struct1 Struct;

    Struct.option1 = 0;
    Struct.option2 = 0;
    Struct.option3 = '\0';
    Struct.option4 = NULL;
    Struct.option5.sub1 = NULL;
    Struct.option5.sub2 = 0;
    Struct.option5.sub3 = NULL;
    Struct.option6 = '\0';
    Struct.option7 = NULL;

    if (!SET_Translate(&Struct, Dict, StructTable, STRUCTCOUNT, SET_TRANSLATIONMODE_NONE))
    {
        printf("Unable to translate settings: %s\n", SET_GetError());
        return 0;
    }

    // Print struct
    PrintStruct(&Struct);

    free(Struct.option4);
    free(Struct.option5.sub1);
    free(Struct.option5.sub3);

    Struct.option1 = 0;
    Struct.option2 = 0;
    Struct.option3 = '\0';
    Struct.option4 = NULL;
    Struct.option5.sub1 = NULL;
    Struct.option5.sub2 = 0;
    Struct.option5.sub3 = NULL;
    Struct.option6 = '\0';
    Struct.option7 = NULL;

    if (!SET_Translate(&Struct, Dict, StructTable, STRUCTCOUNT, SET_TRANSLATIONMODE_FILL | SET_TRANSLATIONMODE_EMPTY))
    {
        printf("Unable to translate settings: %s\n", SET_GetError());
        return 0;
    }

    // Print struct
    PrintStruct(&Struct);

    free(Struct.option4);
    free(Struct.option5.sub1);
    free(Struct.option5.sub3);

    // Make sure there are errors
    if (SET_Translate(&Struct, Dict, FillTable, STRUCTCOUNT, SET_TRANSLATIONMODE_FILL))
    {
        printf("There should have been a fill error\n");
        return 0;
    }

    printf("Fill Error: %s\n", SET_GetError());

    if (SET_Translate(&Struct, Dict, EmptyTable, STRUCTCOUNT - 1, SET_TRANSLATIONMODE_EMPTY))
    {
        printf("There should have been a empty error\n");
        return 0;
    }

    printf("Empty Error: %s\n", SET_GetError());

    SET_DestroyDataStruct(Dict);

    printf("\n\n");

    printf("Finished with no errors\n");

    return 0;
}

void PrintCodeStruct(SET_CodeStruct *Struct)
{
    for (uint32_t Pos = 0; Pos < Struct->count; ++Pos)
    {
        printf("Type: \"%s\", Pointer: %u, Name: \"%s\", Value: ", Struct->names[Pos]->type, Struct->names[Pos]->pointer, Struct->names[Pos]->name);
        PrintCodeValue(*(Struct->values + Pos));
        printf("\n");
    }
}

void PrintCodeList(SET_CodeList *Struct)
{
    for (SET_CodeValue **List = Struct->list, **EndList = Struct->list + Struct->count; List < EndList; ++List)
    {
        PrintCodeValue(*List);
        printf("\n");
    }
}

void PrintCodeValue(SET_CodeValue *Struct)
{
    // Print a normal value
    if (Struct->type == SET_VALUETYPE_VALUE)
        printf("\"%s\"", Struct->value.value);

    // Print a struct
    else if (Struct->type == SET_VALUETYPE_STRUCT)
    {
        printf("{\n");
        PrintCodeStruct(Struct->value.sub);
        printf("}");
    }

    // Print a list
    else if (Struct->type == SET_VALUETYPE_LIST)
    {
        printf("[\n");
        PrintCodeList(Struct->value.list);
        printf("]");
    }
}

void PrintDataStruct(DIC_Dict *Dict)
{
    printf("{\n");

    for (DIC_LinkList **List = Dict->list, **EndList = Dict->list + Dict->length; List < EndList; ++List)
        for (DIC_LinkList *Link = *List; Link != NULL; Link = Link->next)
        {
            printf("%s = ", Link->key);
            PrintDataValue((SET_Data *)Link->value);
            printf(";\n");
        }
    
    printf("\n} (Struct: %u)", SET_DATATYPE_STRUCT);
}

void PrintDataList(SET_DataList *List)
{
    printf("[");
    PrintDataValue(*List->list);

    for (SET_Data **DataList = List->list + 1, **EndDataList = List->list + List->count; DataList < EndDataList; ++DataList)
    {
        printf(", ");
        PrintDataValue(*DataList);
    }

    printf("] (List[%u]: %u)", List->depth, List->type);
}

void PrintDataValue(SET_Data *Value)
{
    switch (Value->type)
    {
        case (SET_DATATYPE_INT8):
        case (SET_DATATYPE_UINT8):
            printf("%u (uint8: %u)", Value->data.u8, Value->type);
            break;

        case (SET_DATATYPE_INT16):
        case (SET_DATATYPE_UINT16):
            printf("%u (uint16: %u)", Value->data.u16, Value->type);
            break;

        case (SET_DATATYPE_INT32):
        case (SET_DATATYPE_UINT32):
            printf("%u (uint32: %u)", Value->data.u32, Value->type);
            break;

        case (SET_DATATYPE_INT64):
        case (SET_DATATYPE_UINT64):
            printf("%lu (uint64: %u)", Value->data.u64, Value->type);
            break;

        case (SET_DATATYPE_SINT8):
            printf("%d (int8: %u)", Value->data.i8, Value->type);
            break;

        case (SET_DATATYPE_SINT16):
            printf("%d (int16: %u)", Value->data.i16, Value->type);
            break;

        case (SET_DATATYPE_SINT32):
            printf("%d (int32: %u)", Value->data.i32, Value->type);
            break;

        case (SET_DATATYPE_SINT64):
            printf("%ld (int64: %u)", Value->data.i64, Value->type);
            break;

        case (SET_DATATYPE_FLOAT):
            printf("%f (float: %u)", Value->data.f, Value->type);
            break;

        case (SET_DATATYPE_DOUBLE):
            printf("%f (double: %u)", Value->data.d, Value->type);
            break;

        case (SET_DATATYPE_CHAR):
            printf("%c (char: %u)", Value->data.c, Value->type);
            break;

        case (SET_DATATYPE_STR):
            printf("%s (str: %u)", Value->data.str, Value->type);
            break;

        case (SET_DATATYPE_LIST):
            PrintDataList(Value->data.list);
            break;

        case (SET_DATATYPE_STRUCT):
            PrintDataStruct(Value->data.stct);
            break;

        default:
            printf("Error, unknown type: %u\n", Value->type);
            break;
    }
}

void PrintStruct(struct Struct1 *Struct)
{
    printf("{.option1 = %f, .option2 = %f, .option3 = \'%c\', .option4 = \"%s\", .option5 = {.sub1 = [%f, %f, %f], .sub2 = %f, .sub3 = [%d, %d, %d]}, .option6 = \'%c\', .option7 = \"%s\"}", Struct->option1, Struct->option2, Struct->option3, Struct->option4, Struct->option5.sub1[0], Struct->option5.sub1[1], Struct->option5.sub1[2], Struct->option5.sub2, Struct->option5.sub3[0], Struct->option5.sub3[1], Struct->option5.sub3[2], Struct->option6, Struct->option7);
}
