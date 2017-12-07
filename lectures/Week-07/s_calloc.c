#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "safemalloc.h"
#define NUMINTS 10

int main(void)
{
    unsigned count; 
    int * array = (int*)safecalloc(NUMINTS, sizeof(int));
    srand(time(NULL));
    for(count = 0; count < NUMINTS; ++count)
    {
        array[count]=rand();
    }
    for(count = 0; count < NUMINTS; ++count)
    {
        printf("%d\t", array[count]);
    }
    putchar('\n');
    free(array);
    return EXIT_SUCCESS;
}
