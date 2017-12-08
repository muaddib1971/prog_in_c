#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* updated by Paul Miller December 2015 */
#define MAX_TEXT 1024

int main(void) 
{
        char text[MAX_TEXT];

        printf("\nEnter up to %d characters, press enter to end:\n", 
                        MAX_TEXT);

        if (fgets(text, MAX_TEXT, stdin) != NULL)  
        {
                /* note that this counts the newline character as 
                 * part of the length of the string 
                 */
                printf("\nYou entered %d characters\n", strlen(text));
        }
        else  
        {
                printf("\nNo input was fetched\n");
        }
        return EXIT_SUCCESS;
}

/*
 * Notes:
 * 
 * 1. strlen() expects a nul-terminated string, and returns an count
 *    of the number of characters that preceed the nul-termiantor.
 *
 * 2. recall that fgets() will fetch the newline where possible
 */
