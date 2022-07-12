#ifndef SETTINGS_H_DEFINED
#define SETTINGS_H_DEFINED

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <Dictionary.h>

#define ERR_PREFIX SET
#include <Error.h>

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
    _SET_ERRORID_SPLITSTRING_MALLOCERROR = 0x30002020A,
    _SET_ERRORID_SPLITSTRING_SPLITVALUE = 0x30002020B,
    _SET_ERRORID_SPLITSTRING_CREATELINEERRROR1 = 0x30002020C,
    _SET_ERRORID_SPLITSTRING_CREATELINEERRROR2 = 0x30002020D,
    _SET_ERRORID_SPLITSTRING_CREATELINEERRROR3 = 0x30002020E,
    _SET_ERRORID_SPLITSTRING_CREATELINEERRROR4 = 0x30002020F,
    _SET_ERRORID_SPLITSTRING_CREATELINEERRROR5 = 0x300020210,
    _SET_ERRORID_SPLITSTRING_CREATELINEERRROR6 = 0x300020211,
    _SET_ERRORID_SPLITSTRING_ENDSTRING = 0x300020212,
    _SET_ERRORID_SPLITSTRING_CREATELINEERRROR7 = 0x300020213,
    _SET_ERRORID_CREATELINEMES_MALLOC = 0x300030200,
    _SET_ERRORID_DESTROYCODEVALUE_KEY = 0x300040100,
    _SET_ERRORID_DESTROYCODESTRUCT_NULL = 0x300050100,
    _SET_ERRORID_SPLITVALUE_ENDSTRUCT = 0x300070200,
    _SET_ERRORID_SPLITVALUE_CREATESUBSTRUCT = 0x300070201,
    _SET_ERRORID_SPLITVALUE_ENDLIST = 0x300070202,
    _SET_ERRORID_SPLITVALUE_CREATELIST = 0x300070203,
    _SET_ERRORID_SPLITVALUE_CREATELINEERRROR1 = 0x300070204,
    _SET_ERRORID_SPLITVALUE_CREATELINEERRROR2 = 0x300070205,
    _SET_ERRORID_SPLITVALUE_CREATELINEERRROR3 = 0x300070205,
    _SET_ERRORID_SPLITVALUE_CREATELINEERRROR4 = 0x300070206,
    _SET_ERRORID_SPLITVALUE_CREATELINEERRROR5 = 0x300070207,
    _SET_ERRORID_SPLITVALUE_NOVALUE = 0x300070208,
    _SET_ERRORID_SPLITLIST_MALLOCSTRUCT = 0x300080200,
    _SET_ERRORID_SPLITLIST_STOPCHAR = 0x300090200,
    _SET_ERRORID_SPLITLIST_NOSTOPCHAR = 0x300090201,
    _SET_ERRORID_SPLITLIST_CREATELINEERRROR1 = 0x300090202,
    _SET_ERRORID_SPLITLIST_MALLOCLIST = 0x300090203,
    _SET_ERRORID_SPLITLIST_REALLOCLIST = 0x300090204,
    _SET_ERRORID_SPLITLIST_SPLITVALUE = 0x300090205,
    _SET_ERRORID_SPLITLIST_CREATELINEERRROR2 = 0x300090206,
    _SET_ERRORID_SPLITLIST_CREATELINEERRROR3 = 0x300090207,
    _SET_ERRORID_GETPOSSIBLETYPE_NOVALUE = 0x3000A0100,
    _SET_ERRORID_GETPOSSIBLETYPE_CHAREND = 0x3000A0101,
    _SET_ERRORID_GETPOSSIBLETYPE_STRINGEND = 0x3000A0102,
    _SET_ERRORID_GETPOSSIBLETYPE_CHARLENGTH = 0x3000A0103,
    _SET_ERRORID_GETPOSSIBLETYPE_ILLIGALBIN = 0x3000A0104,
    _SET_ERRORID_GETPOSSIBLETYPE_ILLIGALHEX = 0x3000A0105,
    _SET_ERRORID_GETPOSSIBLETYPE_ILLIGALDOT = 0x3000A0106,
    _SET_ERRORID_GETPOSSIBLETYPE_ILLIGALNUM = 0x3000A0107,
    _SET_ERRORID_STRUCTTODICT_CREATEDICT = 0x3000B0200
};

