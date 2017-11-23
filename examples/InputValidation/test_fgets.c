/***************************************************************************
 * Steven Burrows
 * sdb@cs.rmit.edu.au
 * 
 * test_fgets.c
 * Diagnostic program for playing with fgets().
 * This program accepts a string of up to 5 characters from the user.
 * This program also addresses the buffer overflow problem by rejecting
 * strings that contain 6 or more characters.
 * Challenge:Try to modularise the code in the do-while loop so you can call
 * a function every time you need to accept user input rather than just
 * cutting and pasting the code.
 * If you wish to use this code, you must acknowledge it for plagiarism 
 * reasons.
 *
 * Created July 2004.
 * updated December 2015 by Paul Miller
 ***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5
typedef enum {FALSE, TRUE} BOOLEAN;
#define EXTRACHARS 2

void readRestOfLine();

int main(void)
{
        char myString[SIZE + EXTRACHARS];  
        int finished = FALSE;
        int i;

        /* Continue to accept input from the user until a string of no 
         * greater than SIZE characters is entered. */
        do 
        {
                /* User prompt. */
                printf("\nEnter some text (1-5 characters): ");

                /* Accept a line of text. */
                /* Question: Why have I used a "+2" here? */
                fgets(myString, SIZE + 2, stdin);

                /* Is there a '\n' character in the string? Because if 
                 * there is, we want to get rid of it. fgets() leaves the 
                 * '\n' character in the string unless there isn't enough 
                 * room to store it. */
                if (myString[strlen(myString) - 1] != '\n')
                {
                        /* String was too long. Reject string and 
                         * flush input buffer. */
                        printf("Input was too long.\n");
                        readRestOfLine();
                }
                else
                {
                        /* String length was ok. Remove the '\n' 
                         * character. */
                        myString[strlen(myString) - 1] = '\0';
                        finished = TRUE;
                }
        } while (!finished); 

        /* The remainder of this program just displays diagnostic 
         * information. This can be helpful when debugging. This 
         * information outputs the string, each character in the array, 
         * and the length of the string. */

        printf("\nDebugging information:\n");

        printf("\nYou entered: '%s'\n\n", myString);

        for (i = 0; i < SIZE + 2; i++)
        {
                if (myString[i] == '\n')
                        printf("myString: '\\n' found at array index %d\n",
                        i);
                else if (myString[i] == '\0')
                        printf("myString: '\\0' found at array index %d\n",
                        i);
                else if (myString[i] == '\r')
                        printf("myString: '\\r' found at array index %d\n",
                        i);
                else
                        printf("myString: '%c' found at array index %d\n", 
                        myString[i], i);
        }

        printf("\nLength of string: %lu characters\n\n", strlen(myString));

        return EXIT_SUCCESS;
}

/* readRestOfLine(): read remaining characters in the standard 
 * input buffer up to the next newline or EOF. */
void readRestOfLine()
{
        int c;

        /* read until the end of the line or end-of-file */   
        while ((c = fgetc(stdin)) != '\n' && c != EOF)
                ;

        /* clear the error and end-of-file flags */
        clearerr(stdin);
}

