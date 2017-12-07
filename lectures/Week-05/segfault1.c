#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    /* segmentation fault caused by an uninitialised pointer - p could 
     * be pointing anywhere but most likely not somewhere you are 
     * allowed to access
     */
    int * p;
    printf("%d\n", *p);
    return EXIT_SUCCESS;
}
