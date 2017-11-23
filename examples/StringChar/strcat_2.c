/* This program demonstrates the use of strcat() function 
 * updated by Paul Miller December 2015
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TEXT 10

int main(void) 
{
        char text1[MAX_TEXT] = "Hello";   
        char text2[MAX_TEXT] = "World";

        printf("\n Original Text1 = (%s) \n Original Text2 = (%s)\n", 
                        text1, text2);

        /** The strcat() function below, takes two strings as arguments and 
         *  concatenates/joins them together. The concatenated string is 
         *  pointed to by the first (text1) string parameter.
         *  But before concatenating the strings, it is a good practise to
         *  ensure that there is enough space allocated for the 
         *  destination string (text1 in this case) to hold the total chars
         *  of the concanetated string.
         *
         *  If you do not do this, you risk memory corruption.
         **/

        if( (strlen(text1) + strlen(text2) ) < MAX_TEXT ) 
        {
                strcat(text1, text2);
        }
        else 
        {
                printf("\n Cannot concatenate text1 (%s) and text2 (%s)\n",
                                text1, text2);
        }

        printf("\n Text1 after strcat() = (%s)", text1);
        printf("\n Text2 after strcat() = (%s)\n\n", text2);

        return EXIT_SUCCESS;
}

