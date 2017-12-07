#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char string[1]="abcdefghijklmnopqrstuvwxyz";
    unsigned count;

    puts(string);
    printf("the size of string is: %lu\n", sizeof(string));
    for (count = 0; count < strlen(string)+1; count++)
    {
        printf("%d\t", string[count]);
    }
    return EXIT_SUCCESS;
}
