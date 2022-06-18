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
    _SET_ERRORID_SPLITSTRING_MALLOCSTRUCT = 0x300020200
};

#define _SET_ERRORMES_MALLOC "Unable to allocate memory (Size: %lu)"
#define _SET_ERRORMES_REALLOC "Unable to reallocate memory (Size: %lu)"

typedef struct __SET_Setting SET_Setting;
typedef union __SET_Data SET_Data;
typedef enum __SET_Type SET_Type;
typedef struct __SET_CodeName SET_CodeName;
typedef union __SET_CodeValue SET_CodeValue;
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

union __SET_CodeValue {
    char *value; // The string containing the value
    SET_CodeList *list; // A pointer to a list
    SET_CodeStruct *sub; // A pointer to a substruct
};

struct __SET_CodeStruct {
    SET_CodeName *names; // A list of the names of the fields
    SET_CodeValue *values; // A list of the values of the fields
    uint32_t count; // The number of fields
};

// List of special characters which should ignore spaces
uint32_t _SET_SpecialCharLength = 28;
char _SET_SpecialChar[] = {';', ':', '=', '+', '-', '*', '/', '%', '?', '^', '<', '>', '!', '~', '|', '&', '\\', '$', '#', '@', '.', ',', '(', ')', '[', ']', '{', '}'};

// Removes newlines, tabs and leading/trailing spaces
char *_SET_CleanString(char *String);

// Split string into field names and values
SET_CodeStruct *_SET_SplitString(char *String);

// Initialize structs
void _SET_InitStructCodeStruct(SET_CodeStruct *Struct);
void _SET_InitStructCodeName(SET_CodeName *Struct);
void _SET_InitStructCodeValue(SET_CodeValue *Struct);
void _SET_InitStructCodeList(SET_CodeList *Struct);

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

SET_CodeStruct *_SET_SplitString(char *String)
{
    // Get memory for the struct
    SET_CodeStruct *CodeStruct = (SET_CodeStruct *)malloc(sizeof(SET_CodeStruct));

    if (CodeStruct == NULL)
    {
        _SET_AddErrorForeign(_SET_ERRORID_SPLITSTRING_MALLOCSTRUCT, strerror(errno), _SET_ERRORMES_MALLOC, sizeof(SET_CodeStruct));
        return NULL;
    }

    _SET_InitStructCodeStruct(CodeStruct);

    // Go through the string and split it
    int32_t ListCount = 0;
    int32_t StructCount = 0;
    bool InString = false;
    bool StringSpecial = false;
    bool FoundType = false;
    bool AfterEqual = 0;

    for (char *Current = String, *LastStart = String; *Current != '\0'; ++Current)
    {
        // Start a string
        if (*Current == '\"')
            InString = !InString;

        if (InString)
        {
            // Do special character
            if (*Current == '\\' && *(Current + 1) != '\0')
                ++Current;

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

        
    }
}

void _SET_InitStructCodeStruct(SET_CodeStruct *Struct)
{
    Struct->names = NULL;
    Struct->values = NULL;
    Struct->count = 0;
}

void _SET_InitStructCodeName(SET_CodeName *Struct)
{
    Struct->name = NULL;
    Struct->type = NULL;
}

void _SET_InitStructCodeValue(SET_CodeValue *Struct)
{
    Struct->value = NULL;
}

void _SET_InitStructCodeList(SET_CodeList *Struct)
{
    Struct->list = NULL;
    Struct->count = 0;
}

#endif