#define _SET_ERRORMES_MALLOC "Unable to allocate memory (Size: %lu)"
#define _SET_ERRORMES_REALLOC "Unable to reallocate memory (Size: %lu)"
#define _SET_ERRORMES_EARLYSTOPCHAR "File ended unexpectedly inside char definition (%s)"
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
#define _SET_ERRORMES_SPLITVALUE "Unable to split value"
#define _SET_ERRORMES_CREATELINEERROR "Unable to create line error string"
#define _SET_ERRORMES_ENDSTRING "File ended unexpectedly inside a string definition (%s)"
#define _SET_ERRORMES_NOSTRING "Found no string"
#define _SET_ERRORMES_NOENDCHAR "Char value ended without \' (%s)"
#define _SET_ERRORMES_NOENDSTRING "String value ended without \" (%s)"
#define _SET_ERRORMES_ILLIGALBIN "Found illigal char in definition of binary number, must be 0 or 1 (%s: %c)"
#define _SET_ERRORMES_ILLIGALHEX "Found illigal char in definition of hexadecimal number, must be 0-9, a-f or A-F (%s: %c)"
#define _SET_ERRORMES_ILLIGALNUM "Found illigal char in definition of number, must be 0-9 (%s: %c)"
#define _SET_ERRORMES_ILLIGALDOT "Found two dots in definition of floating point number (%s)"
#define _SET_ERRORMES_CREATEDICT "Unable to create a dictionary"

enum __SET_ValueType {
    SET_VALUETYPE_VALUE,
    SET_VALUETYPE_LIST,
    SET_VALUETYPE_STRUCT
};

enum __SET_DataType {
    SET_DATATYPE_UINT8,
    SET_DATATYPE_UINT16,
    SET_DATATYPE_UINT32,
    SET_DATATYPE_UINT64,
    SET_DATATYPE_INT8,
    SET_DATATYPE_INT16,
    SET_DATATYPE_INT32,
    SET_DATATYPE_INT64,
    SET_DATATYPE_FLOAT,
    SET_DATATYPE_DOUBLE,
    SET_DATATYPE_CHAR,
    SET_DATATYPE_STR,
    SET_DATATYPE_STRUCT,
    SET_DATATYPE_LIST
};

enum __SET_DataTypeBase {
    SET_DATATYPEBASE_NONE = 0x00,
    SET_DATATYPEBASE_INT = 0x01,
    SET_DATATYPEBASE_UINT = 0x02,
    SET_DATATYPEBASE_FLOAT = 0x04,
    SET_DATATYPEBASE_CHAR = 0x08,
    SET_DATATYPEBASE_STRING = 0x10
};

typedef union ___SET_Data _SET_Data;
typedef struct __SET_Data SET_Data;
typedef struct __SET_DataList SET_DataList;
typedef enum __SET_DataType SET_DataType;
typedef enum __SET_ValueType SET_ValueType;
typedef enum __SET_DataTypeBase SET_DataTypeBase;
typedef struct __SET_CodeName SET_CodeName;
typedef struct __SET_CodeValue SET_CodeValue;
typedef union ___SET_CodeValue _SET_CodeValue;
typedef struct __SET_CodeStruct SET_CodeStruct;
typedef struct __SET_CodeList SET_CodeList;

union ___SET_Data {
    uint8_t u8;
    uint16_t u16;
    uint32_t u32;
    uint64_t u64;
    int8_t i8;
    int16_t i16;
    int32_t i32;
    int64_t i64;
    float f;
    double d;
    char ch;
    char *str;
    DIC_Dict *stct;
    SET_DataList list;
};

struct __SET_Data {
    _SET_Data data; // The data value
    SET_DataType type; // The type of the data
};

struct __SET_DataList {
    uint32_t count; // The number of items in the list
    _SET_Data *list; // The list of values
    SET_DataType type; // The type of all the values
};

