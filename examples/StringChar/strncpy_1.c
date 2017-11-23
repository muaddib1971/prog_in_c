/* This program demonstrates the use of strncpy() function 
 * updated by Paul Miller December 2015 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TEXT 20

int main(void) 
{
        /* Initialisation of the array to be empty */
        char text1[MAX_TEXT] = "";           
        char text2[MAX_TEXT] = "World";

        printf("\n Original Text1 = (%s) \n Original Text2 = (%s)\n", 
        text1, text2);

        /** The strncpy() function below, copies the first 3 characters of 
         * the text2 into text1. ie. the first 3 characters of text1 are 
         * *overwritten* by the first 3 characters of text2.
         **/
        strncpy(text1, text2, 3);
        /* important to note that if the nul terminator is not one of the 
         * characters copied, the destination may not be nul terminated 
         * and this is something you may need to take care of yourself
         */
        printf("\n Text1 after strncpy() = (%s)", text1);
        printf("\n Text2 after strncpy() = (%s)\n\n", text2);

        return EXIT_SUCCESS;
}
