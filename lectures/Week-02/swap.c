#include <stdio.h>
#include <stdlib.h>
/* here is a common problem we have - we want to write a function to swap 
 * two numbers. We can't just use wrong_swap as the parameters passed 
 * into a function are copies of the parameters passed in via the 
 * function call. Because of that we need to pass in the memory addresses
 * of the parameters - and then swap by directly writing to the memory 
 * addresses. Compare the functions and play with them yourself.
 */
void swap(int*,int*);
void wrong_swap(int,int);
int main(void)
{
    /* declare the variables */
    int a=3,b=5;
    /* swap the variables */
    swap(&a,&b);
    /* the variables in main are output */
    printf("%d,%d\n", a,b);
    return EXIT_SUCCESS;
}

/* incorrect swap - only the local values are swapped */
void wrong_swap(int first, int second)
{
    int swapper = first;
    first = second;
    second = swapper;
    printf("in function: %d %d\n", first, second);
}

/* correct swap - we are swapping the values in the actual memory 
 * addresses directly 
 */
void swap(int * first, int * second)
{
    int swapper = *first;
    *first = *second;
    *second = swapper;
    printf("in function: %d %d\n", *first, *second);
    printf("first and second are memory addresses: "
        "first: %p, second: %p\n\n", (void*)first, (void*)second);
    *second=-42;
    second=NULL;
}

/* 
 * &f = take the address of `f'.
 * *f = give me the contents of `f'.
 */
