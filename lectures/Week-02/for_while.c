#include <stdio.h>
#include <stdlib.h>

/* here we have two examples of an infinite loop. If you examine the
 * logic you will see they are the same - the second loop would be
 * terminated by changing i to some number other than 5.
 */

int main(void)
{
        int i = 5;
        /*
        while(1)
        {
            printf("loop\n");
        }
        */
        for (i = 0; i < 5; ++i)
        {
                printf("another loop\n");
        }
        return EXIT_SUCCESS;
}
