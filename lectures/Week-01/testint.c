#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    /* why is there no compiler warning? What does -3U evaluate to? */
    unsigned i = -3U;
    printf("%u\n", i);
    return EXIT_SUCCESS;
}
