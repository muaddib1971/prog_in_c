#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    const char * s = "hello";
    char * t = s;
    printf("%s\n", s);
    printf("%s\n", t);
    return EXIT_SUCCESS;
}
