#include <stdio.h>
#include <stdlib.h>

#define EVEN 2
#define ARRAYSIZE 10

int main(void)
{
    int array[] = {1,2,3,4,5,6,7,8,9,10};
    int count;
    for(count = 0; count < ARRAYSIZE; ++count)
    {
        /* if the index is even, skip this iteration */
        if(count % EVEN == 0)
        {
            continue;
        }
        printf("%d\n", array[count]);
    }
    return EXIT_SUCCESS;
}
