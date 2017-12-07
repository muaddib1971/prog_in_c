#include <stdio.h>
#include <stdlib.h>
int * doit(void);
int main(void)
{
    /* retrieve pointer to static variable */
    int * a = doit();
    int * b = doit();
    int *c;

    /* notice that both pointers hold the same address!!!!! */
    printf("memory addresses of a : %p and b: %p\n\n", (void*)a, (void*)b);
    printf("values of a : %d and b: %d\n\n", *a, *b);

    /* we can even change the value of i outside the function !!!!*/
    *a=-10;
    c=doit();
    printf("%d\n", *b);
    return EXIT_SUCCESS;
}

int * doit(void)
{
    static int i=0;
    if(i<0)
    {
        fprintf(stderr, "Error: int out of range: %d\n\n", i);
        return NULL;
    }
    ++i;
    return &i;
}
