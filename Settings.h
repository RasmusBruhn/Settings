#ifndef SETTINGS_H_DEFINED
#define SETTINGS_H_DEFINED

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>

#define ERR_PREFIX SET
#include <Error.h>

enum __SET_Type {
    SET_TYPE_U8,
    SET_TYPE_U16,
    SET_TYPE_U32,
    SET_TYPE_U64,
    SET_TYPE_AU8,
    SET_TYPE_AU16,
    SET_TYPE_AU32,
    SET_TYPE_AU64,
    SET_TYPE_I8,
    SET_TYPE_I16,
    SET_TYPE_I32,
    SET_TYPE_I64,
    SET_TYPE_AI8,
    SET_TYPE_AI16,
    SET_TYPE_AI32,
    SET_TYPE_AI64,
    SET_TYPE_F,
    SET_TYPE_D,
    SET_TYPE_AF,
    SET_TYPE_AD,
    SET_TYPE_C,
    SET_TYPE_AC,
    SET_TYPE_S,
    SET_TYPE_AS
};

enum _SET_ErrorID {
    _SET_ERRORID_NONE = 0x300000000,
    _SET_ERRORID_CLEANSTRING_MALLOC = 0x300010200,
    _SET_ERRORID_CLEANSTRING_REALLOC = 0x300010201,
    _SET_ERRORID_SPLITSTRING_MALLOCSTRUCT = 0x300020200,
    _SET_ERRORID_SPLITSTRING_STOPCHAR = 0x300020201,
    _SET_ERRORID_SPLITSTRING_NOSTOPCHAR = 0x300020202,
    _SET_ERRORID_SPLITSTRING_SPACEINVALUE = 0x300020203,
    _SET_ERRORID_SPLITSTRING_TYPETWICE = 0x300020204,
    _SET_ERRORID_SPLITSTRING_VALUETWICE = 0x300020205,
    _SET_ERRORID_SPLITSTRING_NOVALUE = 0x300020206,
    _SET_ERRORID_SPLITSTRING_REALLOC = 0x300020207,
    _SET_ERRORID_SPLITSTRING_REALLOC2 = 0x300020208,
    _SET_ERRORID_SPLITSTRING_END = 0x300020209,
    _SET_ERRORID_SPLITSTRING_ENDSTRUCT = 0x30002020A,
    _SET_ERRORID_SPLITSTRING_MALLOCERROR = 0x30002020B,
    _SET_ERRORID_SPLITSTRING_CREATESUBSTRUCT = 0x30002020C,
    _SET_ERRORID_SPLITSTRING_ENDLIST = 0x30002020D,
    _SET_ERRORID_SPLITSTRING_CREATELIST = 0x30002020E,
    _SET_ERRORID_CREATELINEMES_MALLOC = 0x300030200,
    _SET_ERRORID_DESTROYCODEVALUE_KEY = 0x300040100,
    _SET_ERRORID_DESTROYCODESTRUCT_NULL = 0x300050100
};

#define _SET_ERRORMES_MALLOC "Unable to allocate memory (Size: %lu)"
#define _SET_ERRORMES_REALLOC "Unable to reallocate memory (Size: %lu)"
#define _SET_ERRORMES_EARLYSTOPCHAR "File ended unexpectedly inside char definition"
#define _SET_ERRORMES_NOSTOPCHAR "Expected a maximum of one character in char definition (%s)"
#define _SET_ERRORMES_VALUEKEY "Unknown value key (%u)"
#define _SET_ERRORMES_FIELDNULL "A field is NULL"
#define _SET_ERRORMES_SPACEINVALUE "Found unexpected space in value (%s)"
#define _SET_ERRORMES_TYPETWICE "Found two type definitions (%s)"
#define _SET_ERRORMES_VALUETWICE "Found two values (%s)"
#define _SET_ERRORMES_NOVALUE "Found no values (%s)"
#define _SET_ERRORMES_WRONGEND "File ended unexpectedly"
#define _SET_ERRORMES_ENDSTRUCT "Expected } to end struct definition (%s)"
#define _SET_ERRORMES_SUBSTRUCT "Unable to split substruct"
#define _SET_ERRORMES_ENDLIST "Expected ] to end list definition (%s)"
#define _SET_ERRORMES_SUBLIST "Unable to split list"

