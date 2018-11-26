#include "helpers.h"
enum input_result get_string(const char prompt[], char output[], 
                size_t len)
{
        printf(prompt);

        if(!fgets(output, len + EXTRACHARS, stdin) 
                || *output == '\n')
        {
                return RTM;
        }
        if(output[strlen(output) -1 ] != '\n')
        {
                fprintf(stderr, "Error: line was too long. Please "
                                "try again.\n");
                return FALSE;
        }
        output[strlen(output)-1]=0;
        return TRUE;
}
