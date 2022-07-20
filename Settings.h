#ifndef SETTINGS_H_DEFINED
#define SETTINGS_H_DEFINED

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <Dictionary.h>
#include <math.h>
#include <Files.h>

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
    _SET_ERRORID_SPLITSTRING_ENDSTRING = 0x30002020C,
    _SET_ERRORID_SPLITSTRING_MALLOC = 0x30002020D,
    _SET_ERRORID_SPLITSTRING_MALLOC2 = 0x30002020E,
    _SET_ERRORID_CREATELINEMES_MALLOC = 0x300030200,
    _SET_ERRORID_DESTROYCODEVALUE_KEY = 0x300040100,
    _SET_ERRORID_CONVERTVALUE_MALLOC = 0x300050200,
    _SET_ERRORID_CONVERTVALUE_LIST = 0x300050201,
    _SET_ERRORID_CONVERTVALUE_STRUCT = 0x300050202,
    _SET_ERRORID_CONVERTVALUE_LISTMATCH = 0x300050203,
    _SET_ERRORID_CONVERTVALUE_TYPEMATCH = 0x300050204,
    _SET_ERRORID_CONVERTVALUE_LISTMATCH2 = 0x300050205,
    _SET_ERRORID_CONVERTVALUE_NUMBERMATCH = 0x300050206,
    _SET_ERRORID_CONVERTVALUE_TYPE = 0x300050207,
    _SET_ERRORID_CONVERTVALUE_NOVALUE = 0x300050208,
    _SET_ERRORID_CONVERTVALUE_NOPOSSIBLEVALUE = 0x300050209,
    _SET_ERRORID_CONVERTVALUE_CONVERT = 0x30005020A,
    _SET_ERRORID_READTYPE_DICT = 0x300060200,
    _SET_ERRORID_READTYPE_WRONGTYPE = 0x300060201,
    _SET_ERRORID_READTYPE_RETRIEVE = 0x300060202,
    _SET_ERRORID_SPLITVALUE_ENDSTRUCT = 0x300070200,
    _SET_ERRORID_SPLITVALUE_CREATESUBSTRUCT = 0x300070201,
    _SET_ERRORID_SPLITVALUE_ENDLIST = 0x300070202,
    _SET_ERRORID_SPLITVALUE_CREATELIST = 0x300070203,
    _SET_ERRORID_SPLITVALUE_NOVALUE = 0x300070204,
    _SET_ERRORID_SPLITLIST_MALLOCSTRUCT = 0x300080200,
    _SET_ERRORID_SPLITLIST_STOPCHAR = 0x300090200,
    _SET_ERRORID_SPLITLIST_NOSTOPCHAR = 0x300090201,
    _SET_ERRORID_SPLITLIST_MALLOCLIST = 0x300090202,
    _SET_ERRORID_SPLITLIST_REALLOCLIST = 0x300090203,
    _SET_ERRORID_SPLITLIST_SPLITVALUE = 0x300090204,
    _SET_ERRORID_SPLITLIST_MALLOCLIST2 = 0x300090205,
    _SET_ERRORID_SPLITLIST_REALLOCLIST2 = 0x300090206,
    _SET_ERRORID_GETPOSSIBLETYPE_NOVALUE = 0x3000A0100,
    _SET_ERRORID_GETPOSSIBLETYPE_CHAREND = 0x3000A0101,
    _SET_ERRORID_GETPOSSIBLETYPE_STRINGEND = 0x3000A0102,
    _SET_ERRORID_GETPOSSIBLETYPE_CHARLENGTH = 0x3000A0103,
    _SET_ERRORID_GETPOSSIBLETYPE_ILLIGALBIN = 0x3000A0104,
    _SET_ERRORID_GETPOSSIBLETYPE_ILLIGALHEX = 0x3000A0105,
    _SET_ERRORID_GETPOSSIBLETYPE_ILLIGALDOT = 0x3000A0106,
    _SET_ERRORID_GETPOSSIBLETYPE_ILLIGALNUM = 0x3000A0107,
    _SET_ERRORID_GETPOSSIBLETYPE_ILLIGALEXP = 0x3000A0108,
    _SET_ERRORID_GETPOSSIBLETYPE_ILLIGALDOT2 = 0x3000A0109,
    _SET_ERRORID_CONVERTSTRUCT_CREATEDICT = 0x3000B0200,
    _SET_ERRORID_CONVERTSTRUCT_TYPE = 0x3000B0201,
    _SET_ERRORID_CONVERTSTRUCT_VALUE = 0x3000B0202,
    _SET_ERRORID_CONVERTSTRUCT_ADDITEM = 0x3000B0203,
    _SET_ERRORID_CONVERTSTRUCT_DUBLICATE = 0x3000B0204,
    _SET_ERRORID_CONVERTLIST_MALLOC = 0x3000C0200,
    _SET_ERRORID_CONVERTLIST_MALLOCLIST = 0x300C0201,
    _SET_ERRORID_CONVERTLIST_VALUE = 0x3000C0202,
    _SET_ERRORID_CONVERTLIST_TYPE = 0x3000C0203,
    _SET_ERRORID_CONVERTLIST_LISTELEMENT = 0x3000C0204,
    _SET_ERRORID_CONVERTLIST_NOELEMENTS = 0x3000C0205,
    _SET_ERRORID_CONVERTLIST_LISTELEMENT2 = 0x3000C0206,
    _SET_ERRORID_CONVERTLIST_TYPEELEMENT = 0x3000C0207,
    _SET_ERRORID_CONVERTLIST_NUMBERELEMENT = 0x3000C0208,
    _SET_ERRORID_CONVERTTYPE_NOSTRUCT = 0x3000D0200,
    _SET_ERRORID_CONVERTTYPE_TYPEMATCH = 0x3000D0201,
    _SET_ERRORID_CONVERTTYPE_TYPEMATCH2 = 0x3000D0202,
    _SET_ERRORID_CONVERTTYPE_NUMBERMATCH = 0x3000D0203,
    _SET_ERRORID_CONVERTTYPE_FLOATMATCH = 0x3000D0204,
    _SET_ERRORID_CONVERTTYPE_SINTMATCH = 0x3000D0205,
    _SET_ERRORID_CONVERTTYPE_SINTMATCH2 = 0x3000D0206,
    _SET_ERRORID_CONVERTTYPE_INTMATCH = 0x3000D0207,
    _SET_ERRORID_CONVERTUINT_CONVERT = 0x3000E0200,
    _SET_ERRORID_READUINT_HIGH = 0x3000F0200,
    _SET_ERRORID_READUINT_HIGH2 = 0x3000F0201,
    _SET_ERRORID_READUINT_NOSTRING = 0x3000F0202,
    _SET_ERRORID_READHEX_HIGH = 0x300100200,
    _SET_ERRORID_READHEX_NOSTRING = 0x300100201,
    _SET_ERRORID_READBIN_HIGH = 0x300110200,
    _SET_ERRORID_READBIN_NOSTRING = 0x300110201,
    _SET_ERRORID_CONVERTSINT_READ = 0x300120200,
    _SET_ERRORID_CONVERTFLOAT_EXP = 0x300130200,
    _SET_ERRORID_CONVERTFLOAT_FINITE = 0x300130201,
    _SET_ERRORID_READSINT_UINT = 0x300140200,
    _SET_ERRORID_READSINT_HIGH = 0x300140201,
    _SET_ERRORID_CONVERTSPECIALCHAR_UNKNOWN = 0x300150200,
    _SET_ERRORID_CONVERTCHAR_SPECIAL = 0x300160200,
    _SET_ERRORID_CONVERTSTRING_MALLOC = 0x300170200,
    _SET_ERRORID_CONVERTSTRING_SPECIAL = 0x300170201,
    _SET_ERRORID_LOADSETTINGS_LOAD = 0x300180200,
    _SET_ERRORID_LOADSETTINGS_CLEAN = 0x300180201,
    _SET_ERRORID_LOADSETTINGS_SPLIT = 0x300180202,
    _SET_ERRORID_LOADSETTINGS_CREATEDICT = 0x300180203,
    _SET_ERRORID_LOADSETTINGS_LOADDICT = 0x300180204,
    _SET_ERRORID_LOADSETTINGS_CONVERT = 0x300180205,
    _SET_ERRORID_TRANSLATE_FILL = 0x300190200,
    _SET_ERRORID_TRANSLATE_GETITEM = 0x300190201,
    _SET_ERRORID_TRANSLATE_EMPTY = 0x300190202,
    _SET_ERRORID_TRANSLATE_TRANSLATE = 0x300190203,
    _SET_ERRORID_REVERSETRANSLATION_GETITEM = 0x3001A0100,
    _SET_ERRORID_TRANSLATELIST_CONVERTLIST = 0x3001B0200,
    _SET_ERRORID_TRANSLATELIST_MALLOC1 = 0x3001B0201,
    _SET_ERRORID_TRANSLATELIST_UNKNOWNTYPE = 0x3001B0202,
    _SET_ERRORID_TRANSLATEELEMENT_LISTMATCH = 0x3001C0200,
    _SET_ERRORID_TRANSLATEELEMENT_LIST = 0x3001C0201,
    _SET_ERRORID_TRANSLATEELEMENT_STRUCTMATCH = 0x3001C0202,
    _SET_ERRORID_TRANSLATEELEMENT_NOSTRUCT = 0x3001C0203,
    _SET_ERRORID_TRANSLATEELEMENT_CONVERTSTRUCT = 0x3001C0204,
    _SET_ERRORID_TRANSLATEELEMENT_STRINGMATCH = 0x3001C0205,
    _SET_ERRORID_TRANSLATEELEMENT_STRINGMALLOC = 0x3001C0206,
    _SET_ERRORID_TRANSLATEELEMENT_CONVERTVALUE = 0x3001C0207,
    _SET_ERRORID_TRANSLATEELEMENT_UNKNOWNTYPE = 0x3001C0208
};

