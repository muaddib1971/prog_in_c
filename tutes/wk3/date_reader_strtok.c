#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define LINELEN 80
#define EXTRACHARS 2
#define DECIMAL 10


typedef enum{
    FALSE, TRUE
} BOOLEAN;

BOOLEAN strtoint(const char*, int*);

void read_rest_of_line(void)
{
    int ch;
    while(ch = getc(stdin), ch != '\n' && ch != EOF)
        ;
    clearerr(stdin);
}

#define DELIMS "/"

enum date_part{
    /* 0      1      2          3 */
    DP_DAY, DP_MON, DP_YEAR, DP_NUM_PARTS
};

int main(void)
{
    char line[LINELEN + EXTRACHARS];
    int day, month, year;
    char * tok;
    enum date_part part = DP_DAY;

    printf("please enter a date as dd/mm/yy: ");
    fgets(line, LINELEN + EXTRACHARS, stdin);
    if(line[strlen(line)-1] != '\n')
    {
        printf("line was too long\n");
        read_rest_of_line();
        return EXIT_FAILURE;
    }
    /* validate it is a valid date */
    tok = strtok(line, DELIMS);
    while(part < DP_NUM_PARTS && tok)
    {
        switch(part)
        {
            case DP_DAY:
                /* integer conversion */
                if(!strtoint(tok, &day))
                {
                    return EXIT_FAILURE;
                }
                break;
            case DP_MON:
                /* integer conversion */
                if(!strtoint(tok, &month))
                {
                    return EXIT_FAILURE;
                }
                break;
            case DP_YEAR:
                /* integer conversion */
                if(!strtoint(tok, &year))
                {
                    return EXIT_FAILURE;
                }
                break;
            default:
                printf("error: we should never get here.\n");
        }
        ++ part;
        /* strtok is not reentrant 
         * pass in NULL -> use the stored pointer
         */
        tok = strtok(NULL, DELIMS);
    }
    printf("Day: %d, Month: %d, year %d\n", day, month, year);
    return EXIT_SUCCESS;
}


BOOLEAN strtoint(const char * input, int * output)
{
    char * end;
    long result;

    result = strtol(input, &end, DECIMAL);
    while(isspace(*end))
    {
        ++end;
    }
    if(*end != '\0')
    {
        printf("Error: invalid integer string.\n");
        return FALSE;
    }
    if(result < INT_MIN || result > INT_MAX)
    {
        printf("Error: number out of range for an int.\n");
        return FALSE;
    }
    *output = result;
    return TRUE;
}

#if 0
int atoi(const char * str)
{
    return (int)strtol(str,NULL, 10);
}

#endif