struct __SET_CodeName {
    char *type; // The data type the field should store
    char *name; // The name of the field
    uint8_t pointer; // The pointer depth found in the type
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
#define _SET_ELEMENTPREMES "Element "
#define _SET_LINEADDMES " -> "

// Removes newlines, tabs and leading/trailing spaces
char *_SET_CleanString(char *String);

// Creates a line message
char *_SET_CreateLineMes(char *PreMes, char *Mes, uint32_t Line, char *EndMes);

// Splits a value up if needed
bool _SET_SplitValue(SET_CodeValue *Value, char *ErrorLine, uint32_t Line);

// Splits a list into int's components
SET_CodeList *_SET_SplitList(char *String, char *ErrorLine);

// Split string into field names and values
SET_CodeStruct *_SET_SplitString(char *String, char *ErrorLine);

// Finds all the possible types for the value
SET_DataTypeBase _SET_GetPossibleType(const char *Value);

// Converts a code struct into a dictionary
DIC_Dict *_SET_StructToDict(const SET_CodeStruct *Struct);

// Initialize structs
void SET_InitStructCodeStruct(SET_CodeStruct *Struct);
void SET_InitStructCodeName(SET_CodeName *Struct);
void SET_InitStructCodeValue(SET_CodeValue *Struct);
void SET_InitStructCodeList(SET_CodeList *Struct);

// Destroy struct
void SET_DestroyCodeStruct(SET_CodeStruct *Struct);
void SET_DestroyCodeValue(SET_CodeValue *Struct);
void SET_DestroyCodeList(SET_CodeList *Struct);

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