enum __SET_ValueType {
    SET_VALUETYPE_VALUE,
    SET_VALUETYPE_LIST,
    SET_VALUETYPE_STRUCT
};

typedef struct __SET_Setting SET_Setting;
typedef union __SET_Data SET_Data;
typedef enum __SET_Type SET_Type;
typedef enum __SET_ValueType SET_ValueType;
typedef struct __SET_CodeName SET_CodeName;
typedef struct __SET_CodeValue SET_CodeValue;
typedef union ___SET_CodeValue _SET_CodeValue;
typedef struct __SET_CodeStruct SET_CodeStruct;
typedef struct __SET_CodeList SET_CodeList;

// The information for one field
union __SET_Data {
    uint8_t u8;
    uint16_t u16;
    uint32_t u32;
    uint64_t u64;
    uint8_t *au8;
    uint16_t *au16;
    uint32_t *au32;
    uint64_t *au64;
    int8_t i8;
    int16_t i16;
    int32_t i32;
    int64_t i64;
    int8_t *ai8;
    int16_t *ai16;
    int32_t *ai32;
    int64_t *ai64;
    float f;
    double d;
    float *af;
    double *ad;
    char c;
    char *ac;
    char *s;
    char **as;
};

struct __SET_Field {
    SET_Data data;
    SET_Type type;
};

// Saves all information about a setting
struct __SET_Setting {
    char **key; // Strings of keys for the inputs
    SET_Data *data; // The data for the keys
};

struct __SET_CodeName {
    char *type; // The data type the field should store
    char *name; // The name of the field
};

struct __SET_CodeList {
    SET_CodeValue *list; // A list of values
    uint32_t count; // The number of elements
};

union ___SET_CodeValue {
    char *value; // The string containing the value
    SET_CodeList *list; // A list of strings with values
    SET_CodeStruct *sub; // A pointer to a substruct
};

struct __SET_CodeValue {
    SET_ValueType type; // The type of value to store
    _SET_CodeValue value; // The stored value
};

struct __SET_CodeStruct {
    SET_CodeName *names; // A list of the names of the fields
    SET_CodeValue *values; // A list of the values of the fields
    uint32_t count; // The number of fields
};

// List of special characters which should ignore spaces
uint32_t _SET_SpecialCharLength = 28;
char _SET_SpecialChar[] = {';', ':', '=', '+', '-', '*', '/', '%', '?', '^', '<', '>', '!', '~', '|', '&', '\\', '$', '#', '@', '.', ',', '(', ')', '[', ']', '{', '}'};

#define _SET_LINEPREMES "Line "
#define _SET_LINEPRELEN 5
#define _SET_LINEADDMES " -> "
#define _SET_LINEADDLEN 4

// Removes newlines, tabs and leading/trailing spaces
char *_SET_CleanString(char *String);

// Creates a line message
char *_SET_CreateLineMes(char *PreMes, uint32_t Line);

// Splits a value up if needed
bool *_SET_SplitValue(SET_CodeValue *Value, char *ErrorLine, uint32_t Line);

// Splits a list into int's components
SET_CodeList *_SET_SplitList(char *String, char *ErrorLine);

// Split string into field names and values
SET_CodeStruct *_SET_SplitString(char *String, char *ErrorLine);

// Initialize structs
void SET_InitStructCodeStruct(SET_CodeStruct *Struct);
void SET_InitStructCodeName(SET_CodeName *Struct);
void SET_InitStructCodeValue(SET_CodeValue *Struct);
void SET_InitStructCodeList(SET_CodeList *Struct);

// Destroy struct
void SET_DestroyCodeStruct(SET_CodeStruct *Struct);
void SET_DestroyCodeValue(SET_CodeValue *Struct);

