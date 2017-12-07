#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMCHARS 4
int main(void)
{
        unsigned i = 3;
        char chars[NUMCHARS];
        memset(chars, 0, NUMCHARS);
        printf("%d\n", chars[i]);
        return EXIT_SUCCESS;
}
