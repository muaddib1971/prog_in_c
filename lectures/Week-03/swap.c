#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
        int temp = *b;
        *b=*a;
        *a=temp;
}

int main(void)
{
        int a=3,b=5;
        swap(&a,&b);
        printf("%d %d\n", a,b);
        return EXIT_SUCCESS;
}