char *_SET_CleanString(char *String)
{
    extern uint32_t _SET_SpecialCharLength;
    extern char _SET_SpecialChar[];

    size_t Size = strlen(String) + 1;
    char *NewString = (char *)malloc(sizeof(char) * Size);

    if (NewString == NULL)
    {
        _SET_AddErrorForeign(_SET_ERRORID_CLEANSTRING_MALLOC, strerror(errno), _SET_ERRORMES_MALLOC, sizeof(char) * Size);
        return NULL;
    }

    // Go through string
    bool InString = false;
    bool InChar = false;
    bool StringSpecial = false;
    bool Leading = true;
    char *DstString = NewString;
    bool LineComment = false;
    bool MultilineComment = false;
    char *SpecialCharList = NULL;
    char *EndSpecialCharList = _SET_SpecialChar + _SET_SpecialCharLength;

    for (char *Current = String; *Current != '\0'; ++Current)
    {
        // Skip if in line comment
        if (LineComment)
        {
            // Test if it should stop
            if (LineComment && *Current == '\n')
                LineComment = false;

            continue;
        }

        // Skip if in multiline comment
        if (MultilineComment)
        {
            // Test if it should stop
            if (*Current == '*' && *(Current + 1) == '/')
            {
                MultilineComment = false;
                ++Current;
            }

            continue;
        }

        // Skip if it is a newline or tab
        if (*Current == '\n' || *Current == '\t')
            continue;

        // Remove leading spaces
        if (Leading)
        {
            if (*Current == ' ')
                continue;

            else
                Leading = false;
        }

        // Do stuff outside of strings
        if (!InString && !InChar)
        {
            // Start comments
            if (*Current == '/')
            {
                if (*(Current + 1) == '/')
                {
                    LineComment = true;
                    ++Current;
                    continue;
                }

                if (*(Current + 1) == '*')
                {
                    MultilineComment = true;
                    ++Current;
                    continue;
                }
            }

            // Start a string
            if (*Current == '\"')
                InString = true;

            // Start char
            if (*Current == '\'')
                InChar = true;

            // Find space ignoring characters
            for (SpecialCharList = _SET_SpecialChar; SpecialCharList < EndSpecialCharList; ++SpecialCharList)
                if (*Current == *SpecialCharList)
                    break;

            if (SpecialCharList < EndSpecialCharList)
            {
                Leading = true;

                // Remove trailing spaces
                while (DstString > NewString && *(DstString - 1) == ' ')
                    DstString -= 1;
            }
        }

        // Do stuff in strings
        else if (!StringSpecial)
        {
            // Start a special character
            if (*Current == '\\')
                StringSpecial = true;

            // End the string
            if (*Current == '\"')
                InString = false;

            // End the char
            if (*Current == '\'')
                InChar = false;
        }

        // End special character
        else
            StringSpecial = false;

        // Add character to new string
        *DstString++ = *Current;
    }

    *DstString++ = '\0';

    // Shorten string
    Size = DstString - NewString;
    NewString = (char *)realloc(NewString, sizeof(char) * Size);

    if (NewString == NULL)
    {
        _SET_AddErrorForeign(_SET_ERRORID_CLEANSTRING_REALLOC, strerror(errno), _SET_ERRORMES_REALLOC, Size);
        return NULL;
    }

    return NewString;
}

char *_SET_CreateLineMes(char *PreMes, uint32_t Line)
{
    // Find length
    size_t Length = _SET_LINEPRELEN + strlen(PreMes) + 1;
    uint32_t CountLine = Line;

    while (CountLine != 0)
    {
        ++Length;
        CountLine /= 10;
    }

    // Allocate memory
    char *Mes = (char *)malloc(sizeof(char) * Length);

    if (Mes == NULL)
    {
        _SET_AddErrorForeign(_SET_ERRORID_CREATELINEMES_MALLOC, strerror(errno), _SET_ERRORMES_MALLOC, sizeof(char) * Length);
        return NULL;
    }

    // Write message
    sprintf(Mes, "%s" _SET_LINEPREMES "%u", PreMes, Line);

    return Mes;
}