#define _SET_ERRORMES_MALLOC "Unable to allocate memory (Size: %lu)"
#define _SET_ERRORMES_REALLOC "Unable to reallocate memory (Size: %lu)"
#define _SET_ERRORMES_EARLYSTOPCHAR "File ended unexpectedly inside char definition (%s: %u)"
#define _SET_ERRORMES_NOSTOPCHAR "Expected a maximum of one character in char definition (%s: %u)"
#define _SET_ERRORMES_VALUEKEY "Unknown value key (%u)"
#define _SET_ERRORMES_FIELDNULL "A field is NULL"
#define _SET_ERRORMES_SPACEINVALUE "Found unexpected space in value (%s: %u)"
#define _SET_ERRORMES_TYPETWICE "Found two type definitions (%s: %u)"
#define _SET_ERRORMES_VALUETWICE "Found two values (%s: %u)"
#define _SET_ERRORMES_NOVALUE "Found no values (%s: %u)"
#define _SET_ERRORMES_NOVALUE2 "Found no values"
#define _SET_ERRORMES_WRONGEND "File ended unexpectedly"
#define _SET_ERRORMES_ENDSTRUCT "Expected } to end struct definition"
#define _SET_ERRORMES_SUBSTRUCT "Unable to split substruct"
#define _SET_ERRORMES_ENDLIST "Expected ] to end list definition"
#define _SET_ERRORMES_SUBLIST "Unable to split list"
#define _SET_ERRORMES_SPLITVALUE "Unable to split value (%s: %u)"
#define _SET_ERRORMES_ENDSTRING "File ended unexpectedly inside a string definition (%s: %u)"
#define _SET_ERRORMES_NOSTRING "Found no string"
#define _SET_ERRORMES_NOENDCHAR "Char value ended without \' (%s)"
#define _SET_ERRORMES_NOENDSTRING "String value ended without \" (%s)"
#define _SET_ERRORMES_ILLIGALBIN "Found illigal char in definition of binary number, must be 0 or 1 (%s: %c)"
#define _SET_ERRORMES_ILLIGALHEX "Found illigal char in definition of hexadecimal number, must be 0-9, a-f or A-F (%s: %c)"
#define _SET_ERRORMES_ILLIGALNUM "Found illigal char in definition of number, must be 0-9 (%s: %c)"
#define _SET_ERRORMES_ILLIGALDOT "Found two dots in definition of floating point number (%s)"
#define _SET_ERRORMES_ILLIGALDOT2 "Dound a dot in definition of the potentiation of a floating point number (%s)"
#define _SET_ERRORMES_ILLIGALEXP "Found to potentiations in definition of floating point number (%s)"
#define _SET_ERRORMES_CREATEDICT "Unable to create a dictionary"
#define _SET_ERRORMES_CONVERTLIST "Unable to convert list"
#define _SET_ERRORMES_CONVERTSTRUCT "Unable to convert struct"
#define _SET_ERRORMES_DICTEXIST "The dict has not been initialised"
#define _SET_ERRORMES_UNKNOWNTYPE "Type is not in the database (%s)"
#define _SET_ERRORMES_DICTITEM "Unable to retrieve item from dict (%s)"
#define _SET_ERRORMES_READTYPE "Unable to read the type (%s: %lu)"
#define _SET_ERRORMES_READVALUE "Unable to read the value (%s: %lu)"
#define _SET_ERRORMES_DICTADD "Unable to add item to dict (%s)"
#define _SET_ERRORMES_DUBLICATE "2 fields have been given the same name (%s: %lu)"
#define _SET_ERRORMES_WRONGTYPE "Unknown type ID (%u)"
#define _SET_ERRORMES_LISTELEMENT "If one element is a list, they all must be a list of the same depth (%s: %lu)"
#define _SET_ERRORMES_NOELEMENTS "A list must have at least one element"
#define _SET_ERRORMES_TYPEELEMENT "If one element is either a char, string or struct all other elements must be too (%s: %lu)"
#define _SET_ERRORMES_NUMBERELEMENT "If one element is a number all other elements must be too (%s: %lu)"
#define _SET_ERRORMES_DEPTHMATCH "List did not have expected depth (Expected: %u, received: %u)"
#define _SET_ERRORMES_TYPEMATCH "Value did not have expected type (Expected: %u, received: %u)"
#define _SET_ERRORMES_FLOATMATCH "Unable to convert a float into an int"
#define _SET_ERRORMES_SINTMATCH "Unable to convert an interger into a smaller interger (Goal: %u, received: %u)"
#define _SET_ERRORMES_SINTMATCH2 "Unable to convert a signed integer into an unsigned integer (Goal: %u, received: %u)"
#define _SET_ERRORMES_INTMATCH "Unable to convert an unsigned integer into a smaller unsigned integer (Goal: %u, received: %u)"
#define _SET_ERRORMES_NOSTRUCT "Structs and lists cannot be converted"
#define _SET_ERRORMES_NUMBERMATCH "Cannot convert a non-number into a number (Received: %u)"
#define _SET_ERRORMES_LISTMATCH "Found list but expected a different type (Expected: %u)"
#define _SET_ERRORMES_LISTMATCH2 "Expected a list but found a different type (Received: %u)"
#define _SET_ERRORMES_NUMBERCONVERT "Unable to convert number"
#define _SET_ERRORMES_HIGHNUMBER "The number is too large (Max: %lu, received: %s)"
#define _SET_ERRORMES_HIGHHEX "The number is too large (Max: %lX, received: %s)"
#define _SET_ERRORMES_HIGHNUMBERSIGNED "The number is too %s (%s: %li, received: %s)"
#define _SET_ERRORMES_CONVERTEXP "Unable to convert exponentiation (%s)"
#define _SET_ERRORMES_FINITE "Floating point number is not finite (%s)"
#define _SET_ERRORMES_UNKNOWNSPECIAL "Unknown special character (\\%c)"
#define _SET_ERRORMES_CONVERTSPECIALCHAR "Unable to convert special char (%s)"
#define _SET_ERRORMES_NOPOSSIBLEVALUE "The value cannot be any type"
#define _SET_ERRORMES_CONVERTVALUE "Unable to convert value"
#define _SET_ERRORMES_LOADFILE "Unable to load file (%s)"
#define _SET_ERRORMES_CLEANFILE "Unable to clean file (%s)"
#define _SET_ERRORMES_SPLITFILE "Unable to split file (%s)"
#define _SET_ERRORMES_DICTLIST "Unable to add a list to a dict"
#define _SET_ERRORMES_CONVERTFILE "Unable to convert file (%s)"
#define _SET_ERRORMES_TRANSLATEFILL "Dict is missing a field which must be included in FILL mode (%s)"
#define _SET_ERRORMES_WRONGTYPE2 "Unknown type ID (%s: %u)"
#define _SET_ERRORMES_STRINGMATCH "Cannot convert other types into strings (Received: %u)"
#define _SET_ERRORMES_STRUCTMATCH "Cannot convert other types into structs (Received: %u)"
#define _SET_ERRORMES_MISSINGSUB "Translation table is missing sub"
#define _SET_ERRORMES_TRANSLATEEMPTY "Dict has too many fields which must not be the case in EMPTY mode (%s)"
#define _SET_ERRORMES_LISTMATCH3 "The depth of list did not match what was expected (Expected: %u, received: %u)"
#define _SET_ERRORMES_CONVERTLIST2 "Unable to convert list (%s: %lu)"
#define _SET_ERRORMES_TRANSLATELIST "Unable to translate list"
#define _SET_ERRORMES_TRANSLATEITEM "Unable to translate item (%s)"

enum __SET_ValueType {
    SET_VALUETYPE_VALUE,
    SET_VALUETYPE_LIST,
    SET_VALUETYPE_STRUCT
};

enum __SET_DataType {
    SET_DATATYPE_NONE,
    SET_DATATYPE_INT,
    SET_DATATYPE_INT8,
    SET_DATATYPE_UINT8,
    SET_DATATYPE_INT16,
    SET_DATATYPE_UINT16,
    SET_DATATYPE_INT32,
    SET_DATATYPE_UINT32,
    SET_DATATYPE_INT64,
    SET_DATATYPE_UINT64,
    SET_DATATYPE_SINT8,
    SET_DATATYPE_SINT16,
    SET_DATATYPE_SINT32,
    SET_DATATYPE_SINT64,
    SET_DATATYPE_DOUBLE,
    SET_DATATYPE_FLOAT,
    SET_DATATYPE_CHAR,
    SET_DATATYPE_STR,
    SET_DATATYPE_STRUCT,
    SET_DATATYPE_LIST
};

enum __SET_DataTypeBase {
    SET_DATATYPEBASE_NONE = 0x00,
    SET_DATATYPEBASE_UINT = 0x01,
    SET_DATATYPEBASE_SINT = 0x02,
    SET_DATATYPEBASE_FLOAT = 0x04,
    SET_DATATYPEBASE_CHAR = 0x08,
    SET_DATATYPEBASE_STRING = 0x10
};

enum __SET_TranslationMode {
    SET_TRANSLATIONMODE_NONE = 0x0, // No mode activated
    SET_TRANSLATIONMODE_FILL = 0x1, // The struct must be filled completely
    SET_TRANSLATIONMODE_EMPTY = 0x2 // The dict must be emptied completely (no extra fields)
};

typedef union ___SET_Data _SET_Data;
typedef struct __SET_Data SET_Data;
typedef struct __SET_DataList SET_DataList;
typedef enum __SET_DataType SET_DataType;
typedef enum __SET_ValueType SET_ValueType;
typedef enum __SET_DataTypeBase SET_DataTypeBase;
typedef enum __SET_TranslationMode SET_TranslationMode;
typedef struct __SET_CodeName SET_CodeName;
typedef struct __SET_CodeValue SET_CodeValue;
typedef union ___SET_CodeValue _SET_CodeValue;
typedef struct __SET_CodeStruct SET_CodeStruct;
typedef struct __SET_CodeList SET_CodeList;
typedef struct __SET_TranslationTable SET_TranslationTable;

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
    char c;
    char *str;
    DIC_Dict *stct;
    SET_DataList *list;
};

struct __SET_Data {
    _SET_Data data; // The data value
    SET_DataType type; // The type of the data
};

struct __SET_DataList {
    uint32_t count; // The number of items in the list
    SET_Data **list; // The list of values
    SET_DataType type; // The type of the list
    uint32_t depth; // The depth of the list
};

struct __SET_CodeName {
    char *type; // The data type the field should store
    char *name; // The name of the field
    uint8_t pointer; // The pointer depth found in the type
};

struct __SET_CodeList {
    SET_CodeValue **list; // A list of values
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
    SET_CodeName **names; // A list of the names of the fields
    SET_CodeValue **values; // A list of the values of the fields
    uint32_t count; // The number of fields
};

struct __SET_TranslationTable {
    char *name; // The name of the field
    SET_DataType type; // The type of the data
    size_t size; // The size of the value, if a list then it is the size of each member at the deepest level
    uint8_t depth; // How deep the list goes, 0 if it is not a list
    size_t offset; // The offset of the location
    SET_TranslationTable *sub; // The sub translation table list used if Type is struct
    size_t count; // The number of elements in the sub table
};

// List of special characters which should ignore spaces
uint32_t _SET_SpecialCharLength = 28;
char _SET_SpecialChar[] = {';', ':', '=', '+', '-', '*', '/', '%', '?', '^', '<', '>', '!', '~', '|', '&', '\\', '$', '#', '@', '.', ',', '(', ')', '[', ']', '{', '}'};

// Types
#define _SET_TYPECOUNT 14
char *_SET_TypeNames[_SET_TYPECOUNT] = {"int", "uint8", "uint16", "uint32", "uint64", "int8", "int16", "int32", "int64", "float", "double", "char", "str", "struct"};
SET_DataType _SET_Types[_SET_TYPECOUNT] = {SET_DATATYPE_INT, SET_DATATYPE_UINT8, SET_DATATYPE_UINT16, SET_DATATYPE_UINT32, SET_DATATYPE_UINT64, SET_DATATYPE_SINT8, SET_DATATYPE_SINT16, SET_DATATYPE_SINT32, SET_DATATYPE_SINT64, SET_DATATYPE_FLOAT, SET_DATATYPE_DOUBLE, SET_DATATYPE_CHAR, SET_DATATYPE_STR, SET_DATATYPE_STRUCT};
DIC_Dict *_SET_TypeDict = NULL;

#define _SET_LINEPREMES "Line"
#define _SET_ELEMENTPREMES "Element"

// Highest numbers
#define _SET_HIGH_UINT8 0xFF
#define _SET_HIGH_UINT16 0xFFFF
#define _SET_HIGH_UINT32 0xFFFFFFFF
#define _SET_HIGH_UINT64 0xFFFFFFFFFFFFFFFF
#define _SET_HIGH_INT8 0x7F
#define _SET_HIGH_INT16 0x7FFF
#define _SET_HIGH_INT32 0x7FFFFFFF
#define _SET_HIGH_INT64 0x7FFFFFFFFFFFFFFF

// Removes newlines, tabs and leading/trailing spaces
char *_SET_CleanString(const char *String);

// Splits a value up if needed
bool _SET_SplitValue(SET_CodeValue *Value);

// Splits a list into int's components
SET_CodeList *_SET_SplitList(char *String);

// Split string into field names and values
SET_CodeStruct *_SET_SplitString(char *String);

// Finds all the possible types for the value
SET_DataTypeBase _SET_GetPossibleType(const char *Value);

// Converts a code struct into a dictionary
DIC_Dict *_SET_ConvertStruct(const SET_CodeStruct *Struct);

// Converts a list from a string
SET_DataList *_SET_ConvertList(const SET_CodeList *List, SET_DataType Type, uint8_t Depth);

// Converts a single value from a string
SET_Data *_SET_ConvertValue(const SET_CodeValue *Value, SET_DataType Type, uint8_t Depth);

