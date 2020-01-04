#include "io.h"

BOOLEAN get_int(const char prompt[], int* output)
{
        char line[LINELEN + EXTRACHARS];
        long result;
        char* end;
        char* inresult;
        printf("%s: ", prompt);
        inresult = fgets(line, LINELEN + EXTRACHARS, stdin);
        if (!inresult || line[strlen(line) - 1] != '\n')
        {
                return FALSE;
        }
        line[strlen(line) - 1] = 0;
#if 0 
            NULL; /* (void*) 0 */
#endif
        result = strtol(line, &end, 10);
        /*
        input ="12a", end "a" "12        " end "        " "12" end ""
        */
        while (isspace(*end))
        {
                ++end;
        }
        if (*end)
        {
                fprintf(stderr, "Error: input was not numeric.\n");
                return FALSE;
        }
        if (result < INT_MIN || result > INT_MAX)
        {
                fprintf(stderr, "Error: number out of the range of an int.\n");
                return FALSE;
        }
        *output = result;
        return TRUE;
}

static void read_rest_of_line()
{
}