SET_CodeStruct *_SET_SplitString(char *String, char *ErrorLine)
{
    // Get memory for the struct
    SET_CodeStruct *CodeStruct = (SET_CodeStruct *)malloc(sizeof(SET_CodeStruct));

    if (CodeStruct == NULL)
    {
        _SET_AddErrorForeign(_SET_ERRORID_SPLITSTRING_MALLOCSTRUCT, strerror(errno), _SET_ERRORMES_MALLOC, sizeof(SET_CodeStruct));
        return NULL;
    }

    SET_InitStructCodeStruct(CodeStruct);

    // Go through the string and split it
    char *TypeString = NULL;
    char *NameString = NULL;
    char *Current = String;
    int32_t ListCount = 0;
    int32_t StructCount = 0;
    bool InString = false;
    bool FoundType = false;
    bool AfterEqual = false;

    for (char *LastStart = String; *Current != '\0'; ++Current)
    {
        // Start or end a string
        if (*Current == '\"')
            InString = !InString;

        if (InString)
        {
            // Do special character
            if (*Current == '\\' && *(Current + 1) != '\0')
                ++Current;

            continue;
        }

        // Skip a char
        if (*Current == '\'')
        {
            uint32_t WithSpecial = 0;

            // With special character
            if (*(Current + 1) == '\\')
                WithSpecial = 1;

            // Test if it stops
            if (*(Current + WithSpecial + 1) == '\0')
            {
                SET_DestroyCodeStruct(CodeStruct);
                free(CodeStruct);
                _SET_SetError(_SET_ERRORID_SPLITSTRING_STOPCHAR, _SET_ERRORMES_EARLYSTOPCHAR);
                return NULL;
            }

            // Make sure it ends
            if (*(Current + WithSpecial + 2) != '\'')
            {
                char *LineMes = _SET_CreateLineMes(ErrorLine, CodeStruct->count + 1);
                SET_DestroyCodeStruct(CodeStruct);
                free(CodeStruct);
                _SET_SetError(_SET_ERRORID_SPLITSTRING_NOSTOPCHAR, _SET_ERRORMES_NOSTOPCHAR, LineMes);
                free(LineMes);
                return NULL;
            }

            // Skip till the end
            Current += 2 + WithSpecial;
            continue;
        }

        // Start or end list and structs
        if (*Current == '[')
            ++ListCount;

        else if (*Current == ']')
            --ListCount;

        else if (*Current == '{')
            ++StructCount;

        else if (*Current == '}')
            --StructCount;

        // Do the rest
        else if (ListCount == 0 && StructCount == 0)
        {
            // Look for type-name separator
            if (*Current == ' ')
            {
                // if there is an error
                if (AfterEqual)
                {
                    char *LineMes = _SET_CreateLineMes(ErrorLine, CodeStruct->count + 1);
                    SET_DestroyCodeStruct(CodeStruct);
                    free(CodeStruct);
                    _SET_SetError(_SET_ERRORID_SPLITSTRING_SPACEINVALUE, _SET_ERRORMES_SPACEINVALUE, LineMes);
                    free(LineMes);
                    return NULL;
                }

                if (FoundType)
                {
                    char *LineMes = _SET_CreateLineMes(ErrorLine, CodeStruct->count + 1);
                    SET_DestroyCodeStruct(CodeStruct);
                    free(CodeStruct);
                    _SET_SetError(_SET_ERRORID_SPLITSTRING_TYPETWICE, _SET_ERRORMES_TYPETWICE, LineMes);
                    free(LineMes);
                    return NULL;
                }

                // Add the type
                TypeString = LastStart;
                LastStart = Current + 1;
                *Current = '\0';
                FoundType = true;
                continue;
            }

            // Look for name-value separator
            if (*Current == '=')
            {
                // If there is an error
                if (AfterEqual)
                {
                    char *LineMes = _SET_CreateLineMes(ErrorLine, CodeStruct->count + 1);
                    SET_DestroyCodeStruct(CodeStruct);
                    free(CodeStruct);
                    _SET_SetError(_SET_ERRORID_SPLITSTRING_VALUETWICE, _SET_ERRORMES_VALUETWICE, LineMes);
                    free(LineMes);
                    return NULL;
                }

                // Add name
                NameString = LastStart;
                LastStart = Current + 1;
                *Current = '\0';
                AfterEqual = true;
                continue;
            }

            // Look for line stop
            if (*Current == ';')
            {
                // If there is an error
                if (!AfterEqual)
                {
                    char *LineMes = _SET_CreateLineMes(ErrorLine, CodeStruct->count + 1);
                    SET_DestroyCodeStruct(CodeStruct);
                    free(CodeStruct);
                    _SET_SetError(_SET_ERRORID_SPLITSTRING_NOVALUE, _SET_ERRORMES_NOVALUE, LineMes);
                    free(LineMes);
                    return NULL;
                }

                // Allocate memory for new line
                SET_CodeName *NewNames = (SET_CodeName *)realloc(CodeStruct->names, sizeof(SET_CodeName) * (CodeStruct->count + 1));

                if (NewNames == NULL)
                {
                    SET_DestroyCodeStruct(CodeStruct);
                    free(CodeStruct);
                    _SET_SetError(_SET_ERRORID_SPLITSTRING_REALLOC, _SET_ERRORMES_REALLOC, sizeof(SET_CodeName) * (CodeStruct->count + 1));
                    return NULL;
                }

                CodeStruct->names = NewNames;

                SET_CodeValue *NewValues = (SET_CodeValue *)realloc(CodeStruct->values, sizeof(SET_CodeValue) * (CodeStruct->count + 1));

                if (NewValues == NULL)
                {
                    SET_DestroyCodeStruct(CodeStruct);
                    free(CodeStruct);
                    _SET_SetError(_SET_ERRORID_SPLITSTRING_REALLOC2, _SET_ERRORMES_REALLOC, sizeof(SET_CodeValue) * (CodeStruct->count + 1));
                    return NULL;
                }

                CodeStruct->values = NewValues;

                // Add the new line
                NewValues[CodeStruct->count].type = SET_VALUETYPE_VALUE;
                NewValues[CodeStruct->count].value.value = LastStart;
                NewNames[CodeStruct->count].type = TypeString;
                NewNames[CodeStruct->count++].name = NameString;

                // Update the string
                LastStart = Current + 1;
                *Current = '\0';
                AfterEqual = false;
                FoundType = false;
                TypeString = NULL;
                NameString = NULL;
                continue;
            }
        }
    }

    // Make sure it ended with a line end
    if (*(Current - 1) != '\0' || FoundType || AfterEqual)
    {
        SET_DestroyCodeStruct(CodeStruct);
        free(CodeStruct);
        _SET_SetError(_SET_ERRORID_SPLITSTRING_END, _SET_ERRORMES_WRONGEND);
        return NULL;
    }

    // Create new error line
    size_t ErrorLength = strlen(ErrorLine) + _SET_LINEADDLEN + 1;
    char *NewErrorLine = (char *)malloc(sizeof(char) * ErrorLength);

    if (NewErrorLine == NULL)
    {
        SET_DestroyCodeStruct(CodeStruct);
        free(CodeStruct);
        _SET_SetError(_SET_ERRORID_SPLITSTRING_MALLOCERROR, _SET_ERRORMES_MALLOC, sizeof(SET_CodeValue) * ErrorLength);
        return NULL;
    }

    sprintf(NewErrorLine, "%s" _SET_LINEADDMES, ErrorLine);

    // Convert values into structs and lists
    for (SET_CodeValue *List = CodeStruct->values, *EndList = CodeStruct->values + CodeStruct->count; List < EndList; ++List)
    {
        
    }

    // Return the struct
    return CodeStruct;
}