// Reads the type
SET_DataType _SET_ReadType(const char *Type);

// Converts data to a specific type, does not convert lists or structs
SET_Data _SET_ConvertType(SET_Data *Data, SET_DataType Type);

// Converts a string to an unsigned int
SET_Data _SET_ConvertUint(const char *String);

// Converts a string to an unsigned int 64 from standard form
SET_Data _SET_ReadUint(const char *String);

// Converts a string to an unsigned int 64 from hex form
SET_Data _SET_ReadHex(const char *String);

// Converts a string to an unsigned int 64 from bin form
SET_Data _SET_ReadBin(const char *String);

// Converts a string to a signed int
SET_Data _SET_ConvertSint(const char *String);

// Converts a string to a signed int 64
SET_Data _SET_ReadSint(const char *String);

// Converts a string to a float
SET_Data _SET_ConvertFloat(const char *String);

// Converts a string to a char
SET_Data _SET_ConvertChar(const char *String);

// Converts a string to another string
SET_Data _SET_ConvertString(const char *String);

// Reads a special character
char _SET_ConvertSpecialChar(char Char);

// Loads a settings file
// The output should be destroyed with SET_DestroyDataStruct not DIC_DestroyDict
DIC_Dict *SET_LoadSettings(const char *FileName);

// Converts a dict into a c struct using a translation table
bool SET_Translate(void *Struct, DIC_Dict *Dict, const SET_TranslationTable *Table, size_t Count, SET_TranslationMode Mode);

// Converts a list from a dict using a transation table
void *_SET_TranslateList(SET_DataList *DataList, const SET_TranslationTable *Table, uint8_t Depth, SET_TranslationMode Mode);

// Translate a single element
bool _SET_TranslateElement(void *Struct, SET_Data *Data, const SET_TranslationTable *Table, uint8_t Depth, SET_TranslationMode Mode);

// Reverse the work done during translation
void _SET_ReverseTranslation(void *Struct, DIC_Dict *Dict, const SET_TranslationTable *Table, size_t Count);

// Free a translation list
void _SET_ReverseTranslationList(void *List, SET_DataList *DataList, const SET_TranslationTable *Table);

// Initialize structs
void SET_InitData(SET_Data *Struct);
void SET_InitDataList(SET_DataList *Struct);
void SET_InitCodeStruct(SET_CodeStruct *Struct);
void SET_InitCodeName(SET_CodeName *Struct);
void SET_InitCodeValue(SET_CodeValue *Struct);
void SET_InitCodeList(SET_CodeList *Struct);
void SET_InitTranslationTable(SET_TranslationTable *Struct);

// Destroy struct
void SET_DestroyData(SET_Data *Struct);
void SET_DestroyDataList(SET_DataList *Struct);
void SET_DestroyDataStruct(DIC_Dict *Struct);
void SET_DestroyCodeStruct(SET_CodeStruct *Struct);
void SET_DestroyCodeName(SET_CodeName *Struct);
void SET_DestroyCodeValue(SET_CodeValue *Struct);
void SET_DestroyCodeList(SET_CodeList *Struct);

bool SET_Translate(void *Struct, DIC_Dict *Dict, const SET_TranslationTable *Table, size_t Count, SET_TranslationMode Mode)
{
    // Check that EMPTY mode is fulfilled
    if (Mode & SET_TRANSLATIONMODE_EMPTY)
        for (DIC_LinkList **List = Dict->list, **EndList = Dict->list + Dict->length; List < EndList; ++List)
            for (DIC_LinkList *Link = *List; Link != NULL; Link = Link->next)
            {
                const SET_TranslationTable *TableList = Table;
                for (const SET_TranslationTable *EndTableList = Table + Count; TableList < EndTableList; ++TableList)
                    if (strcmp(Link->key, TableList->name) == 0)
                        break;

                if (TableList >= Table + Count)
                {
                    _SET_SetError(_SET_ERRORID_TRANSLATE_EMPTY, _SET_ERRORMES_TRANSLATEEMPTY, Link->key);
                    _SET_ReverseTranslation(Struct, Dict, Table, TableList - Table);
                    return false;
                }
            }

    // Go through all of the fields
    for (const SET_TranslationTable *TableList = Table, *TableListEnd = Table + Count; TableList < TableListEnd; ++TableList)
    {
        // Check if it is in the dict
        if (!DIC_CheckItem(Dict, TableList->name))
        {
            // Check if it is an error
            if (Mode & SET_TRANSLATIONMODE_FILL)
            {
                _SET_SetError(_SET_ERRORID_TRANSLATE_FILL, _SET_ERRORMES_TRANSLATEFILL, TableList->name);
                _SET_ReverseTranslation(Struct, Dict, Table, TableList - Table);
                return false;
            }

            continue;
        }

        // Get the data
        SET_Data *Data = (SET_Data *)DIC_GetItem(Dict, TableList->name);

        if (Data == NULL)
        {
            _SET_AddErrorForeign(_SET_ERRORID_TRANSLATE_GETITEM, DIC_GetError(), _SET_ERRORMES_DICTITEM, TableList->name);
            _SET_ReverseTranslation(Struct, Dict, Table, TableList - Table);
            return false;
        }

        // Translate the item
        if (!_SET_TranslateElement(Struct + TableList->offset, Data, TableList, TableList->depth, Mode))
        {
            _SET_AddError(_SET_ERRORID_TRANSLATE_TRANSLATE, _SET_ERRORMES_TRANSLATEITEM, TableList->name);
            _SET_ReverseTranslation(Struct, Dict, Table, TableList - Table);
            return false;
        }
    }

    return true;
}

void *_SET_TranslateList(SET_DataList *DataList, const SET_TranslationTable *Table, uint8_t Depth, SET_TranslationMode Mode)
{
    void *NewList = NULL;

    // Get size of one element
    size_t Size = 0;

    if (Depth > 1)
        Size = sizeof(void *);
    
    else
        switch (Table->type)
        {
            case (SET_DATATYPE_INT8):
            case (SET_DATATYPE_UINT8):
                Size = sizeof(uint8_t);
                break;

            case (SET_DATATYPE_INT16):
            case (SET_DATATYPE_UINT16):
                Size = sizeof(uint16_t);
                break;

            case (SET_DATATYPE_INT32):
            case (SET_DATATYPE_UINT32):
                Size = sizeof(uint32_t);
                break;

            case (SET_DATATYPE_INT64):
            case (SET_DATATYPE_UINT64):
                Size = sizeof(uint64_t);
                break;

            case (SET_DATATYPE_SINT8):
                Size = sizeof(int8_t);
                break;

            case (SET_DATATYPE_SINT16):
                Size = sizeof(int16_t);
                break;

            case (SET_DATATYPE_SINT32):
                Size = sizeof(int32_t);
                break;

            case (SET_DATATYPE_SINT64):
                Size = sizeof(int64_t);
                break;

            case (SET_DATATYPE_FLOAT):
                Size = sizeof(float);
                break;

            case (SET_DATATYPE_DOUBLE):
                Size = sizeof(double);
                break;

            case (SET_DATATYPE_CHAR):
                Size = sizeof(char);
                break;

            case (SET_DATATYPE_STR):
                Size = sizeof(char *);
                break;

            case (SET_DATATYPE_STRUCT):
                Size = Table->size;
                break;

            default:
                _SET_SetError(_SET_ERRORID_TRANSLATELIST_UNKNOWNTYPE, _SET_ERRORMES_WRONGTYPE, Table->type);
                return NULL;
                break;
        }

    // Allocate memory
    NewList = malloc(Size * DataList->count);

    if (NewList == NULL)
    {
        _SET_AddErrorForeign(_SET_ERRORID_TRANSLATELIST_MALLOC1, strerror(errno), _SET_ERRORMES_MALLOC, Size * DataList->count);
        return NULL;
    }

    // Initialize
    if (Depth > 1 || Table->type == SET_DATATYPE_STR)
        for (void **InitList = (void **)NewList, **EndInitList = (void **)NewList + DataList->count; InitList < EndInitList; ++InitList)
            *InitList = NULL;

    // Fill in
    SET_Data **FillDataList = DataList->list;

    for (void *FillList = NewList, *EndFillList = NewList + Size * DataList->count; FillList < EndFillList; FillList += Size, ++FillDataList)
    {
        // Translate sub list
        if (!_SET_TranslateElement(FillList, *FillDataList, Table, Depth - 1, Mode))
        {
            _SET_AddError(_SET_ERRORID_TRANSLATELIST_CONVERTLIST, _SET_ERRORMES_CONVERTLIST2, _SET_ELEMENTPREMES, FillList - NewList);
            _SET_ReverseTranslationList(NewList, DataList, Table);
            free(NewList);
            return NULL;
        }
    }

    return NewList;
}

bool _SET_TranslateElement(void *Struct, SET_Data *Data, const SET_TranslationTable *Table, uint8_t Depth, SET_TranslationMode Mode)
{
    // Figure out what type it is
    // List
    if (Depth > 0)
    {
        // Make sure the depth is correct
        if (Data->type != SET_DATATYPE_LIST || Depth != Data->data.list->depth)
        {
            _SET_SetError(_SET_ERRORID_TRANSLATEELEMENT_LISTMATCH, _SET_ERRORMES_LISTMATCH3, Depth, ((Data->type == SET_DATATYPE_LIST) ? (Data->data.list->depth) : (0)));
            return false;
        }

        // Translate the list
        void *List = _SET_TranslateList(Data->data.list, Table, Depth, Mode | SET_TRANSLATIONMODE_FILL);

        if (List == NULL)
        {
            _SET_AddError(_SET_ERRORID_TRANSLATEELEMENT_LIST, _SET_ERRORMES_TRANSLATELIST);
            return false;
        }

        *(void **)Struct = List;
    }

    // Another struct
    else if (Table->type == SET_DATATYPE_STRUCT)
    {
        // Make sure type is correct
        if (Data->type != SET_DATATYPE_STRUCT)
        {
            _SET_SetError(_SET_ERRORID_TRANSLATEELEMENT_STRUCTMATCH, _SET_ERRORMES_STRUCTMATCH, Data->type);
            return false;
        }

        // Make sure there is a sub
        if (Table->sub == NULL)
        {
            _SET_SetError(_SET_ERRORID_TRANSLATEELEMENT_NOSTRUCT, _SET_ERRORMES_MISSINGSUB);
            return false;
        }

        // Fill in the struct
        if (!SET_Translate(Struct, Data->data.stct, Table->sub, Table->count, Mode))
        {
            _SET_AddError(_SET_ERRORID_TRANSLATEELEMENT_CONVERTSTRUCT, _SET_ERRORMES_CONVERTSTRUCT);
            return false;
        }
    }

    // A string
    else if (Table->type == SET_DATATYPE_STR)
    {
        // Make sure it is a string
        if (Data->type != SET_DATATYPE_STR)
        {
            _SET_SetError(_SET_ERRORID_TRANSLATEELEMENT_STRINGMATCH, _SET_ERRORMES_STRINGMATCH, Data->type);
            return false;
        }

        // Get memory
        char *String = (char *)malloc(sizeof(char) * (strlen(Data->data.str) + 1));

        if (String == NULL)
        {
            _SET_AddErrorForeign(_SET_ERRORID_TRANSLATEELEMENT_STRINGMALLOC, strerror(errno), _SET_ERRORMES_MALLOC, sizeof(char) * (strlen(Data->data.str) + 1));
            return false;
        }

        strcpy(String, Data->data.str);

        // Copy data
        *(char **)Struct = String;
    }

    // A number of char
    else if (Table->type >= SET_DATATYPE_INT8 && Table->type <= SET_DATATYPE_CHAR)
    {
        // Get the size
        size_t Size;

        switch (Table->type)
        {
            case (SET_DATATYPE_INT8):
            case (SET_DATATYPE_UINT8):
                Size = sizeof(uint8_t);
                break;

            case (SET_DATATYPE_INT16):
            case (SET_DATATYPE_UINT16):
                Size = sizeof(uint16_t);
                break;

            case (SET_DATATYPE_INT32):
            case (SET_DATATYPE_UINT32):
                Size = sizeof(uint32_t);
                break;

            case (SET_DATATYPE_INT64):
            case (SET_DATATYPE_UINT64):
                Size = sizeof(uint64_t);
                break;

            case (SET_DATATYPE_SINT8):
                Size = sizeof(int8_t);
                break;

            case (SET_DATATYPE_SINT16):
                Size = sizeof(int16_t);
                break;

            case (SET_DATATYPE_SINT32):
                Size = sizeof(int32_t);
                break;

            case (SET_DATATYPE_SINT64):
                Size = sizeof(int64_t);
                break;

            case (SET_DATATYPE_FLOAT):
                Size = sizeof(float);
                break;

            case (SET_DATATYPE_DOUBLE):
                Size = sizeof(double);
                break;

            case (SET_DATATYPE_CHAR):
                Size = sizeof(char);
                break;

            default:
                Size = 0;
                break;
        }

        // Attempt to convert type
        SET_Data ConvertData = _SET_ConvertType(Data, Table->type);

        if (ConvertData.type == SET_DATATYPE_NONE)
        {
            _SET_AddError(_SET_ERRORID_TRANSLATEELEMENT_CONVERTVALUE, _SET_ERRORMES_CONVERTVALUE);
            return false;
        }

        // Copy data
        memcpy(Struct, &ConvertData.data, Size);
    }

    // Error
    else
    {
        _SET_SetError(_SET_ERRORID_TRANSLATEELEMENT_UNKNOWNTYPE, _SET_ERRORMES_WRONGTYPE, Table->type);
        return false;
    }

    return true;
}

