#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIMS ", "
/* 3, 4, 5,, 7, 99,,,,4,5,7 */
#define LINE_LEN 80
#define EXTRA_SPACES 2

int main(void)
{
    char line[LINE_LEN + EXTRA_SPACES];
    char * tok;
    printf("Please enter a line of numbers to tokenize, separated "
        "by commas or spaces: ");
    /* get user input - test that the user entered something */
    if(fgets(line, LINE_LEN + EXTRA_SPACES, stdin) == NULL)
    {
        printf("Error: no data entered.\n\n");
        return EXIT_FAILURE;
    }
    /* check that there was no buffer overflow */
    if(line[strlen(line)-1]!='\n')
    {
        printf("Error: too much data entered.\n\n");
        return EXIT_FAILURE;
    }
    /* remove newline */
    line[strlen(line)-1]=0;

    /* grab the first token */
    tok = strtok(line, DELIMS);
    while(tok!=NULL)
    {
        int num;
        long lnum;
        char * end;
        /* extract the number and validate it is numeric */
        lnum = strtol(tok, &end, 0);
        if(lnum <= INT_MAX && lnum >= INT_MIN)
        {
                num = lnum;
        }
        else
        {
                printf("Error: number out of range.\n");
                return EXIT_FAILURE;
        }
        if(*end)
        {
            printf("Error: there is some non-numeric data.\n\n");
            return EXIT_FAILURE;
        }
        /* output the data */
        printf("%d is the next number\n\n", num);
        /* get every other token. note that as strtok keeps a pointer to 
         * and modifies the char array, you will not be able to use the 
         * unmodified char array for any purpose after this process.
         * If this is important to you, make a copy first */
        tok = strtok(NULL, DELIMS);
    }
    return EXIT_SUCCESS;
}

