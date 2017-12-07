#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SWAP(X,Y,TYPE) \
{\
    TYPE * copy=malloc(sizeof(TYPE)); \
    *copy = *(X); \
    *(X)=*(Y);\
    *(Y)=*copy;\
    free(copy); \
}

int main(void)
{
    char fred[7];
    char barney[7];
    strcpy(fred, "fred");
    strcpy(barney, "barney");
    SWAP(fred,barney,char);
    printf("fred: %s\tbarney: %s\n", fred,barney);
    return EXIT_SUCCESS;
}