            // Remove leading spaces
            if (Leading)
            {
                if (*Current == ' ')
                    continue;

                else
                    Leading = false;
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

char *_SET_CreateLineMes(char *PreMes, char *Mes, uint32_t Line, char *EndMes)
{
    // Find length
    size_t Length = strlen(PreMes) + strlen(Mes) + strlen(EndMes) + 1;
    uint32_t CountLine = Line;

    while (CountLine != 0)
    {
        ++Length;
        CountLine /= 10;
    }

    // Allocate memory
    char *UseMes = (char *)malloc(sizeof(char) * Length);

    if (UseMes == NULL)
    {
        _SET_AddErrorForeign(_SET_ERRORID_CREATELINEMES_MALLOC, strerror(errno), _SET_ERRORMES_MALLOC, sizeof(char) * Length);
        return NULL;
    }

    // Write message
    sprintf(UseMes, "%s%s%u%s", PreMes, Mes, Line, EndMes);

    return UseMes;
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

    if (String[0] == '\0')
        return CodeStruct;

    // Go through the string and split it
    char *TypeString = NULL;
    char *NameString = NULL;
    char *Current = String;
    int32_t ListCount = 0;
    int32_t StructCount = 0;
    uint8_t PointerCount = 0;
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
                char *LineMes = _SET_CreateLineMes(ErrorLine, _SET_LINEPREMES, CodeStruct->count + 1, "");
                SET_DestroyCodeStruct(CodeStruct);
                free(CodeStruct);
                if (LineMes == NULL)
                    _SET_SetError(_SET_ERRORID_SPLITSTRING_CREATELINEERRROR7, _SET_ERRORMES_CREATELINEERROR);
                else
                {
                    _SET_SetError(_SET_ERRORID_SPLITSTRING_STOPCHAR, _SET_ERRORMES_EARLYSTOPCHAR, LineMes);
                    free(LineMes);
                }
                return NULL;
            }

            // Make sure it ends
            if (*(Current + WithSpecial + 2) != '\'')
            {
                char *LineMes = _SET_CreateLineMes(ErrorLine, _SET_LINEPREMES, CodeStruct->count + 1, "");
                SET_DestroyCodeStruct(CodeStruct);
                free(CodeStruct);
                if (LineMes == NULL)
                    _SET_SetError(_SET_ERRORID_SPLITSTRING_CREATELINEERRROR1, _SET_ERRORMES_CREATELINEERROR);
                else
                {
                    _SET_SetError(_SET_ERRORID_SPLITSTRING_NOSTOPCHAR, _SET_ERRORMES_NOSTOPCHAR, LineMes);
                    free(LineMes);
                }
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
            if (*Current == ' ' || (!AfterEqual && *Current == '*'))
            {
                // if there is an error
                if (AfterEqual)
                {
                    char *LineMes = _SET_CreateLineMes(ErrorLine, _SET_LINEPREMES, CodeStruct->count + 1, "");
                    SET_DestroyCodeStruct(CodeStruct);
                    free(CodeStruct);
                    if (LineMes == NULL)
                        _SET_SetError(_SET_ERRORID_SPLITSTRING_CREATELINEERRROR2, _SET_ERRORMES_CREATELINEERROR);
                    else
                    {
                        _SET_SetError(_SET_ERRORID_SPLITSTRING_SPACEINVALUE, _SET_ERRORMES_SPACEINVALUE, LineMes);
                        free(LineMes);
                    }
                    return NULL;
                }

                if (FoundType)
                {
                    char *LineMes = _SET_CreateLineMes(ErrorLine, _SET_LINEPREMES, CodeStruct->count + 1, "");
                    SET_DestroyCodeStruct(CodeStruct);
                    free(CodeStruct);
                    if (LineMes == NULL)
                        _SET_SetError(_SET_ERRORID_SPLITSTRING_CREATELINEERRROR3, _SET_ERRORMES_CREATELINEERROR);
                    else
                    {
                        _SET_SetError(_SET_ERRORID_SPLITSTRING_TYPETWICE, _SET_ERRORMES_TYPETWICE, LineMes);
                        free(LineMes);
                    }
                    return NULL;
                }

                // Count the pointer depth
                if (*Current == '*')
                {
                    PointerCount = 1;
                    *Current = '\0';

                    while (*(Current + 1) == '*')
                    {
                        ++PointerCount;
                        ++Current;
                    }
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
                    char *LineMes = _SET_CreateLineMes(ErrorLine, _SET_LINEPREMES, CodeStruct->count + 1, "");
                    SET_DestroyCodeStruct(CodeStruct);
                    free(CodeStruct);
                    if (LineMes == NULL)
                        _SET_SetError(_SET_ERRORID_SPLITSTRING_CREATELINEERRROR4, _SET_ERRORMES_CREATELINEERROR);
                    else
                    {
                        _SET_SetError(_SET_ERRORID_SPLITSTRING_VALUETWICE, _SET_ERRORMES_VALUETWICE, LineMes);
                        free(LineMes);
                    }
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
                    char *LineMes = _SET_CreateLineMes(ErrorLine, _SET_LINEPREMES, CodeStruct->count + 1, "");
                    SET_DestroyCodeStruct(CodeStruct);
                    free(CodeStruct);
                    if (LineMes == NULL)
                        _SET_SetError(_SET_ERRORID_SPLITSTRING_CREATELINEERRROR5, _SET_ERRORMES_CREATELINEERROR);
                    else
                    {
                        _SET_SetError(_SET_ERRORID_SPLITSTRING_NOVALUE, _SET_ERRORMES_NOVALUE, LineMes);
                        free(LineMes);
                    }
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
                NewNames[CodeStruct->count].pointer = PointerCount;
                NewNames[CodeStruct->count++].name = NameString;

                // Update the string
                LastStart = Current + 1;
                *Current = '\0';
                AfterEqual = false;
                FoundType = false;
                TypeString = NULL;
                NameString = NULL;
                PointerCount = 0;
                continue;
            }
        }
    }

    // Make sure it is not inside of a string
    if (InString)
    {
        char *LineMes = _SET_CreateLineMes(ErrorLine, _SET_LINEPREMES, CodeStruct->count + 1, "");
        SET_DestroyCodeStruct(CodeStruct);
        free(CodeStruct);
        if (LineMes == NULL)
            _SET_SetError(_SET_ERRORID_SPLITSTRING_CREATELINEERRROR6, _SET_ERRORMES_CREATELINEERROR);
        else
        {
            _SET_SetError(_SET_ERRORID_SPLITSTRING_ENDSTRING, _SET_ERRORMES_ENDSTRING, LineMes);
            free(LineMes);
        }
        return NULL;
    }

    // Make sure it ended with a line end
    if (*(Current - 1) != '\0' || FoundType || AfterEqual)
    {
        SET_DestroyCodeStruct(CodeStruct);
        free(CodeStruct);
        _SET_SetError(_SET_ERRORID_SPLITSTRING_END, _SET_ERRORMES_WRONGEND);
        return NULL;
    }

    // Convert values into structs and lists
    for (SET_CodeValue *List = CodeStruct->values, *EndList = CodeStruct->values + CodeStruct->count; List < EndList; ++List)
        // Split the value
        if (!_SET_SplitValue(List, ErrorLine, (uint32_t)(List - CodeStruct->values)))
        {
            SET_DestroyCodeStruct(CodeStruct);
            free(CodeStruct);
            _SET_AddError(_SET_ERRORID_SPLITSTRING_SPLITVALUE, _SET_ERRORMES_SPLITVALUE);
            return NULL;
        }

    // Return the struct
    return CodeStruct;
}

bool _SET_SplitValue(SET_CodeValue *Value, char *ErrorLine, uint32_t Line)
{
    if (Value->value.value[0] == '\0')
    {
        char *LineMes = _SET_CreateLineMes(ErrorLine, _SET_LINEPREMES, Line, "");
        if (LineMes == NULL)
            _SET_SetError(_SET_ERRORID_SPLITVALUE_CREATELINEERRROR5, _SET_ERRORMES_CREATELINEERROR);
        else
        {
            _SET_SetError(_SET_ERRORID_SPLITVALUE_NOVALUE, _SET_ERRORMES_NOVALUE, LineMes);
            free(LineMes);
        }
        return false;
    }

    // Check for a structs
    if (*Value->value.value == '{')
    {
        // Make sure it ends with }
        size_t Length = strlen(Value->value.value);

        if (Value->value.value[Length - 1] != '}')
        {
            char *LineMes = _SET_CreateLineMes(ErrorLine, _SET_LINEPREMES, Line, "");
            if (LineMes == NULL)
                _SET_SetError(_SET_ERRORID_SPLITVALUE_CREATELINEERRROR3, _SET_ERRORMES_CREATELINEERROR);
            else
            {
                _SET_SetError(_SET_ERRORID_SPLITVALUE_ENDSTRUCT, _SET_ERRORMES_ENDSTRUCT, LineMes);
                free(LineMes);
            }
            return false;
        }

        // Create new line message
        char *NewLineMes = _SET_CreateLineMes(ErrorLine, _SET_LINEPREMES, Line, _SET_LINEADDMES);

        if (NewLineMes == NULL)
        {
            _SET_AddError(_SET_ERRORID_SPLITVALUE_CREATELINEERRROR1, _SET_ERRORMES_CREATELINEERROR);
            return false;
        }

        // Split the struct
        Value->value.value[Length - 1] = '\0';
        SET_CodeStruct *StructValue = _SET_SplitString(Value->value.value + 1, NewLineMes);

        if (StructValue == NULL)
        {
            _SET_AddError(_SET_ERRORID_SPLITVALUE_CREATESUBSTRUCT, _SET_ERRORMES_SUBSTRUCT);
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
            char *LineMes = _SET_CreateLineMes(ErrorLine, _SET_LINEPREMES, Line, "");
            if (LineMes == NULL)
                _SET_SetError(_SET_ERRORID_SPLITVALUE_CREATELINEERRROR4, _SET_ERRORMES_CREATELINEERROR);
            else
            {
                _SET_SetError(_SET_ERRORID_SPLITVALUE_ENDLIST, _SET_ERRORMES_ENDLIST, LineMes);
                free(LineMes);
            }
            return false;
        }

        // Create new line message
        char *NewLineMes = _SET_CreateLineMes(ErrorLine, _SET_LINEPREMES, Line, _SET_LINEADDMES);

        if (NewLineMes == NULL)
        {
            _SET_AddError(_SET_ERRORID_SPLITVALUE_CREATELINEERRROR2, _SET_ERRORMES_CREATELINEERROR);
            return false;
        }

        // Split the list
        Value->value.value[Length - 1] = '\0';
        SET_CodeList *ListValues = _SET_SplitList(Value->value.value + 1, NewLineMes);

        if (ListValues == NULL)
        {
            _SET_AddError(_SET_ERRORID_SPLITVALUE_CREATELIST, _SET_ERRORMES_SUBLIST);
            return false;
        }

        // Update the value
        Value->type = SET_VALUETYPE_LIST;
        Value->value.list = ListValues;
    }

    return true;
}

SET_CodeList *_SET_SplitList(char *String, char *ErrorLine)
{
    // Get memory for the struct
    SET_CodeList *CodeList = (SET_CodeList *)malloc(sizeof(SET_CodeList));

    if (CodeList == NULL)
    {
        _SET_AddErrorForeign(_SET_ERRORID_SPLITLIST_MALLOCSTRUCT, strerror(errno), _SET_ERRORMES_MALLOC, sizeof(SET_CodeList));
        return NULL;
    }

    SET_InitStructCodeList(CodeList);

    // Get first memory for list
    CodeList->list = (SET_CodeValue *)malloc(sizeof(SET_CodeValue));

    if (CodeList->list == NULL)
    {
        free(CodeList);
        _SET_AddErrorForeign(_SET_ERRORID_SPLITLIST_MALLOCLIST, strerror(errno), _SET_ERRORMES_MALLOC, sizeof(SET_CodeValue));
        return NULL;
    }

    if (String[0] == '\0')
        return CodeList;

    char *LastStart = String;
    int32_t ListCount = 0;
    int32_t StructCount = 0;
    bool InString = false;

    for (char *Current = String; *Current != '\0'; ++Current)
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
                char *LineMes = _SET_CreateLineMes(ErrorLine, _SET_ELEMENTPREMES, CodeList->count + 1, "");
                SET_DestroyCodeList(CodeList);
                free(CodeList);
                if (LineMes == NULL)
                    _SET_SetError(_SET_ERRORID_SPLITLIST_CREATELINEERRROR2, _SET_ERRORMES_CREATELINEERROR);
                else
                {
                    _SET_SetError(_SET_ERRORID_SPLITLIST_STOPCHAR, _SET_ERRORMES_EARLYSTOPCHAR);
                    free(LineMes);
                }
                return NULL;
            }

