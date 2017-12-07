#include <stdio.h>
#include <stdlib.h>
/* This file is a iterative implementation of a program to find the 
 * factorial of a number
 */
int fact(int n);
#define MAXFACT 10
int main(void)
{
    unsigned num;
    unsigned count;

    /* calculate the factorials up to MAXFACT */
    for(count=0; count <= MAXFACT; ++count)
    {
        num = fact(count);
        printf("the factorial of %d is %d\n", count, num);
    }
    return EXIT_SUCCESS;
}
/**************************************************************************
 * Iterative implemenation of calculating the factorial of a number - 
 * this is the real difference in comparison to the recursive 
 * implementation.
 *************************************************************************/
int fact(int n)
{
    int result=1;
    unsigned count;
    /* iterate over all the numbers up to and including n and multiply 
     * them together */
    for(count = 1; count <= n; ++count)
    {
        result *= count;
    }
    return result;
}
