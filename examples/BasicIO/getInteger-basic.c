/***************************************************************************
 * Steven Burrows
 * sdb@cs.rmit.edu.au
 * getInteger-basic.c
 *
 * This program demonstrates a reusable function for accepting integers.
 * If you wish to use this code, you must acknowledge it for plagiarism 
 * reasons.
 *
 * Created June 2006.
 * Updated by Paul Miller December 2015.
 **************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_LENGTH 11
#define PROMPT_LENGTH 80

#define MAX_STRING_LENGTH 11
#define EXTRACHARS 2

typedef enum {FALSE, TRUE} BOOLEAN; 

void readRestOfLine(void);

/* variable names are unnecessary in the function prototype - we only need
 * the types 
 */
void getInteger(int*, const unsigned, const char*,const int, const int);

int main(void)
{
        int result = 0;
        char prompt[PROMPT_LENGTH + 1];
        int min = 1, max = 100;


        /* create the prompt that will be displayed to the user */
        sprintf(prompt, "Enter an integer (%d - %d): ", min, max);

        /* display prompt and get integer input from the user */
        getInteger(&result, INPUT_LENGTH, prompt, min, max);

        printf("You entered: '%d'\n", result);

        return EXIT_SUCCESS;
}


/****************************************************************************
 * getInteger(): An interactive integer input function.
 * This function prompts the user for an integer using a custom prompt. A 
 * line of text is accepted from the user using fgets() and stored in a 
 * temporary string. When the function detects that the user has entered 
 * too much text, an error message is given and the user is forced to 
 * reenter the input. The function also clears the extra text (if any) with 
 * the readRestOfLine() function.
 * 
 * When a valid string has been accepted, the newline character at the end 
 * of the string is overwritten as it is only there to signify that the 
 * entire input buffer has been successfully transferred. The function 
 * then attempts to convert the string into an integer with strtol(). The 
 * function checks to see if the input is numeric and within range.
 * Finally, the integer is copied to the integer pointer that is 
 * returned to the calling function.
 ****************************************************************************/
void getInteger(int* integer, const unsigned length, const char* prompt,
                const int min, const int max)
{
        int finished = FALSE;
        char output[MAX_STRING_LENGTH + EXTRACHARS];
        int int_result = 0;
        char* endPtr;

        /* Continue to interact with the user until the input is valid. */
        do
        {
                /* Provide a custom prompt. */
                printf("%s", prompt);

                /* Accept input. "+2" is for the \n and \0 characters. */
                fgets(output, length + EXTRACHARS, stdin);

                /* A string that doesn't have a newline character is
                 * too long.
                 * fgets() reads at most length+EXTRACHARS-1 characters 
                 * from the input buffer up to the newline character. If 
                 * it finds the newline character it is appended to the 
                 * string. If no newline character has been found, it 
                 * means that there is still more input in the 
                 * input buffer beyond the length specified.
                 */
                if (output[strlen(output) - 1] != '\n')
                {
                        printf("Input was too long.\n");
                        readRestOfLine();
                }
                else
                {
                        /* Overwrite the \n character with \0. */
                        output[strlen(output) - 1] = '\0';

                        /* Convert string to an integer. */
                        /* 0 in the third parameter signifies that we 
                         * will use the decimal number base which is 10. 
                         *
                         * Other options are 8 for octal and 16
                         * for hexadecimal
                         */

                        /* note there is a danger here if the user enters 
                         * a number larger than the range of an integer
                         */
                        int_result = (int) strtol(output, &endPtr, 0);

                        /* Validate integer result. */
                        if (*endPtr!=0) /* strings in C are 0 terminated */
                        {
                                printf("Input was not numeric.\n");
                        }
                        else if (int_result < min || int_result > max)
                        {
                                printf("Input was not within range "
                                        "%d - %d.\n", min, max);
                        }
                        else
                        {
                                finished = TRUE;
                        }
                }
        } while (finished == FALSE);

        /* Make the result integer available to calling function. */
        *integer = int_result;
}


/****************************************************************************
 * readRestOfLine(): A function for buffer handling.
 * This function reads remaining characters in the standard input buffer
 * up to the next newline or EOF. Source:
 * https://inside.cs.rmit.edu.au/~sdb/teaching/C-Prog/CourseDocuments/
 * FrequentlyAskedQuestions/#alternative
 ****************************************************************************/
void readRestOfLine()
{
        int c;

        /* read until the end of the line or end-of-file */   
        while ((c = fgetc(stdin)) != '\n' && c != EOF)
                ;

        /* clear the error and end-of-file flags */
        clearerr(stdin);
}
