/** Demonstrate the use of memset() function in string.h header file **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 10

int main(void) 
{
        char src[MAX_STR] = "AAAAAAAAA";
        unsigned char ch = 'a';
        int n =4;

        printf("\nBefore memset() src = \"%s\"", src);

        /** 
         * memset() copies 'ch' into the first 'n' bytes of 'dest'. 
         * The pointer to the destination is returned.
         **/
        memset(src, ch, n);

        printf("\nAfter memset() src = \"%s\"\n\n", src);
        return EXIT_SUCCESS;
}
