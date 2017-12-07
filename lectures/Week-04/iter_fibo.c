#include <stdio.h>
#include <stdlib.h>
unsigned int fibo(unsigned int);
#define MAXFIBO 45
int main(void)
{
    unsigned result;
    unsigned count;

    /* print out the first N fibonacci numbers */
    for(count=0; count < MAXFIBO; ++count)
    {
        result = fibo(count+1);
        printf("fibonacci number %d is %d\n", count+1, result);
    }
    return EXIT_SUCCESS;
}

/**************************************************************************
 * iterative implementation of calculating fibonacci numbers. This is far
 * more efficient in terms of time
 *************************************************************************/
unsigned int fibo(unsigned int num)
{
    unsigned count;
    unsigned first=0, second=1, next;
    for(count=0; count < num; ++count)
    {
        /* what we can see here is that the algorithm to calculate the 
         * fibonacci number is a bit more complex using an iterative
         * algorithm. We start with the numbers 0 and 1 and each new 
         * number is the sum of the previous two numbers.
         */
        if(count<=1)
        {
            next=count;
        }
        else
        {
            next = first + second;
            first = second;
            second = next;
        }
    }
    return next;
}
