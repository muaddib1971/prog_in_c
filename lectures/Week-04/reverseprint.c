#include <stdio.h>
#include <stdlib.h>

void print(char * s);
int main(void)
{
    print("hello\n");
    putchar('\n');
    return EXIT_SUCCESS;
}

void print(char * s)
{
    /* base case - we have gotten to the end of the string */
    if(*s == '\0')
    {
        return;
    }
    /* recursive call */
    print(s+1);
    /* because the recursive call comes before the output, 
     * the output will be printed backwards */
    putchar(*s);
}
