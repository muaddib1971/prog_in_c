/***************************************************************************
 * Steven Burrows
 * sdb@cs.rmit.edu.au
 * with modifications by Paul Miller: Paul.Miller@rmit.edu.au
 * getInteger-advanced.c
 *
 * This program demonstrates a reusable function for accepting integers 
 * using dynamic memory allocation.
 * If you wish to use this code, you must acknowledge it for plagiarism 
 * reasons.
 *
 * Created June 2006, last modified December 2015.
 *************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define INPUT_LENGTH 11
#define PROMPT_LENGTH 80

/* two chars at the end of a valid string from fgets: 
 * the newline (\n) and (\0). If the newline is missing then there is still
 * input left in the buffer.
 */
#define EXTRACHARS 2
/* definition of the boolean type */
typedef enum {FALSE, TRUE} BOOLEAN;

void readRestOfLine(void);
BOOLEAN getInteger(int*, const unsigned, const char*, const int, const int);

int main(void)
{
        int result = 0;
        char prompt[PROMPT_LENGTH + EXTRACHARS];
        /* the range of numbers that will be accepted */
        int min = 1, max = 100;

        /* prompt the user for a number within the allowed range */
        sprintf(prompt, "Enter an integer (%d - %d): ", min, max);
        if(!getInteger(&result, INPUT_LENGTH, prompt, min, max))
        {
                fprintf(stderr, "Error: the was a problem with the number"
                        " you entered.");
                return EXIT_FAILURE;
        }
        printf("You entered: '%d'\n", result);

        return EXIT_SUCCESS;
}


/****************************************************************************
 * getInteger(): An interactive integer input function using dynamic memory.
 * This function prompts the user for an integer using a custom prompt. A line
 * of text is accepted from the user using fgets() and stored in a temporary
 * string. When the function detects that the user has entered too much text,
 * an error message is given and the user is forced to reenter the input. The
 * function also clears the extra text (if any) with the readRestOfLine()
 * function.
 * When a valid string has been accepted, the unnecessary newline character
 * at the end of the string is overwritten. The function then attempts to 
 * convert the string into an integer with strtol(). The function checks to
 * see if the input is numberic and within range.
 * Finally, the temporary integer is copied to the integer variable that is 
 * returned to the calling function.
 ****************************************************************************/
BOOLEAN getInteger(int* integer, const char* prompt, const int min, const int max)
{
                /* the maximum length of a string to hold an integer */
#define MAXINTLEN 10
        BOOLEAN finished = FALSE;
        char input[MAXINTLEN + EXTRACHARS];
        long long_result;
        int int_result = 0;
        /* a pointer to the next character after what has been successfully
         * processed
         */
        char* end;

        /* Continue to interact with the user until the input is valid. */
        do
        {
                /* Provide a custom prompt. */
                printf("%s", prompt);

                /* Accept input. "EXTRACHARS" is for the \n and \0 
                 * characters. */
                fgets(input, MAXINTLEN + EXTRACHARS, stdin);

                /* A string that doesn't have a newline character is too 
                 * long (has leftover input in the buffer). */
                if (input[strlen(input) - 1] != '\n')
                {
                        printf("Input was too long.\n");
                        readRestOfLine();
                }
                else
                {
                        /* Overwrite the \n character with \0 as we now 
                         * know we have gotten all the data from the buffer
                         */
                        input[strlen(input) - 1] = '\0';
                        /* Convert string to an integer. */
                        long_result = strtol(input, &end, 10);
                        /* Validate integer result. */
                        if (*end=='\0')
                        {
                                /* there were leftover characters that were
                                 * no processed so it was not a valid
                                 * integer
                                 */
                                fprintf(stderr, "Input was not numeric.\n");
                                continue;
                        }
                        /* validate the range of the integer */
                        if (long_result < min || long_result > max)
                        {
                                printf("Input was not within"
                                        " range %d - %d.\n", min, max);
                        }
                        else
                        {
                                /* all good so assign the value to its 
                                 * integer variable 
                                 */
                                int_result = long_result;
                                finished = TRUE;
                        }
                }
        } while (finished == FALSE);

        /* Make the result integer available to calling function. */
        *integer = int_result;

        return TRUE;
}


/***************************************************************************
 * readRestOfLine(): A function for buffer handling.
 * This function reads remaining characters in the standard input buffer
 * up to the next newline or EOF. Source:
 * https://inside.cs.rmit.edu.au/~sdb/teaching/C-Prog/CourseDocuments/
 * FrequentlyAskedQuestions/#alternative
 **************************************************************************/
void readRestOfLine()
{
        int c;

        /* read until the end of the line or end-of-file */   
        while ((c = fgetc(stdin)) != '\n' && c != EOF)
                ;

        /* clear the error and end-of-file flags */
        clearerr(stdin);
}