            // Make sure it ends
            if (*(Current + WithSpecial + 2) != '\'')
            {
                char *LineMes = _SET_CreateLineMes(ErrorLine, _SET_ELEMENTPREMES, CodeList->count + 1, "");
                SET_DestroyCodeList(CodeList);
                free(CodeList);
                if (LineMes == NULL)
                    _SET_SetError(_SET_ERRORID_SPLITLIST_CREATELINEERRROR1, _SET_ERRORMES_CREATELINEERROR);
                else
                {
                    _SET_SetError(_SET_ERRORID_SPLITLIST_NOSTOPCHAR, _SET_ERRORMES_NOSTOPCHAR, LineMes);
                    free(LineMes);
                }
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

        // End element
        else if (ListCount == 0 && StructCount == 0 && *Current == ',')
        {
            // Get memory for the list
            SET_CodeValue *NewList = (SET_CodeValue *)realloc(CodeList->list, sizeof(SET_CodeValue) * (CodeList->count + 2));

            if (NewList == NULL)
            {
                SET_DestroyCodeList(CodeList);
                free(CodeList);
                _SET_SetError(_SET_ERRORID_SPLITLIST_REALLOCLIST, _SET_ERRORMES_REALLOC, sizeof(SET_CodeValue) * (CodeList->count + 2));
                return NULL;
            }

            CodeList->list = NewList;
            NewList[CodeList->count].type = SET_VALUETYPE_VALUE;
            NewList[CodeList->count++].value.value = LastStart;

            *Current = '\0';
            LastStart = Current + 1;
            continue;
        }
    }

