#include <stdio.h>
#include <stdlib.h>
#include <time.h>
unsigned int fibo(unsigned int);
#define MAXFIBO 45
int main(void)
{
    unsigned result;
    unsigned count;
    /* we are going to time how long it takes to generate the whole 
     * fibonacci sequence
     */
    time_t start = time(NULL), end;

    /* print out the first N fibonacci numbers */
    for(count=0; count < MAXFIBO; ++count)
    {
        result = fibo(count);
        printf("fibonacci number %d is %d\n", count+1, result);
    }
    end = time(NULL);
    /* print out the time */
    printf("this whole process took %f seconds\n", difftime(end,start));
    return EXIT_SUCCESS;
}

/* recursive implementation of calculating fibonacci numbers */
unsigned int fibo(unsigned int num)
{
    /* 0 and 1 are the base cases */
    if(num <= 0)
    {
        return 0;
    }
    if(num == 1)
    {
        return 1;
    }
    /* recursive call to calculate the fibonacci sequence */
    return fibo(num-1) + fibo(num-2);
    /* 0, 1, 1, 2, 3, 5, 8, 13, 21 */
    /* 2 ^ n recursive calls */
}
