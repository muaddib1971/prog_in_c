/* 
 * This program demonstrates the use of toupper() and tolower() 
 * from the standard C library (ctype)
 * updated by Paul Miller December 2015
 */

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_TEXT 16

int main(void) 
{
        char text[MAX_TEXT] = "Hello World";
        int i;

        printf("\nThe Original text = %s", text);

        for(i=0; text[i]; i++) 
        {
                /* changes all lower case characters to upper case
                 * and vice-versa
                 */
                if(isupper( text[i]) )
                {
                        text[i] = tolower(text[i]);
                }
                else 
                {
                        text[i] = toupper(text[i]);
                }
        }
        printf("\nThe Converted text: %s \n", text);

        return EXIT_SUCCESS;
}      
