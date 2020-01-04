#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define NDEBUG

char* mystrcpy(char* dup, const char orig[]) {
    char* dupiter, *origiter;
    assert(dup != NULL); /* <-- if these are EVER not TRUE, there has been a
                            programming error */
    assert(orig != NULL);
    /* assertion failed: orig != NULL */
    while (*dupiter++ = *origiter++)
        ;
    return dup;
}

int main(void) { return EXIT_SUCCESS; }
