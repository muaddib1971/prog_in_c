#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char name[42];
    strcpy(name, "hello");
    printf("%s\n", name);
    return EXIT_SUCCESS;
}
