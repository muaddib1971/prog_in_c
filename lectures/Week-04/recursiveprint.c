#include <stdio.h>
#include <stdlib.h>

void print(char * s);
int main(void)
{
    print("hello\n");
    return EXIT_SUCCESS;
}

void print(char * s)
{
    if(*s == '\0')
    {
        return;
    }
    /* tail recursion */
    print(s+1);
    putchar(*s);
}