    // Make sure it is not inside of a string
    if (InString)
    {
        char *LineMes = _SET_CreateLineMes(ErrorLine, _SET_ELEMENTPREMES, CodeList->count + 1, "");
        SET_DestroyCodeList(CodeList);
        free(CodeList);
        if (LineMes == NULL)
            _SET_SetError(_SET_ERRORID_SPLITLIST_CREATELINEERRROR3, _SET_ERRORMES_CREATELINEERROR);
        else
        {
            _SET_SetError(_SET_ERRORID_SPLITSTRING_ENDSTRING, _SET_ERRORMES_ENDSTRING, LineMes);
            free(LineMes);
        }
        return NULL;
    }

    // Add the last element
    CodeList->list[CodeList->count].type = SET_VALUETYPE_VALUE;
    CodeList->list[CodeList->count++].value.value = LastStart;

    // Convert values into structs and lists
    for (SET_CodeValue *List = CodeList->list, *EndList = CodeList->list + CodeList->count; List < EndList; ++List)
        // Split the value
        if (!_SET_SplitValue(List, ErrorLine, (uint32_t)(List - CodeList->list)))
        {
            SET_DestroyCodeList(CodeList);
            free(CodeList);
            _SET_AddError(_SET_ERRORID_SPLITLIST_SPLITVALUE, _SET_ERRORMES_SPLITVALUE);
            return NULL;
        }

