#include<stdio.h>
#include<stdlib.h>

void change_ptr(int * const );

int main(void)
{
    int var1 = 0, var2 = 0;
    /* the ptr is const, not the data */
    int * const  ptr = &var1;
    /* ptr = &var2; */
    change_ptr(&var1);
    printf("%d\n", *ptr);

    return EXIT_SUCCESS;
}
void change_ptr(int * const ptr)
{
    *ptr=42;
}
