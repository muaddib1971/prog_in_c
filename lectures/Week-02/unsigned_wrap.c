#include <stdio.h>
#include <stdlib.h>

/* This program shows that if you use an unsigned and it goes below 0
 * it will wrap around to the top of the number range , so be careful.*/
int main(void)
{
    unsigned a = 0;
    a--;
    printf("%u\n", a);
    return EXIT_SUCCESS;
}
