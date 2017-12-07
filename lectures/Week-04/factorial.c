#include <stdio.h>
#include <stdlib.h>
int fact(int n);
#define MAXFACT 10
int main(void)
{
    unsigned num;
    unsigned count;

    /* loop to generate the first MAXFACT factorial numbers */
    for(count=0; count <= MAXFACT; ++count)
    {
        num = fact(count);
        printf("the factorial of %d is %d\n", count, num);
    }
    return EXIT_SUCCESS;
}

/*******************************************************************
 * recursive function that calculates the factorial for a number
 * where the factorial of N is N * N-1 * N-2, until N-n == 1
 ******************************************************************/
int fact(int n)
{
    /* the base case return 1 for any number <= 1 */
    if(n<=1)
    {
        return 1;
    }
    else
    {
        /* recursive call */
        int result = n*fact(n-1);
        return result;
    }
}