bool *_SET_SplitValue(SET_CodeValue *Value, char *ErrorLine, uint32_t Line)
{
    // Check for a structs
    if (*Value->value.value == '{')
    {
        // Make sure it ends with }
        size_t Length = strlen(Value->value.value);

        if (Value->value.value[Length - 1] != '}')
        {
            char *LineMes = _SET_CreateLineMes(ErrorLine, Line);
            _SET_SetError(_SET_ERRORID_SPLITSTRING_ENDSTRUCT, _SET_ERRORMES_ENDSTRUCT, LineMes);
            free(LineMes);
            return false;
        }

        // Split the struct
        Value->value.value[Length - 1] = '\0';
        SET_CodeStruct *StructValue = _SET_SplitString(Value->value.value + 1, ErrorLine);

        if (StructValue == NULL)
        {
            _SET_AddError(_SET_ERRORID_SPLITSTRING_CREATESUBSTRUCT, _SET_ERRORMES_SUBSTRUCT);
            return false;
        }

        // Update the value
        Value->type = SET_VALUETYPE_STRUCT;
        Value->value.sub = StructValue;
    }

    // Check for a list
    else if (*Value->value.value == '[')
    {
        // Make sure it ends with ]
        size_t Length = strlen(Value->value.value);

        if (Value->value.value[Length - 1] != ']')
        {
            char *LineMes = _SET_CreateLineMes(ErrorLine, Line);
            _SET_SetError(_SET_ERRORID_SPLITSTRING_ENDLIST, _SET_ERRORMES_ENDLIST, LineMes);
            free(LineMes);
            return false;
        }

        // Split the list
        Value->value.value[Length - 1] = '\0';
        SET_CodeList *ListValues = _SET_SplitList(Value->value.value + 1, ErrorLine);

        if (ListValues == NULL)
        {
            _SET_AddError(_SET_ERRORID_SPLITSTRING_CREATELIST, _SET_ERRORMES_SUBLIST);
            return false;
        }

        // Update the value
        Value->type = SET_VALUETYPE_LIST;
        Value->value.list = ListValues;
    }

    return true;
}

