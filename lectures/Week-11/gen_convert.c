#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printnum(void *);
int main(void)
{
    /* create an int on the stack */
    int i = 50;
    /* pass in an int pointer to printnum */
    printnum(&i);
    /* print out the altered data from printnum() */
    printf("%d\n", i);
    putchar('\n');
    return EXIT_SUCCESS;
}

void printnum(void * numptr)
{
    /* cast to a double * !! it was an int * in main() but there are no
     * warnings!! */
     /* it prints out 0.00000 because it is treating the data as if it is in 
      * floating point format
      */
    printf("%g\n", *((double*)numptr));
    /* it even lets us assign to the memory space and when we print out the 
     * value in here, there is no problem 
     */
    memset(numptr, 0, sizeof(double));
    *((double*)numptr)=150.5;
    printf("%g\n", *((double*)numptr));
}

