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
    _SET_ERRORID_CLEANSTRING_REALLOC = 0x300010201
};

#define _SET_ERRORMES_MALLOC "Unable to allocate memory (Size: %lu)"
#define _SET_ERRORMES_REALLOC "Unable to reallocate memory (Size: %lu)"

typedef struct __SET_Setting SET_Setting;
typedef union __SET_Data SET_Data;
typedef enum __SET_Type SET_Type;

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

// List of special characters which should ignore spaces
uint32_t _SET_SpecialCharLength = 28;
char _SET_SpecialChar[] = {';', ':', '=', '+', '-', '*', '/', '%', '?', '^', '<', '>', '!', '~', '|', '&', '\\', '$', '#', '@', '.', ',', '(', ')', '[', ']', '{', '}'};

// Removes newlines, tabs and leading/trailing spaces
char *_SET_CleanString(char *String);

// Split string in lines, removing leading and trailing white space and any newlines
char **_SET_SplitString(char *String);

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
        if (!InString)
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

            // Remove leading spaces
            if (Leading)
            {
                if (*Current == ' ')
                    continue;

                else
                    Leading = false;
            }

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

char **_SET_SplitString(char *String)
{
    // Setup list
    char **List = NULL;
    size_t Size = 0;

    // If it is currently inside a string or inside a field
    bool InString = false;
    int32_t InField = 0;


}

#endif