void _SET_ReverseTranslation(void *Struct, DIC_Dict *Dict, const SET_TranslationTable *Table, size_t Count)
{
    // Go through all of the fields
    for (const SET_TranslationTable *TableList = Table, *TableListEnd = Table + Count; TableList < TableListEnd; ++TableList)
    {
        // Find the item
        SET_Data *Data = (SET_Data *)DIC_GetItem(Dict, TableList->name);

        if (Data == NULL)
        {
            _SET_AddErrorForeign(_SET_ERRORID_REVERSETRANSLATION_GETITEM, DIC_GetError(), _SET_ERRORMES_DICTITEM, TableList->name);
            continue;
        }

        // If it is a list, free all of it and set to NULL
        if (TableList->depth > 0)
        {
            _SET_ReverseTranslationList(Struct + TableList->offset, Data->data.list, TableList);
            free(*(void **)(Struct + TableList->offset));
            *((void **)(Struct + TableList->offset)) = NULL;
        }

        // If it is a struct, reverse it
        else if (TableList->type == SET_DATATYPE_STRUCT)
            _SET_ReverseTranslation(Struct + TableList->offset, Data->data.stct, TableList->sub, TableList->count);

        // If it is a string, free it and set to NULL
        else if (TableList->type == SET_DATATYPE_STR)
        {
            free(*(char **)(Struct + TableList->offset));
            *((char **)(Struct + TableList->offset)) = NULL;
        }
    }
}

void _SET_ReverseTranslationList(void *List, SET_DataList *DataList, const SET_TranslationTable *Table)
{
    // If it is no deeper, free the rest
    if (DataList->depth == 1)
    {
        // Free strings
        if (Table->type == SET_DATATYPE_STR)
        {
            for (char **NewList = (char **)List, **EndNewList = (char **)List + DataList->count; NewList < EndNewList; ++NewList)
                if (*NewList != NULL)
                    free(*NewList);
        }

        // Free structs
        else if (Table->type == SET_DATATYPE_STRUCT)
        {
            SET_Data **NewDataList = DataList->list;

            for (void *NewList = List, *EndNewList = List + DataList->count * Table->size; NewList < EndNewList; NewList += Table->size, ++NewDataList)
                _SET_ReverseTranslation(NewList, (*NewDataList)->data.stct, Table->sub, Table->count);
        }
    }

    // If it is deeper
    else
    {
        SET_Data **NewDataList = DataList->list;

        // Go through and free each element in the list
        for (void **NewList = (void **)List, **EndNewList = (void **)List + DataList->count; NewList < EndNewList; ++NewList, ++NewDataList)
            if (NewList != NULL)
            {
                _SET_ReverseTranslationList(*NewList, (*NewDataList)->data.list, Table);
                free(*NewList);
            }
    }
}

DIC_Dict *SET_LoadSettings(const char *FileName)
{
    // Load file
    char *String = FIL_Load(FileName);

    if (String == NULL)
    {
        _SET_AddErrorForeign(_SET_ERRORID_LOADSETTINGS_LOAD, FIL_GetError(), _SET_ERRORMES_LOADFILE, FileName);
        return NULL;
    }

    // Clean string
    char *CleanString = _SET_CleanString(String);
    
    free(String);

    if (CleanString == NULL)
    {
        _SET_AddError(_SET_ERRORID_LOADSETTINGS_CLEAN, _SET_ERRORMES_CLEANFILE, FileName);
        return NULL;
    }

    // Split string
    SET_CodeStruct *CodeStruct = _SET_SplitString(CleanString);

    if (CodeStruct == NULL)
    {
        _SET_AddError(_SET_ERRORID_LOADSETTINGS_SPLIT, _SET_ERRORMES_SPLITFILE, FileName);
        free(CleanString);
        return NULL;
    }

    // Load type dict
    extern DIC_Dict *_SET_TypeDict;
    extern char *_SET_TypeNames[];
    extern SET_DataType _SET_Types[];

    _SET_TypeDict = DIC_CreateDict(_SET_TYPECOUNT);

    if (_SET_TypeDict == NULL)
    {
        _SET_AddErrorForeign(_SET_ERRORID_LOADSETTINGS_CREATEDICT, DIC_GetError(), _SET_ERRORMES_CREATEDICT);
        SET_DestroyCodeStruct(CodeStruct);
        free(CleanString);
        return NULL;
    }

    size_t ElementSize = sizeof(SET_DataType);

    if (!DIC_AddList(_SET_TypeDict, (const char **)_SET_TypeNames, _SET_TYPECOUNT, (void *)_SET_Types, &ElementSize, DIC_MODE_LIST))
    {
        _SET_AddErrorForeign(_SET_ERRORID_LOADSETTINGS_LOADDICT, DIC_GetError(), _SET_ERRORMES_DICTLIST);
        DIC_DestroyDict(_SET_TypeDict);
        _SET_TypeDict = NULL;
        SET_DestroyCodeStruct(CodeStruct);
        free(CleanString);
        return NULL;
    }

    // Convert
    DIC_Dict* Result = _SET_ConvertStruct(CodeStruct);

    if (Result == NULL)
    {
        _SET_AddError(_SET_ERRORID_LOADSETTINGS_CONVERT, _SET_ERRORMES_CONVERTFILE, FileName);
        DIC_DestroyDict(_SET_TypeDict);
        _SET_TypeDict = NULL;
        SET_DestroyCodeStruct(CodeStruct);
        free(CleanString);
        return NULL;
    }

    // Clean up
    DIC_DestroyDict(_SET_TypeDict);
    _SET_TypeDict = NULL;
    SET_DestroyCodeStruct(CodeStruct);
    free(CleanString);

    return Result;
}

char *_SET_CleanString(const char *String)
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

    for (const char *Current = String; *Current != '\0'; ++Current)
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

SET_CodeStruct *_SET_SplitString(char *String)
{
    // Get memory for the struct
    SET_CodeStruct *CodeStruct = (SET_CodeStruct *)malloc(sizeof(SET_CodeStruct));

    if (CodeStruct == NULL)
    {
        _SET_AddErrorForeign(_SET_ERRORID_SPLITSTRING_MALLOCSTRUCT, strerror(errno), _SET_ERRORMES_MALLOC, sizeof(SET_CodeStruct));
        return NULL;
    }

    SET_InitCodeStruct(CodeStruct);

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
                _SET_SetError(_SET_ERRORID_SPLITSTRING_STOPCHAR, _SET_ERRORMES_EARLYSTOPCHAR, _SET_LINEPREMES, CodeStruct->count + 1);
                SET_DestroyCodeStruct(CodeStruct);
                return NULL;
            }

            // Make sure it ends
            if (*(Current + WithSpecial + 2) != '\'')
            {
                _SET_SetError(_SET_ERRORID_SPLITSTRING_NOSTOPCHAR, _SET_ERRORMES_NOSTOPCHAR, _SET_LINEPREMES, CodeStruct->count + 1);
                SET_DestroyCodeStruct(CodeStruct);
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
                    _SET_SetError(_SET_ERRORID_SPLITSTRING_SPACEINVALUE, _SET_ERRORMES_SPACEINVALUE, _SET_LINEPREMES, CodeStruct->count + 1);
                    SET_DestroyCodeStruct(CodeStruct);
                    return NULL;
                }

                if (FoundType)
                {
                    _SET_SetError(_SET_ERRORID_SPLITSTRING_TYPETWICE, _SET_ERRORMES_TYPETWICE, _SET_LINEPREMES, CodeStruct->count + 1);
                    SET_DestroyCodeStruct(CodeStruct);
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
                    _SET_SetError(_SET_ERRORID_SPLITSTRING_VALUETWICE, _SET_ERRORMES_VALUETWICE, _SET_LINEPREMES, CodeStruct->count + 1);
                    SET_DestroyCodeStruct(CodeStruct);
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
                    _SET_SetError(_SET_ERRORID_SPLITSTRING_NOVALUE, _SET_ERRORMES_NOVALUE, _SET_LINEPREMES, CodeStruct->count + 1);
                    SET_DestroyCodeStruct(CodeStruct);
                    return NULL;
                }

                // Allocate memory for new line
                SET_CodeName **NewNames = (SET_CodeName **)realloc(CodeStruct->names, sizeof(SET_CodeName *) * (CodeStruct->count + 1));

                if (NewNames == NULL)
                {
                    _SET_SetError(_SET_ERRORID_SPLITSTRING_REALLOC, _SET_ERRORMES_REALLOC, sizeof(SET_CodeName *) * (CodeStruct->count + 1));
                    SET_DestroyCodeStruct(CodeStruct);
                    return NULL;
                }

                CodeStruct->names = NewNames;

                CodeStruct->names[CodeStruct->count] = (SET_CodeName *)malloc(sizeof(SET_CodeName));

                if (CodeStruct->names[CodeStruct->count] == NULL)
                {
                    _SET_SetError(_SET_ERRORID_SPLITSTRING_MALLOC, _SET_ERRORMES_MALLOC, sizeof(SET_CodeName));
                    SET_DestroyCodeStruct(CodeStruct);
                    return NULL;
                }

                SET_InitCodeName(CodeStruct->names[CodeStruct->count]);

                SET_CodeValue **NewValues = (SET_CodeValue **)realloc(CodeStruct->values, sizeof(SET_CodeValue *) * (CodeStruct->count + 1));

                if (NewValues == NULL)
                {
                    _SET_SetError(_SET_ERRORID_SPLITSTRING_REALLOC2, _SET_ERRORMES_REALLOC, sizeof(SET_CodeValue *) * (CodeStruct->count + 1));
                    SET_DestroyCodeStruct(CodeStruct);
                    return NULL;
                }

                CodeStruct->values = NewValues;

                CodeStruct->values[CodeStruct->count] = (SET_CodeValue *)malloc(sizeof(SET_CodeValue));

                if (CodeStruct->values[CodeStruct->count] == NULL)
                {
                    _SET_SetError(_SET_ERRORID_SPLITSTRING_MALLOC2, _SET_ERRORMES_MALLOC, sizeof(SET_CodeValue));
                    SET_DestroyCodeStruct(CodeStruct);
                    return NULL;
                }

                SET_InitCodeValue(CodeStruct->values[CodeStruct->count]);

                // Add the new line
                NewValues[CodeStruct->count]->type = SET_VALUETYPE_VALUE;
                NewValues[CodeStruct->count]->value.value = LastStart;
                NewNames[CodeStruct->count]->type = TypeString;
                NewNames[CodeStruct->count]->pointer = PointerCount;
                NewNames[CodeStruct->count++]->name = NameString;

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
        _SET_SetError(_SET_ERRORID_SPLITSTRING_ENDSTRING, _SET_ERRORMES_ENDSTRING, _SET_LINEPREMES, CodeStruct->count + 1);
        SET_DestroyCodeStruct(CodeStruct);
        return NULL;
    }

    // Make sure it ended with a line end
    if (*(Current - 1) != '\0' || FoundType || AfterEqual)
    {
        _SET_SetError(_SET_ERRORID_SPLITSTRING_END, _SET_ERRORMES_WRONGEND);
        SET_DestroyCodeStruct(CodeStruct);
        return NULL;
    }

    // Convert values into structs and lists
    for (SET_CodeValue **List = CodeStruct->values, **EndList = CodeStruct->values + CodeStruct->count; List < EndList; ++List)
        // Split the value
        if (!_SET_SplitValue(*List))
        {
            _SET_AddError(_SET_ERRORID_SPLITSTRING_SPLITVALUE, _SET_ERRORMES_SPLITVALUE, _SET_LINEPREMES, CodeStruct->count + 1);
            SET_DestroyCodeStruct(CodeStruct);
            return NULL;
        }

    // Return the struct
    return CodeStruct;
}