    // Return the struct
    return CodeList;
}

SET_DataTypeBase _SET_GetPossibleType(const char *Value)
{
    // Make sure there is a string
    if (*Value == '\0')
    {
        _SET_SetError(_SET_ERRORID_GETPOSSIBLETYPE_NOVALUE, _SET_ERRORMES_NOSTRING);
        return SET_DATATYPEBASE_NONE;
    }

    const char *Current = Value;
    SET_DataTypeBase Type = SET_DATATYPEBASE_NONE;
    bool Hex = false;
    bool Bin = false;
    bool Dot = false;

    // Do the start
    switch (*Current)
    {
        // Char
        case ('\''):
            Type = SET_DATATYPEBASE_CHAR;
            break;

        // String
        case ('\"'):
            Type = SET_DATATYPEBASE_STRING;
            break;

        // Signed
        case ('-'):
            Type = SET_DATATYPEBASE_INT | SET_DATATYPEBASE_FLOAT;
            break;

        // Hex or Bin
        case ('0'):
            ++Current;
            switch (*Current)
            {
                // Hex
                case ('x'):
                    Type = SET_DATATYPEBASE_UINT;
                    Hex = true;
                    break;

                // Bin
                case ('b'):
                    Type = SET_DATATYPEBASE_UINT;
                    Bin = true;
                    break;
                
                default:
                    Type = SET_DATATYPEBASE_INT | SET_DATATYPEBASE_UINT | SET_DATATYPEBASE_FLOAT;
                    Current -= 2;
                    break;
            }
            break;
        
        default:
            Type = SET_DATATYPEBASE_INT | SET_DATATYPEBASE_UINT | SET_DATATYPEBASE_FLOAT;
            --Current;
            break;
    }

    ++Current;

    // Go through entire string
    if (Type != SET_DATATYPEBASE_CHAR && Type != SET_DATATYPEBASE_STRING)
        for (; *Current != '\0'; ++Current)
        {
            // Check binary
            if (Bin)
            {
                if (*Current != '0' || *Current != '1')
                {
                    _SET_SetError(_SET_ERRORID_GETPOSSIBLETYPE_ILLIGALBIN, _SET_ERRORMES_ILLIGALBIN, Value, *Current);
                    return SET_DATATYPEBASE_NONE;
                }
            }

            else if (Hex)
            {
                if (!((*Current >= '0' && *Current <= '9') || (*Current >= 'a' && *Current <= 'f') || (*Current >= 'A' && *Current <= 'F')))
                {
                    _SET_SetError(_SET_ERRORID_GETPOSSIBLETYPE_ILLIGALHEX, _SET_ERRORMES_ILLIGALHEX, Value, *Current);
                    return SET_DATATYPEBASE_NONE;
                }
            }

            else
            {
                if (*Current == '.' && Type & SET_DATATYPEBASE_FLOAT)
                {
                    if (!Dot)
                    {
                        Dot = true;
                        Type = SET_DATATYPEBASE_FLOAT;
                    }

                    else
                    {
                        _SET_SetError(_SET_ERRORID_GETPOSSIBLETYPE_ILLIGALDOT, _SET_ERRORMES_ILLIGALDOT, Value);
                        return SET_DATATYPEBASE_NONE;
                    }
                }

                else if (!(*Current >= '0' && *Current <= '9'))
                {
                    _SET_SetError(_SET_ERRORID_GETPOSSIBLETYPE_ILLIGALNUM, _SET_ERRORMES_ILLIGALNUM, Value, *Current);
                    return SET_DATATYPEBASE_NONE;
                }
            }
        }

    // Do the end
    else
    {
        Current += strlen(Current) - 1;

        if (Type == SET_DATATYPEBASE_CHAR)
        {
            // Make sure a char ends
            if (*Current != '\'')
            {
                _SET_SetError(_SET_ERRORID_GETPOSSIBLETYPE_CHAREND, _SET_ERRORMES_NOENDCHAR, Value);
                return SET_DATATYPEBASE_NONE;
            }

            // Make sure it is not too long or short
            uint32_t CharLength = 3;

            if (*(Value + 1) == '\\')
                ++CharLength;

            if (strlen(Value) != CharLength)
            {
                _SET_SetError(_SET_ERRORID_GETPOSSIBLETYPE_CHARLENGTH, _SET_ERRORMES_NOSTOPCHAR, Value);
                return SET_DATATYPEBASE_NONE;
            }
        }

        // Make sure a tring ends
        else if (Type == SET_DATATYPEBASE_STRING)
        {
            // Check if it really ends
            uint32_t SpecialCount = 0;

            for (char *Current2 = Current - 1; *Current2 == '\\'; --Current2)
                ++SpecialCount;

            // Check that it ends
            if (SpecialCount % 2 == 1 || *Current != '\"')
            {
                _SET_SetError(_SET_ERRORID_GETPOSSIBLETYPE_STRINGEND, _SET_ERRORMES_NOENDSTRING, Value);
                return SET_DATATYPEBASE_NONE;
            }
        }
    } 

    return Type;
}

