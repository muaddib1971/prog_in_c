#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SWAP(X,Y,SIZE) \
{\
    void * copy=malloc(SIZE); \
    memmove(copy, X, SIZE); \
    memmove(X, Y, SIZE); \
    memmove(Y, copy, SIZE); \
    free(copy); \
}

int main(void)
{
    char fred[7];
    char barney[7];
    strcpy(fred, "fred");
    strcpy(barney, "barney");
    SWAP(fred,barney,sizeof(char) * 7);
    printf("fred: %s\tbarney: %s\n", fred,barney);
    return EXIT_SUCCESS;
}
