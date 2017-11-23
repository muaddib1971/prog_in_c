/* This program demonstrates the use of strstr() function 
 * updated by Paul Miller december 2015
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
        /* the string to search over */
        const char haystack[] = "the cat sat on the mat";
        /* the things to search for */
        const char * needles[] = { "cat", "sat", "fred", "on the", NULL };
        /* NULL on a search failure and otherwise points to the location 
         * in the string where the needle starts 
         */
        char * result;
        int i;

        /* iterate over the needles */
        for(i=0; target[i] != NULL; i++)
        {
                /* search for the needle */
                result = strstr(source, target[i]);
                if (result) /* implied != NULL */
                {
                        printf("\"%s\" found starting at \"%s\"\n", 
                                        target[i], result);
                }
                else
                {
                        printf("\"%s\" not found in \"%s\"\n", 
                                        target[i], source);
                }
        }

        return EXIT_SUCCESS;
}