bool _SET_SplitValue(SET_CodeValue *Value)
{
    if (Value->value.value[0] == '\0')
    {
        _SET_SetError(_SET_ERRORID_SPLITVALUE_NOVALUE, _SET_ERRORMES_NOVALUE2);
        return false;
    }

    // Check for a structs
    if (*Value->value.value == '{')
    {
        // Make sure it ends with }
        size_t Length = strlen(Value->value.value);

        if (Value->value.value[Length - 1] != '}')
        {
            _SET_SetError(_SET_ERRORID_SPLITVALUE_ENDSTRUCT, _SET_ERRORMES_ENDSTRUCT);
            return false;
        }

        // Split the struct
        Value->value.value[Length - 1] = '\0';
        SET_CodeStruct *StructValue = _SET_SplitString(Value->value.value + 1);

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
            _SET_SetError(_SET_ERRORID_SPLITVALUE_ENDLIST, _SET_ERRORMES_ENDLIST);
            return false;
        }

        // Split the list
        Value->value.value[Length - 1] = '\0';
        SET_CodeList *ListValues = _SET_SplitList(Value->value.value + 1);

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

SET_CodeList *_SET_SplitList(char *String)
{
    // Get memory for the struct
    SET_CodeList *CodeList = (SET_CodeList *)malloc(sizeof(SET_CodeList));

    if (CodeList == NULL)
    {
        _SET_AddErrorForeign(_SET_ERRORID_SPLITLIST_MALLOCSTRUCT, strerror(errno), _SET_ERRORMES_MALLOC, sizeof(SET_CodeList));
        return NULL;
    }

    SET_InitCodeList(CodeList);

    if (String[0] == '\0')
        return CodeList;

    // Get first memory for list
    CodeList->list = (SET_CodeValue **)malloc(sizeof(SET_CodeValue *));

    if (CodeList->list == NULL)
    {
        _SET_AddErrorForeign(_SET_ERRORID_SPLITLIST_MALLOCLIST, strerror(errno), _SET_ERRORMES_MALLOC, sizeof(SET_CodeValue *));
        SET_DestroyCodeList(CodeList);
        return NULL;
    }

    *CodeList->list = (SET_CodeValue *)malloc(sizeof(SET_CodeValue));

    if (*CodeList->list == NULL)
    {
        _SET_AddErrorForeign(_SET_ERRORID_SPLITLIST_MALLOCLIST2, strerror(errno), _SET_ERRORMES_MALLOC, sizeof(SET_CodeValue));
        SET_DestroyCodeList(CodeList);
        return NULL;
    }

    SET_InitCodeValue(*CodeList->list);

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
                _SET_SetError(_SET_ERRORID_SPLITLIST_STOPCHAR, _SET_ERRORMES_EARLYSTOPCHAR, _SET_ELEMENTPREMES, CodeList->count + 1);
                SET_DestroyCodeList(CodeList);
                return NULL;
            }

            // Make sure it ends
            if (*(Current + WithSpecial + 2) != '\'')
            {
                _SET_SetError(_SET_ERRORID_SPLITLIST_NOSTOPCHAR, _SET_ERRORMES_NOSTOPCHAR, _SET_ELEMENTPREMES, CodeList->count + 1);
                SET_DestroyCodeList(CodeList);
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
            SET_CodeValue **NewList = (SET_CodeValue **)realloc(CodeList->list, sizeof(SET_CodeValue *) * (CodeList->count + 2));

            if (NewList == NULL)
            {
                _SET_SetError(_SET_ERRORID_SPLITLIST_REALLOCLIST, _SET_ERRORMES_REALLOC, sizeof(SET_CodeValue *) * (CodeList->count + 2));
                SET_DestroyCodeList(CodeList);
                return NULL;
            }

            CodeList->list = NewList;

            CodeList->list[CodeList->count + 1] = (SET_CodeValue *)malloc(sizeof(SET_CodeValue));

            if (CodeList->list[CodeList->count + 1] == NULL)
            {
                _SET_SetError(_SET_ERRORID_SPLITLIST_REALLOCLIST2, _SET_ERRORMES_MALLOC, sizeof(SET_CodeValue));
                SET_DestroyCodeList(CodeList);
                return NULL;
            }

            SET_InitCodeValue(CodeList->list[CodeList->count + 1]);

            NewList[CodeList->count]->type = SET_VALUETYPE_VALUE;
            NewList[CodeList->count++]->value.value = LastStart;

            *Current = '\0';
            LastStart = Current + 1;
            continue;
        }
    }

    // Make sure it is not inside of a string
    if (InString)
    {
        _SET_SetError(_SET_ERRORID_SPLITSTRING_ENDSTRING, _SET_ERRORMES_ENDSTRING, _SET_ELEMENTPREMES, CodeList->count + 1);
        SET_DestroyCodeList(CodeList);
        return NULL;
    }

    // Add the last element
    CodeList->list[CodeList->count]->type = SET_VALUETYPE_VALUE;
    CodeList->list[CodeList->count++]->value.value = LastStart;

    // Convert values into structs and lists
    for (SET_CodeValue **List = CodeList->list, **EndList = CodeList->list + CodeList->count; List < EndList; ++List)
        // Split the value
        if (!_SET_SplitValue(*List))
        {
            _SET_AddError(_SET_ERRORID_SPLITLIST_SPLITVALUE, _SET_ERRORMES_SPLITVALUE, _SET_ELEMENTPREMES, CodeList->count + 1);
            SET_DestroyCodeList(CodeList);
            return NULL;
        }

    // Return the list
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
    bool Exp = false;

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
            Type = SET_DATATYPEBASE_SINT | SET_DATATYPEBASE_FLOAT;
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
                    Type = SET_DATATYPEBASE_SINT | SET_DATATYPEBASE_UINT | SET_DATATYPEBASE_FLOAT;
                    Current -= 2;
                    break;
            }
            break;
        
        default:
            Type = SET_DATATYPEBASE_SINT | SET_DATATYPEBASE_UINT | SET_DATATYPEBASE_FLOAT;
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
                if (*Current != '0' && *Current != '1')
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

                    else if (Exp)
                    {
                        _SET_SetError(_SET_ERRORID_GETPOSSIBLETYPE_ILLIGALDOT2, _SET_ERRORMES_ILLIGALDOT2, Value);
                        return SET_DATATYPEBASE_NONE;
                    }

                    else
                    {
                        _SET_SetError(_SET_ERRORID_GETPOSSIBLETYPE_ILLIGALDOT, _SET_ERRORMES_ILLIGALDOT, Value);
                        return SET_DATATYPEBASE_NONE;
                    }
                }

                else if ((*Current == 'e' || *Current == 'E') && Type & SET_DATATYPEBASE_FLOAT)
                {
                    if (!Exp)
                    {
                        Exp = true;
                        Type = SET_DATATYPEBASE_FLOAT;

                        if (*(Current + 1) == '-')
                            ++Current;
                    }

                    else
                    {
                        _SET_SetError(_SET_ERRORID_GETPOSSIBLETYPE_ILLIGALEXP, _SET_ERRORMES_ILLIGALEXP, Value);
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

            for (const char *Current2 = Current - 1; *Current2 == '\\'; --Current2)
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

DIC_Dict *_SET_ConvertStruct(const SET_CodeStruct *Struct)
{
    // Create a dictionary
    DIC_Dict *Dict = DIC_CreateDict(Struct->count);

    if (Dict == NULL)
    {
        _SET_AddErrorForeign(_SET_ERRORID_CONVERTSTRUCT_CREATEDICT, DIC_GetError(), _SET_ERRORMES_CREATEDICT);
        return NULL;
    }
    
    // Start filling it up
    SET_CodeName **Names = Struct->names;
    SET_CodeName **EndNames = Names + Struct->count;
    SET_CodeValue **Values = Struct->values;

    for (; Names < EndNames; ++Names, ++Values)
    {
        // Test if the item is already there
        if (DIC_CheckItem(Dict, (*Names)->name))
        {
            _SET_SetError(_SET_ERRORID_CONVERTSTRUCT_DUBLICATE, _SET_ERRORMES_DUBLICATE, _SET_LINEPREMES, Names - Struct->names + 1);
            SET_DestroyDataStruct(Dict);
            return NULL;
        }
        
        // Get the type
        SET_DataType Type = SET_DATATYPE_NONE;

        if ((*Names)->type != NULL)
        {
            Type = _SET_ReadType((*Names)->type);

            if (Type == SET_DATATYPE_NONE)
            {
                _SET_AddError(_SET_ERRORID_CONVERTSTRUCT_TYPE, _SET_ERRORMES_READTYPE, _SET_LINEPREMES, Names - Struct->names + 1);
                SET_DestroyDataStruct(Dict);
                return NULL;
            }
        }
        
        // Read the value
        SET_Data *Value = _SET_ConvertValue(*Values, Type, (*Names)->pointer);

        if (Value == NULL)
        {
            _SET_AddError(_SET_ERRORID_CONVERTSTRUCT_VALUE, _SET_ERRORMES_READVALUE, _SET_LINEPREMES, Names - Struct->names + 1);
            SET_DestroyDataStruct(Dict);
            return NULL;
        }
        
        // Add to dict
        if (!DIC_AddItem(Dict, (*Names)->name, (void *)Value, 0, DIC_MODE_POINTER))
        {
            _SET_AddErrorForeign(_SET_ERRORID_CONVERTSTRUCT_ADDITEM, _SET_ERRORMES_DICTADD, (*Names)->name);
            SET_DestroyData(Value);
            SET_DestroyDataStruct(Dict);
            return NULL;
        }
    }
    
    return Dict;
}

SET_DataList *_SET_ConvertList(const SET_CodeList *List, SET_DataType Type, uint8_t Depth)
{
    if (List->count == 0)
    {
        _SET_SetError(_SET_ERRORID_CONVERTLIST_NOELEMENTS, _SET_ERRORMES_NOELEMENTS);
        return NULL;
    }
    
    // Allocate memory
    SET_DataList *ListObject = (SET_DataList *)malloc(sizeof(SET_DataList));

    if (ListObject == NULL)
    {
        _SET_AddErrorForeign(_SET_ERRORID_CONVERTLIST_MALLOC, strerror(errno), _SET_ERRORMES_MALLOC, sizeof(SET_DataList));
        return NULL;
    }
    
    SET_InitDataList(ListObject);
    
    // Add in the list
    ListObject->list = (SET_Data **)malloc(sizeof(SET_Data *) * List->count);

    if (ListObject->list == NULL)
    {
        _SET_AddErrorForeign(_SET_ERRORID_CONVERTLIST_MALLOCLIST, strerror(errno), _SET_ERRORMES_MALLOC, sizeof(SET_Data *) * List->count);
        SET_DestroyDataList(ListObject);
        return NULL;
    }
    
    for (SET_Data **Elements = ListObject->list, **EndElements = ListObject->list + List->count; Elements < EndElements; ++Elements)
        *Elements = NULL;

    ListObject->count = List->count;
    
    // Go through each element in the list and convert them
    SET_Data **DataList = ListObject->list;

    for (SET_CodeValue **ValueList = List->list, **EndValueList = List->list + List->count; ValueList < EndValueList; ++ValueList, ++DataList)
    {
        // Convert value
        *DataList = _SET_ConvertValue(*ValueList, Type, Depth);

        if (*DataList == NULL)
        {
            _SET_AddError(_SET_ERRORID_CONVERTLIST_VALUE, _SET_ERRORMES_READVALUE, _SET_ELEMENTPREMES, ValueList - List->list);
            SET_DestroyDataList(ListObject);
            return NULL;
        }
    }
    
    // Find the common type
    SET_DataType CommonType = (*ListObject->list)->type;
    uint8_t CommonDepth = 0;

    if (CommonType == SET_DATATYPE_LIST)
    {
        CommonType = (*ListObject->list)->data.list->type;
        CommonDepth = (*ListObject->list)->data.list->depth;
    }
    
    for (SET_Data **ValueList = ListObject->list + 1, **EndValueList = ListObject->list + ListObject->count; ValueList < EndValueList; ++ValueList)
    {
        // Check for lists
        if (CommonDepth > 0)
        {
            if ((*ValueList)->type != SET_DATATYPE_LIST || (*ValueList)->data.list->depth != CommonDepth || (*ValueList)->data.list->type != CommonType)
            {
                _SET_SetError(_SET_ERRORID_CONVERTLIST_LISTELEMENT, _SET_ERRORMES_LISTELEMENT, _SET_ELEMENTPREMES, ValueList - ListObject->list);
                SET_DestroyDataList(ListObject);
                return NULL;
            }
        }

        else if ((*ValueList)->type == SET_DATATYPE_LIST)
        {
            _SET_SetError(_SET_ERRORID_CONVERTLIST_LISTELEMENT2, _SET_ERRORMES_LISTELEMENT, _SET_ELEMENTPREMES, ValueList - ListObject->list);
            SET_DestroyDataList(ListObject);
            return NULL;
        }

        // Check for special types
        else if ((*ValueList)->type >= SET_DATATYPE_CHAR && (*ValueList)->type <= SET_DATATYPE_STRUCT)
        {
            if ((*ValueList)->type != CommonType)
            {
                _SET_SetError(_SET_ERRORID_CONVERTLIST_TYPEELEMENT, _SET_ERRORMES_TYPEELEMENT, _SET_ELEMENTPREMES, ValueList - ListObject->list);
                SET_DestroyDataList(ListObject);
                return NULL;
            }
        }

        // Check for numbers
        else if ((*ValueList)->type >= SET_DATATYPE_INT8 && (*ValueList)->type <= SET_DATATYPE_FLOAT)
        {
            // Make sure it is supposed to be a number
            if (!(CommonType >= SET_DATATYPE_INT8 && CommonType <= SET_DATATYPE_DOUBLE))
            {
                _SET_SetError(_SET_ERRORID_CONVERTLIST_NUMBERELEMENT, _SET_ERRORMES_NUMBERELEMENT, _SET_ELEMENTPREMES, ValueList - ListObject->list);
                SET_DestroyDataList(ListObject);
                return NULL;
            }
            
            // Find out what number it must be
            // Floats
            if (CommonType == SET_DATATYPE_DOUBLE || (*ValueList)->type == SET_DATATYPE_DOUBLE)
                CommonType = SET_DATATYPE_DOUBLE;

            else if (CommonType == SET_DATATYPE_FLOAT || (*ValueList)->type == SET_DATATYPE_FLOAT)
                CommonType = SET_DATATYPE_FLOAT;

            // Signed ints
            else if (CommonType >= SET_DATATYPE_SINT8 || (*ValueList)->type >= SET_DATATYPE_SINT8)
            {
                // Get what type of signed int it should be
                uint8_t CommonSize;
                uint8_t ValueSize;

                if (CommonType >= SET_DATATYPE_SINT8)
                    CommonSize = CommonType - SET_DATATYPE_SINT8;

                else
                    CommonSize = (CommonType - SET_DATATYPE_INT8 + 1) / 2;

                if ((*ValueList)->type >= SET_DATATYPE_SINT8)
                    ValueSize = (*ValueList)->type - SET_DATATYPE_SINT8;

                else
                    ValueSize = ((*ValueList)->type - SET_DATATYPE_INT8 + 1) / 2;

                if (ValueSize > CommonSize)
                    CommonSize = ValueSize;
                    
                CommonType = SET_DATATYPE_SINT8 + CommonSize;
            }

            // Not a signed int
            else if ((*ValueList)->type > CommonType)
                CommonType = (*ValueList)->type;
        }

        else
        {
            _SET_SetError(_SET_ERRORID_CONVERTLIST_TYPE, _SET_ERRORMES_WRONGTYPE, (*ValueList)->type);
            SET_DestroyDataList(ListObject);
            return NULL;
        }
        
    }
    
    // Convert elements to the same type
    if (CommonDepth == 0 && CommonType >= SET_DATATYPE_INT8 && CommonType <= SET_DATATYPE_FLOAT)
        for (SET_Data **ValueList = ListObject->list, **EndValueList = ListObject->list + ListObject->count; ValueList < EndValueList; ++ValueList)
            if ((*ValueList)->type != CommonType)
                **ValueList = _SET_ConvertType(*ValueList, CommonType);
                
    // Finish up
    ListObject->type = CommonType;
    ListObject->depth = CommonDepth + 1;

    return ListObject;
}

SET_Data *_SET_ConvertValue(const SET_CodeValue *Value, SET_DataType Type, uint8_t Depth)
{
    // Check that there is a value
    if (Value->value.value == NULL)
    {
        _SET_SetError(_SET_ERRORID_CONVERTVALUE_NOVALUE, _SET_ERRORMES_NOVALUE2);
        return NULL;
    }
    
    // Allocate memory
    SET_Data *Data = (SET_Data *)malloc(sizeof(SET_Data));

    if (Data == NULL)
    {
        _SET_AddErrorForeign(_SET_ERRORID_CONVERTVALUE_MALLOC, strerror(errno), _SET_ERRORMES_MALLOC, sizeof(SET_Data));
        return NULL;
    }
    
    SET_InitData(Data);
    SET_DataTypeBase PossibleType;

    // Make sure it is a list if needed
    if (Type != SET_DATATYPE_NONE && Depth > 0 && Value->type != SET_VALUETYPE_LIST)
    {
        _SET_AddError(_SET_ERRORID_CONVERTVALUE_LISTMATCH2, _SET_ERRORMES_LISTMATCH2, Value->type);
        SET_DestroyData(Data);
        return NULL;
    }
    
    // Find the type of value
    switch (Value->type)
    {
        case (SET_VALUETYPE_LIST):
            // Make sure it is supposed to be a list
            if (Type != SET_DATATYPE_NONE && Depth == 0)
            {
                _SET_AddError(_SET_ERRORID_CONVERTVALUE_LISTMATCH, _SET_ERRORMES_LISTMATCH, Type);
                SET_DestroyData(Data);
                return NULL;
            }

            // Get the data
            Data->data.list = _SET_ConvertList(Value->value.list, Type, Depth - 1);

            if (Data->data.list == NULL)
            {
                _SET_AddError(_SET_ERRORID_CONVERTVALUE_LIST, _SET_ERRORMES_CONVERTLIST);
                SET_DestroyData(Data);
                return NULL;
            }

            // Set the type
            Data->type = SET_DATATYPE_LIST;
            break;

        case (SET_VALUETYPE_STRUCT):
            // Get the data
            Data->data.stct = _SET_ConvertStruct(Value->value.sub);

            if (Data->data.stct == NULL)
            {
                _SET_AddError(_SET_ERRORID_CONVERTVALUE_STRUCT, _SET_ERRORMES_CONVERTSTRUCT);
                SET_DestroyData(Data);
                return NULL;
            }

            // Set the type
            Data->type = SET_DATATYPE_STRUCT;
            break;

        case (SET_VALUETYPE_VALUE):
            // Figure out what type it is
            PossibleType = _SET_GetPossibleType(Value->value.value);

            // Convert
            if (PossibleType & SET_DATATYPEBASE_CHAR)
                *Data = _SET_ConvertChar(Value->value.value);

            else if (PossibleType & SET_DATATYPEBASE_STRING)
                *Data = _SET_ConvertString(Value->value.value);

            else if (PossibleType & SET_DATATYPEBASE_UINT)
                *Data = _SET_ConvertUint(Value->value.value);

            else if (PossibleType & SET_DATATYPEBASE_SINT)
                *Data = _SET_ConvertSint(Value->value.value);

            else if (PossibleType & SET_DATATYPEBASE_FLOAT)
                *Data = _SET_ConvertFloat(Value->value.value);

            else
            {
                _SET_AddError(_SET_ERRORID_CONVERTVALUE_NOPOSSIBLEVALUE, _SET_ERRORMES_NOPOSSIBLEVALUE);
                SET_DestroyData(Data);
                return NULL;
            }

            if (Data->type == SET_DATATYPE_NONE)
            {
                _SET_AddError(_SET_ERRORID_CONVERTVALUE_CONVERT, _SET_ERRORMES_CONVERTVALUE);
                SET_DestroyData(Data);
                return NULL;
            }

            break;

        default:
            break;
    }

    // Make sure the type is correct
    if (Type != SET_DATATYPE_NONE && Data->type != SET_DATATYPE_LIST)
    {
        // Check for special types
        if (Type >= SET_DATATYPE_CHAR && Type <= SET_DATATYPE_STRUCT)
        {
            if (Data->type != Type)
            {
                _SET_SetError(_SET_ERRORID_CONVERTVALUE_TYPEMATCH, _SET_ERRORMES_TYPEMATCH, Type, Data->type);
                SET_DestroyData(Data);
                return NULL;
            }
        }

        // Check for numbers
        else if (Type >= SET_DATATYPE_INT && Type <= SET_DATATYPE_FLOAT)
        {
            // Convert it
            SET_Data NewData = _SET_ConvertType(Data, Type);

            if (NewData.type == SET_DATATYPE_NONE)
            {
                _SET_AddError(_SET_ERRORID_CONVERTVALUE_NUMBERMATCH, _SET_ERRORMES_NUMBERCONVERT);
                SET_DestroyData(Data);
                return NULL;
            }

            if (Data->type != NewData.type)
                *Data = NewData;
        }

        else
        {
            _SET_SetError(_SET_ERRORID_CONVERTVALUE_TYPE, _SET_ERRORMES_WRONGTYPE, Type);
            SET_DestroyData(Data);
            return NULL;
        }
    }
    
    return Data;
}

SET_DataType _SET_ReadType(const char *Type)
{
    // Make sure the dict exists
    extern DIC_Dict *_SET_TypeDict;

    if (_SET_TypeDict == NULL)
    {
        _SET_SetError(_SET_ERRORID_READTYPE_DICT, _SET_ERRORMES_DICTEXIST);
        return SET_DATATYPE_NONE;
    }

    // Check that it exists
    if (!DIC_CheckItem(_SET_TypeDict, Type))
    {
        _SET_SetError(_SET_ERRORID_READTYPE_WRONGTYPE, _SET_ERRORMES_UNKNOWNTYPE, Type);
        return SET_DATATYPE_NONE;
    }

    // Get the item
    SET_DataType *DataType = (SET_DataType *)DIC_GetItem(_SET_TypeDict, Type);

    if (DataType == NULL)
    {
        _SET_AddErrorForeign(_SET_ERRORID_READTYPE_RETRIEVE, DIC_GetError(), _SET_ERRORMES_DICTITEM, Type);
        return SET_DATATYPE_NONE;
    }

    return *DataType;
}

SET_Data _SET_ConvertType(SET_Data *Data, SET_DataType Type)
{
    // Setup output
    SET_Data NewData;
    SET_InitData(&NewData);

    // Make sure it is legal
    if (Type == SET_DATATYPE_LIST || Type == SET_DATATYPE_STRUCT)
    {
        _SET_SetError(_SET_ERRORID_CONVERTTYPE_NOSTRUCT, _SET_ERRORMES_NOSTRUCT);
        return NewData;
    }

    // Do the standalones
    else if (Type == SET_DATATYPE_CHAR || Type == SET_DATATYPE_STR)
    {
        if (Type != Data->type)
        {
            _SET_SetError(_SET_ERRORID_CONVERTTYPE_TYPEMATCH, _SET_ERRORMES_TYPEMATCH, Type, Data->type);
            return NewData;
        }
    }

    // Make sure the number match up
    else if (Type >= SET_DATATYPE_INT && Type <= SET_DATATYPE_FLOAT)
    {
        if (!(Data->type >= SET_DATATYPE_INT8 && Data->type <= SET_DATATYPE_FLOAT))
        {
            _SET_SetError(_SET_ERRORID_CONVERTTYPE_NUMBERMATCH, _SET_ERRORMES_NUMBERMATCH, Data->type);
            return NewData;
        }

        else if (Type >= SET_DATATYPE_DOUBLE)
            ;

        else if (Data->type >= SET_DATATYPE_DOUBLE)
        {
            _SET_SetError(_SET_ERRORID_CONVERTTYPE_FLOATMATCH, _SET_ERRORMES_FLOATMATCH);
            return NewData;
        }

        else if (Type == SET_DATATYPE_INT)
            return *Data;

        else if (Type >= SET_DATATYPE_SINT8)
        {
            uint8_t Size;

            if (Data->type >= SET_DATATYPE_SINT8)
                Size = Data->type - SET_DATATYPE_SINT8;

            else
                Size = (Data->type - SET_DATATYPE_INT8 + 1) / 2;

            if (Size > Type - SET_DATATYPE_SINT8)
            {
                _SET_SetError(_SET_ERRORID_CONVERTTYPE_SINTMATCH, _SET_ERRORMES_SINTMATCH, Type, Data->type);
                return NewData;
            }
        }

        else if (Data->type >= SET_DATATYPE_SINT8)
        {
            _SET_SetError(_SET_ERRORID_CONVERTTYPE_SINTMATCH2, _SET_ERRORMES_SINTMATCH2, Type, Data->type);
            return NewData;
        }

        else if (Data->type > Type)
        {
            _SET_SetError(_SET_ERRORID_CONVERTTYPE_INTMATCH, _SET_ERRORMES_INTMATCH, Type, Data->type);
            return NewData;
        }
    }

    else
    {
        _SET_SetError(_SET_ERRORID_CONVERTTYPE_TYPEMATCH2, _SET_ERRORMES_TYPEMATCH, Type, Data->type);
        return NewData;
    }

    NewData.type = Type;

    // Convert the type to a general type
    uint64_t Uint;
    bool UseUint = false;
    int64_t Sint;
    bool UseSint = false;
    double Float;
    bool UseFloat = false;

    switch (Data->type)
    {
        // If a char or string, just return
        case (SET_DATATYPE_CHAR):
        case (SET_DATATYPE_STR):
            return *Data;

        // If an unsigned int
        case (SET_DATATYPE_INT8):
        case (SET_DATATYPE_UINT8):
            Uint = (uint64_t)Data->data.u8;
            UseUint = true;
            break;

        case (SET_DATATYPE_INT16):
        case (SET_DATATYPE_UINT16):
            Uint = (uint64_t)Data->data.u16;
            UseUint = true;
            break;

        case (SET_DATATYPE_INT32):
        case (SET_DATATYPE_UINT32):
            Uint = (uint64_t)Data->data.u32;
            UseUint = true;
            break;

        case (SET_DATATYPE_INT64):
        case (SET_DATATYPE_UINT64):
            Uint = (uint64_t)Data->data.u64;
            UseUint = true;
            break;

        // If signed int
        case (SET_DATATYPE_SINT8):
            Sint = (int64_t)Data->data.i8;
            UseSint = true;
            break;

        case (SET_DATATYPE_SINT16):
            Sint = (int64_t)Data->data.i16;
            UseSint = true;
            break;

        case (SET_DATATYPE_SINT32):
            Sint = (int64_t)Data->data.i32;
            UseSint = true;
            break;

        case (SET_DATATYPE_SINT64):
            Sint = (int64_t)Data->data.i64;
            UseSint = true;
            break;

        // If float
        case (SET_DATATYPE_FLOAT):
            Float = (double)Data->data.f;
            UseFloat = true;
            break;

        case (SET_DATATYPE_DOUBLE):
            Float = (double)Data->data.d;
            UseFloat = true;
            break;

        default:
            break;
    }

    if (Type >= SET_DATATYPE_DOUBLE)
    {
        if (UseUint)
            Float = (double)Uint;

        else if (UseSint)
            Float = (double)Sint;
    }

    else if (Type >= SET_DATATYPE_SINT8)
    {
        if (UseUint)
            Sint = (int64_t)Uint;

        else if (UseFloat)
            Sint = (int64_t)Float;
    }

    else
    {
        if (UseSint)
            Uint = (uint64_t)Sint;

        else if (UseFloat)
            Uint = (uint64_t)Float;
    }

    // Convert to the correct type
    switch (Type)
    {
        // Unsigned int
        case (SET_DATATYPE_INT8):
        case (SET_DATATYPE_UINT8):
            NewData.data.u8 = (uint8_t)Uint;
            break;

        case (SET_DATATYPE_INT16):
        case (SET_DATATYPE_UINT16):
            NewData.data.u16 = (uint16_t)Uint;
            break;

        case (SET_DATATYPE_INT32):
        case (SET_DATATYPE_UINT32):
            NewData.data.u32 = (uint32_t)Uint;
            break;

        case (SET_DATATYPE_INT64):
        case (SET_DATATYPE_UINT64):
            NewData.data.u64 = (uint64_t)Uint;
            break;

        // Signed int
        case (SET_DATATYPE_SINT8):
            NewData.data.i8 = (int8_t)Sint;
            break;

        case (SET_DATATYPE_SINT16):
            NewData.data.i16 = (int16_t)Sint;
            break;

        case (SET_DATATYPE_SINT32):
            NewData.data.i32 = (int32_t)Sint;
            break;

        case (SET_DATATYPE_SINT64):
            NewData.data.i64 = (int64_t)Sint;
            break;

        // Float
        case (SET_DATATYPE_FLOAT):
            NewData.data.f = (float)Float;
            break;

        case (SET_DATATYPE_DOUBLE):
            NewData.data.d = (double)Float;
            break;

        default:
            break;
    }

    return NewData;
}

SET_Data _SET_ConvertUint(const char *String)
{
    SET_Data Value;
    SET_InitData(&Value);

    // Get the length
    size_t Length = strlen(String);

    // Convert number
    if (Length >= 2 && String[1] == 'x')
        Value = _SET_ReadHex(String + 2);

    else if (Length >= 2 && String[1] == 'b')
        Value = _SET_ReadBin(String + 2);

    else
        Value = _SET_ReadUint(String);

    if (Value.type == SET_DATATYPE_NONE)
    {
        _SET_SetError(_SET_ERRORID_CONVERTUINT_CONVERT, _SET_ERRORMES_NUMBERCONVERT);
        return Value;
    }

    // Convert it to the lowest possible type
    if (Value.data.u64 <= _SET_HIGH_INT8)
    {
        Value.data.u8 = (uint8_t)Value.data.u64;
        Value.type = SET_DATATYPE_INT8;
    }

    else if (Value.data.u64 <= _SET_HIGH_UINT8)
    {
        Value.data.u8 = (uint8_t)Value.data.u64;
        Value.type = SET_DATATYPE_UINT8;
    }

    else if (Value.data.u64 <= _SET_HIGH_INT16)
    {
        Value.data.u16 = (uint16_t)Value.data.u64;
        Value.type = SET_DATATYPE_INT16;
    }

    else if (Value.data.u64 <= _SET_HIGH_UINT16)
    {
        Value.data.u16 = (uint16_t)Value.data.u64;
        Value.type = SET_DATATYPE_UINT16;
    }

    else if (Value.data.u64 <= _SET_HIGH_INT32)
    {
        Value.data.u32 = (uint32_t)Value.data.u64;
        Value.type = SET_DATATYPE_INT32;
    }

    else if (Value.data.u64 <= _SET_HIGH_UINT32)
    {
        Value.data.u32 = (uint32_t)Value.data.u64;
        Value.type = SET_DATATYPE_UINT32;
    }

    else if (Value.data.u64 <= _SET_HIGH_INT64)
        Value.type = SET_DATATYPE_INT64;

    return Value;
}

SET_Data _SET_ReadUint(const char *String)
{
    SET_Data Value;
    Value.type = SET_DATATYPE_NONE;
    Value.data.u64 = 0;

    // Get the length
    if (strlen(String) == 0)
    {
        _SET_AddError(_SET_ERRORID_READUINT_NOSTRING, _SET_ERRORMES_NOVALUE2);
        return Value;
    }

    // Remove leading 0
    for (; *String == '0'; ++String)
        ;

    // Start reading
    for (const char *NewString = String; *NewString != '\0'; ++NewString)
    {
        if (Value.data.u64 > _SET_HIGH_UINT64 / 10)
        {
            _SET_SetError(_SET_ERRORID_READUINT_HIGH, _SET_ERRORMES_HIGHNUMBER, _SET_HIGH_UINT64, String);
            return Value;
        }

        uint64_t NewInt = Value.data.u64 * 10 + *NewString - '0';

        if (NewInt < Value.data.u64)
        {
            _SET_SetError(_SET_ERRORID_READUINT_HIGH2, _SET_ERRORMES_HIGHNUMBER, _SET_HIGH_UINT64, String);
            return Value;
        }

        Value.data.u64 = NewInt;
    }

    Value.type = SET_DATATYPE_UINT64;
    return Value;
}

SET_Data _SET_ReadHex(const char *String)
{
    SET_Data Value;
    Value.type = SET_DATATYPE_NONE;
    Value.data.u64 = 0;

    // Get the length
    if (strlen(String) == 0)
    {
        _SET_AddError(_SET_ERRORID_READHEX_NOSTRING, _SET_ERRORMES_NOVALUE2);
        return Value;
    }

    // Remove leading 0
    for (; *String == '0'; ++String)
        ;

    // Make sure it is not too large
    if (strlen(String) > sizeof(uint64_t) * 2)
    {
        _SET_SetError(_SET_ERRORID_READHEX_HIGH, _SET_ERRORMES_HIGHHEX, _SET_HIGH_UINT64, String);
        return Value;
    }

    // Read
    for (const char *NewString = String; *NewString != '\0'; ++NewString)
    {
        Value.data.u64 *= 0x10;

        if (*NewString >= '0' && *NewString <= '9')
            Value.data.u64 += *NewString - '0';

        else if (*NewString >= 'a' && *NewString <= 'f')
            Value.data.u64 += *NewString - 'a' + 0xA;

        else
            Value.data.u64 += *NewString - 'A' + 0xA;
    }

    Value.type = SET_DATATYPE_UINT64;
    return Value;
}

SET_Data _SET_ReadBin(const char *String)
{
    SET_Data Value;
    Value.type = SET_DATATYPE_NONE;
    Value.data.u64 = 0;

    // Get the length
    if (strlen(String) == 0)
    {
        _SET_AddError(_SET_ERRORID_READBIN_NOSTRING, _SET_ERRORMES_NOVALUE2);
        return Value;
    }

    // Remove leading 0
    for (; *String == '0'; ++String)
        ;

    // Make sure it is not too large
    if (strlen(String) > sizeof(uint64_t) * 8)
    {
        _SET_SetError(_SET_ERRORID_READBIN_HIGH, _SET_ERRORMES_HIGHHEX, _SET_HIGH_UINT64, String);
        return Value;
    }

    // Read
    for (const char *NewString = String; *NewString != '\0'; ++NewString)
        Value.data.u64 = Value.data.u64 * 2 + *NewString - '0';

    Value.type = SET_DATATYPE_UINT64;
    return Value;
}

SET_Data _SET_ReadSint(const char *String)
{
    bool Negative = false;

    // Check if it is negative
    if (*String == '-')
        Negative = true;

    // Read the positive part
    SET_Data Value = _SET_ReadUint(String + Negative);

    if (Value.type == SET_DATATYPE_NONE)
    {
        _SET_AddError(_SET_ERRORID_READSINT_UINT, _SET_ERRORMES_NUMBERCONVERT);
        return Value;
    }

    // Make sure it is not too large
    if (Value.data.u64 > _SET_HIGH_INT64 + ((Negative) ? (1) : (0)))
    {
        _SET_SetError(_SET_ERRORID_READSINT_HIGH, _SET_ERRORMES_HIGHNUMBERSIGNED, ((Negative) ? ("small") : ("large")), ((Negative) ? ("Min") : ("Max")), (_SET_HIGH_INT64 + Negative) * ((Negative) ? (-1) : (1)), String);
        Value.type = SET_DATATYPE_NONE;
        return Value;
    }

    // Convert to signed int
    Value.data.i64 = (int64_t)Value.data.u64 * ((Negative) ? (-1) : (1));
    Value.type = SET_DATATYPE_SINT64;
}

SET_Data _SET_ConvertSint(const char *String)
{
    // Read
    SET_Data Value = _SET_ReadSint(String);

    if (Value.type == SET_DATATYPE_NONE)
    {
        _SET_SetError(_SET_ERRORID_CONVERTSINT_READ, _SET_ERRORMES_NUMBERCONVERT);
        return Value;
    }

    // Find the correct type
    bool Negative = ((Value.data.i64 < 0) ? (true) : (false));
    uint64_t Pos = (uint64_t)Value.data.i64 * ((Negative) ? (-1) : (1));

    if (Pos <= _SET_HIGH_INT8 + Negative)
    {
        Value.data.i8 = (int8_t)Value.data.i64;
        Value.type = SET_DATATYPE_SINT8;
    }

    else if (Pos <= _SET_HIGH_INT16 + Negative)
    {
        Value.data.i16 = (int16_t)Value.data.i64;
        Value.type = SET_DATATYPE_SINT16;
    }

    else if (Pos <= _SET_HIGH_INT32 + Negative)
    {
        Value.data.i32 = (int32_t)Value.data.i64;
        Value.type = SET_DATATYPE_SINT32;
    }

    else
        Value.type = SET_DATATYPE_SINT64;

    return Value;
}

SET_Data _SET_ConvertFloat(const char *String)
{
    bool Negative = false;

    // Check if it is negative
    if (*String == '-')
        Negative = true;

    // Read number
    const char *NewString;
    SET_Data Value;
    Value.data.d = 0.;
    Value.type = SET_DATATYPE_NONE;

    for (NewString = String + Negative; *NewString != '\0' && *NewString != '.' && *NewString != 'e' && *NewString != 'E'; ++NewString)
        Value.data.d = Value.data.d * 10. + (double)(*NewString - '0');

    // Add after .
    if (*NewString == '.')
    {
        ++NewString;

        for (double Size = 0.1; *NewString != '\0' && *NewString != 'e' && *NewString != 'E'; ++NewString, Size /= 10.)
            Value.data.d += (double)(*NewString - '0') * Size;
    }

    if (Negative)
        Value.data.d *= -1.;

    // Add exponentiation
    if (*NewString == 'e' || *NewString == 'E')
    {
        // Convert int
        SET_Data Exp = _SET_ReadSint(NewString + 1);

        if (Exp.type == SET_DATATYPE_NONE)
        {
            _SET_AddError(_SET_ERRORID_CONVERTFLOAT_EXP, _SET_ERRORMES_CONVERTEXP, String);
            return Value;
        }

        // Change the value
        Value.data.d *= pow(10., (double)Exp.data.i64);
    }

    // Check if it is finite
    if (!isfinite(Value.data.d))
    {
        _SET_SetError(_SET_ERRORID_CONVERTFLOAT_FINITE, _SET_ERRORMES_FINITE, String);
        return Value;
    }

    Value.type = SET_DATATYPE_DOUBLE;
    return Value;
}

char _SET_ConvertSpecialChar(char Char)
{
    // Figure out what it is
    switch (Char)
    {
        case ('n'):
            return '\n';

        case ('t'):
            return '\t';

        case ('s'):
            return '\0';

        case ('\''):
            return '\'';

        case ('\"'):
            return '\"';

        case ('\\'):
            return '\\';
        
        default:
            _SET_SetError(_SET_ERRORID_CONVERTSPECIALCHAR_UNKNOWN, _SET_ERRORMES_UNKNOWNSPECIAL, Char);
            return EOF;
    }
}

SET_Data _SET_ConvertChar(const char *String)
{
    SET_Data Value;
    SET_InitData(&Value);

    // Check if it needs a special char
    if (String[1] == '\\')
    {
        char Char = _SET_ConvertSpecialChar(String[2]);

        if (Char == EOF || Char == '\0')
        {
            _SET_AddError(_SET_ERRORID_CONVERTCHAR_SPECIAL, _SET_ERRORMES_CONVERTSPECIALCHAR, String);
            return Value;
        }

        Value.data.c = Char;
    }

    else
        Value.data.c = String[1];

    Value.type = SET_DATATYPE_CHAR;
    return Value;
}

SET_Data _SET_ConvertString(const char *String)
{
    SET_Data Value;
    SET_InitData(&Value);

    // Allocate memory
    size_t Length = strlen(String) - 2;

    char *NewString = (char *)malloc(sizeof(char) * (Length + 1));

    if (NewString == NULL)
    {
        _SET_SetError(_SET_ERRORID_CONVERTSTRING_MALLOC, _SET_ERRORMES_MALLOC, sizeof(char) * (Length + 1));
        return Value;
    }

    // Go through and copy
    char *Dst = NewString;
    for (const char *Src = String + 1; *Src != '\"'; ++Src, ++Dst)
    {
        // If it is a special char
        if (*Src == '\\')
        {
            char NewChar = _SET_ConvertSpecialChar(*(++Src));

            if (NewChar == EOF)
            {
                _SET_AddError(_SET_ERRORID_CONVERTSTRING_SPECIAL, _SET_ERRORMES_CONVERTSPECIALCHAR, String);
                free(NewString);
                return Value;
            }

            else if (NewChar != '\0')
                *Dst = NewChar;

            else
                --Dst;
        }

        else
            *Dst = *Src;
    }

    *(Dst++) = '\0';
    Value.data.str = (char *)realloc(NewString, sizeof(char) * (Dst - NewString));
    Value.type = SET_DATATYPE_STR;
    return Value;
}

void SET_InitData(SET_Data *Struct)
{
    Struct->data.stct = NULL;
    Struct->type = SET_DATATYPE_NONE;
}

void SET_InitDataList(SET_DataList *Struct)
{
    Struct->count = 0;
    Struct->list = NULL;
    Struct->depth = 0;
    Struct->type = SET_DATATYPE_NONE;
}

void SET_InitCodeStruct(SET_CodeStruct *Struct)
{
    Struct->names = NULL;
    Struct->values = NULL;
    Struct->count = 0;
}

void SET_InitCodeName(SET_CodeName *Struct)
{
    Struct->name = NULL;
    Struct->type = NULL;
    Struct->pointer = 0;
}

void SET_InitCodeValue(SET_CodeValue *Struct)
{
    Struct->type = SET_VALUETYPE_VALUE;
    Struct->value.value = NULL;
}

void SET_InitCodeList(SET_CodeList *Struct)
{
    Struct->list = NULL;
    Struct->count = 0;
}

void SET_InitTranslationTable(SET_TranslationTable *Struct)
{
    Struct->name = NULL;
    Struct->offset = 0;
    Struct->sub = NULL;
    Struct->type = SET_DATATYPE_NONE;
    Struct->depth = 0;
    Struct->count = 0;
}

void SET_DestroyData(SET_Data *Struct)
{
    switch (Struct->type)
    {
        case (SET_DATATYPE_STR):
            if (Struct->data.str != NULL)
                free(Struct->data.str);
            break;

        case (SET_DATATYPE_LIST):
            if (Struct->data.list != NULL)
                SET_DestroyDataList(Struct->data.list);
            break;

        case (SET_DATATYPE_STRUCT):
            if (Struct->data.stct != NULL)
                SET_DestroyDataStruct(Struct->data.stct);
            break;
        
        default:
            break;
    }

    free(Struct);
}

void SET_DestroyDataList(SET_DataList *Struct)
{
    if (Struct->list != NULL)
    {
        for (SET_Data **List = Struct->list, **EndList = Struct->list + Struct->count; List < EndList; ++List)
            if (*List != NULL)
                SET_DestroyData(*List);

        free(Struct->list);
    }

    free(Struct);
}

void SET_DestroyDataStruct(DIC_Dict *Struct)
{
    for (DIC_LinkList **List = Struct->list, **EndList = Struct->list + Struct->length; List < EndList; ++List)
        for (DIC_LinkList *Link = *List; Link != NULL; Link = Link->next)
            if (Link->value != NULL)
            {
                SET_DestroyData((SET_Data *)Link->value);
                Link->value = NULL;
            }

    DIC_DestroyDict(Struct);
}

void SET_DestroyCodeStruct(SET_CodeStruct *Struct)
{
    // Go through all of the elements
    if (Struct->values != NULL)
    {
        for (SET_CodeValue **List = Struct->values, **EndList = Struct->values + Struct->count; List < EndList; ++List)
            if (*List != NULL)
                SET_DestroyCodeValue(*List);

        free(Struct->values);
    }

    if (Struct->names != NULL)
    {
        for (SET_CodeName **List = Struct->names, **EndList = Struct->names + Struct->count; List < EndList; ++List)
            if (*List != NULL)
                SET_DestroyCodeName(*List);

        free(Struct->names);
    }

    free(Struct);
}

void SET_DestroyCodeName(SET_CodeName *Struct)
{
    free(Struct);
}

void SET_DestroyCodeValue(SET_CodeValue *Struct)
{
    switch (Struct->type)
    {
        case SET_VALUETYPE_VALUE:
            break;

        case SET_VALUETYPE_LIST:
            if (Struct->value.list != NULL)
                SET_DestroyCodeList(Struct->value.list);
            break;

        case SET_VALUETYPE_STRUCT:
            if (Struct->value.sub != NULL)
                SET_DestroyCodeStruct(Struct->value.sub);
            break;

        default:
            _SET_SetError(_SET_ERRORID_DESTROYCODEVALUE_KEY, _SET_ERRORMES_VALUEKEY, Struct->type);
            break;
    }

    free(Struct);
}

void SET_DestroyCodeList(SET_CodeList *Struct)
{
    if (Struct->list != NULL)
    {
        for (SET_CodeValue **List = Struct->list, **EndList = Struct->list + Struct->count; List < EndList; ++List)
            if (*List != NULL)
                SET_DestroyCodeValue(*List);

        free(Struct->list);
    }

    free(Struct);
}

#endif