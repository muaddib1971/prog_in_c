#include <stdio.h>
#include <stdlib.h>
/* this counter program emphasises two principles - that of pass by 
 * reference and the use of a library
 */ 

/* here we are including a header file for a library we will create to 
 * keep track of a counter variable
 */
#include "counterlib.h"
int main(void)
{
    /* we declare a counting variable here but we don't initialise it 
     * as it will be initialised the first time we call the counter() 
     * function 
     */
    unsigned count;
    do
    {
        /* we get the value of the next counter note that this is what 
         * we call pass by reference - counter() will write into the 
         * memory address of count as that is the meaning of the parameter
         * we are passing in (&count). This is also called an out-parameter
         * as the value in count is irrelevant - we are passing in a 
         * memory address as a way to return a value
         */
        counter(&count);
        printf("%u\t", count);
        /* we want a newline after every 10 numbers */
        if(count % 10 == 0)
            putchar('\n');
      /* when count is >= 50 we exit this loop */
    } while(count < 50);
    return EXIT_SUCCESS;
}
