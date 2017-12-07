#include <stdio.h>
#include <stdlib.h>
int cmp(int, int);
/* stdarg.h */
int main(void)
{
    int (*bcmp)(int,int)=cmp;
    int i;
    i = bcmp(5,3);
    printf("%d\n", i);
    return EXIT_FAILURE;
}

int cmp(int a, int b)
{
    return a-b;
}
