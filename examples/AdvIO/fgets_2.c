/* This program accepts the data from the standard input using fgets().
 * Read the fgets manual page (man fgets) before reading this.
 * updated by Paul Miller December 2015.
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_TEXT 5
/* last two characters appended by fgets to a string - \n\0 */
#define EXTRACHARS 2

int main(void)
{
        char text[MAX_TEXT + EXTRACHARS];
        int len;

        printf("\n Enter a text of Maximum %d characters "
               "before pressing enter / return: ",
               MAX_TEXT);

        /* Always check the return value of fgets */
        if (fgets(text, MAX_TEXT + EXTRACHARS, stdin) == NULL)
        {
                printf(
                    "\nEOF at beginning of input - no data has been stored.\n");
                return (EXIT_SUCCESS);
        }
        len = strlen(text);

        /** Check if the character before nul is a newline character; if it is
         * a newline character , then replace it with a nul character. If it
         * is not a newline character then the user must have attempted to
         * enter more the maximum limit (MAX_LIMIT-2) of the character.
         *
         * Read fgets_pitfalls.txt for further explanation.
         * */
        if (text[len - 1] == '\n')
        {
                /* remove the newline as it is only there to indicate that we
                 * got
                 * all the data we were supposed to. For this reason, we also
                 * subtract 1 from the length as the newline is counted in the
                 * length.
                 */
                text[len - 1] = '\0';
        }
        else
        {
                printf("\nMore than %d characters entered", MAX_TEXT);
                printf(
                    "\nAccept only %d characters (including the newline\n"
                    "character and excess chars have not been retrieved from\n"
                    " the input buffer.\n",
                    MAX_TEXT + EXTRACHARS - 1);
                return EXIT_FAILURE;
        }
        printf("\nThe length of the text (%s) entered is %d, not counting\n"
               "the newline (\\n) character.\n",
               text, len);
        return EXIT_SUCCESS;
}
