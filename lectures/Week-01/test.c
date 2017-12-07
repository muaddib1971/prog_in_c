#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i = 6.5;
    int a, b=5,c=5;
    /* what is the type of i? why doesn't this cause a compiler 
     * warning? 
     */
    printf("%d\n", i);
    /* what is the value in a? is it possible the programmer 
     * meant something different? 
     */
    a=b==c;
    printf("%d\n", a);
    return EXIT_SUCCESS;
}
