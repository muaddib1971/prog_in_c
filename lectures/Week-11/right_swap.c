#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define WITH_MALLOC_FUNC
#define NAMELEN 7
#if 0
#define WITH_MALLOC_MACRO
#endif
/* swapping as a macro */
#define SWAP(X,Y,TYPE, LENGTH) \
{\
    /* calculate space required for copy */ \
    size_t length = sizeof(TYPE) * (LENGTH); \
    /* allocate space */ \
    void* copy=malloc(length); \
    /* do the swap */ \
    memcpy(copy, X, length );\
    memcpy(X, Y, length) ;\
    memcpy(Y, copy, length); \
    /* free the memory allocated */ \
    puts("malloc macro");\
    free(copy); \
}
/* note that LENGTH cannot be a variable */
#define SWAP2(X,Y,TYPE,LENGTH) \
{ \
    TYPE copy[LENGTH];\
    memcpy(copy, X, LENGTH);\
    memcpy(X, Y, LENGTH) ;\
    memcpy(Y, copy, LENGTH); \
    puts("no malloc macro");\
}

void swap(void*, void*, size_t, size_t);
int main(void)
{
    char fred[NAMELEN];
    char barney[NAMELEN];
    strcpy(fred, "fred");
    strcpy(barney, "barney");

#ifdef WITH_MALLOC_MACRO
    SWAP(fred,barney,char, NAMELEN);
#elif defined(WITH_MALLOC_FUNC)
    swap(fred, barney, sizeof(char), NAMELEN);
#else
    SWAP2(fred,barney,char,NAMELEN);
#endif
    printf("fred: %s\tbarney: %s\n", fred,barney);
    return EXIT_SUCCESS;
}

/* implement the generic swap as a function */
void swap(void* first, void* second, size_t size, size_t len)
{
    /* calculate the space required for copying */
    size_t allocated = size * len;
    /* allocate space */
    void * copy = malloc(allocated);
    /* perform the swap */
    memcpy(copy, first, allocated);
    memcpy(first, second, allocated);
    memcpy(second, copy, allocated);
    /* free the space used for copying */
    puts("malloc in function");
    free(copy);
}