void SET_InitStructCodeStruct(SET_CodeStruct *Struct)
{
    Struct->names = NULL;
    Struct->values = NULL;
    Struct->count = 0;
}

void SET_InitStructCodeName(SET_CodeName *Struct)
{
    Struct->name = NULL;
    Struct->type = NULL;
}

void SET_InitStructCodeValue(SET_CodeValue *Struct)
{
    Struct->type = SET_VALUETYPE_VALUE;
    Struct->value.value = NULL;
}

void SET_InitStructCodeList(SET_CodeList *Struct)
{
    Struct->list = NULL;
    Struct->count = 0;
}

void SET_DestroyCodeStruct(SET_CodeStruct *Struct)
{
    if (Struct->count == 0)
        return;

    if (Struct->names == NULL || Struct->values == NULL)
    {
        _SET_SetError(_SET_ERRORID_DESTROYCODESTRUCT_NULL, _SET_ERRORMES_FIELDNULL);
        return;
    }

    // Go through all of the elements
    for (SET_CodeStruct *List = Struct->values, *EndList = Struct->values + Struct->count; List < EndList; ++List)
        SET_DestroyCodeValue(List);

    free(Struct->names);
    free(Struct->values);
}

void SET_DestroyCodeValue(SET_CodeValue *Struct)
{
    switch (Struct->type)
    {
        case SET_VALUETYPE_VALUE:
            break;

        case SET_VALUETYPE_LIST:
            if (Struct->value.list != NULL)
            {
                if (Struct->value.list->list != NULL)
                {
                    for (SET_CodeValue *List = Struct->value.list->list, *EndList = Struct->value.list->list + Struct->value.list->count; List < EndList; ++List)
                        SET_DestroyCodeValue(List);

                    free(Struct->value.list->list);
                }

                free(Struct->value.list);
            }
            break;

        case SET_VALUETYPE_STRUCT:
            if (Struct->value.sub != NULL)
            {
                SET_DestroyCodeStruct(Struct->value.sub);
                free(Struct->value.sub);
            }
            break;
        
        default:
            _SET_SetError(_SET_ERRORID_DESTROYCODEVALUE_KEY, _SET_ERRORMES_VALUEKEY, Struct->type);
            break;
    }
}

#endif