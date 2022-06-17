#include <stdio.h>
#include <Files.h>
#include "Settings.h"

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

    printf("Original string: %s\n\nCleaned String: %s\n", Settings, CleanString);

    free(Settings);
    free(CleanString);

    return 0;
}