#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char ch;
    for(ch = 'a'; ch <= 'z'; ++ch)
    {
        printf("%c, ", ch);
        printf("%d\n", ch);
    }
    return EXIT_SUCCESS;
}
