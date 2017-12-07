#include <stdio.h>

void read_rest_of_line(void)
{
    int ch;
    while(ch=getchar(), ch!=EOF&&ch!='\n');
    clearerr(stdin);
}
