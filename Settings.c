#include <stdio.h>
#include <Files.h>
#include "Settings.h"

void PrintCodeStruct(SET_CodeStruct *Struct);
void PrintCodeList(SET_CodeList *Struct);
void PrintCodeValue(SET_CodeValue *Struct);

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

    printf("Original string: %s\n\nCleaned String: %s\n\n\n", Settings, CleanString);

    free(Settings);
    free(CleanString);

    return 0;
}

void PrintCodeStruct(SET_CodeStruct *Struct)
{
    for (uint32_t Pos = 0; Pos < Struct->count - 1; ++Pos)
    {
        printf("Type: \"%s\", Name: \"%s\", Value:", Struct->names[Pos].type, Struct->names[Pos].name);
        PrintCodeValue(Struct->values + Pos);
        printf("\n");
    }
}

void PrintCodeList(SET_CodeList *Struct)
{
    for (SET_CodeValue *List = Struct->list, *EndList = Struct->list + Struct->count; List < EndList; ++List)
    {
        PrintCodeValue(List);
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