DIC_Dict *_SET_StructToDict(const SET_CodeStruct *Struct)
{
    // Create a dictionary
    DIC_Dict *Dict = DIC_CreateDict(Struct->count);

    if (Dict == NULL)
    {
        _SET_AddErrorForeign(_SET_ERRORID_STRUCTTODICT_CREATEDICT, DIC_GetError(), _SET_ERRORMES_CREATEDICT);
        return NULL;
    }

    // Start filling it up
    SET_CodeName *Names = Struct->names;
    SET_CodeName *EndNames = Names + Struct->count;
    SET_CodeValue *Values = Struct->values;

    for (; Names < EndNames; ++Names, ++Values)
    {

    }

    return Dict;
}

void SET_InitStructData(SET_Data *Struct)
{
    Struct->data.stct = NULL;
    Struct->type = SET_DATATYPE_STRUCT;
}

void SET_InitStructDataList(SET_DataList *Struct)
{
    Struct->count = 0;
    Struct->list = NULL;
    Struct->type = SET_DATATYPE_STRUCT;
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
    Struct->pointer = 0;
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

void SET_DestroyStructData(SET_Data *Struct)
{
    switch ()
    {
    case /* constant-expression */:
        /* code */
        break;
    
    default:
        break;
    }
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
    for (SET_CodeValue *List = Struct->values, *EndList = Struct->values + Struct->count; List < EndList; ++List)
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
            SET_DestroyCodeList(Struct->value.list);
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

void SET_DestroyCodeList(SET_CodeList *Struct)
{
    if (Struct->list != NULL)
    {
        for (SET_CodeValue *List = Struct->list, *EndList = Struct->list + Struct->count; List < EndList; ++List)
            SET_DestroyCodeValue(List);

        free(Struct->list);
    }
}

#endif