#include "for_each_int.h"
int main(void)
{
    int val;
    int nums[TOTAL_NUMS];
    
    /* fill the array with random numbers and print it */
    fill_array(nums, TOTAL_NUMS);
    print_array(nums, TOTAL_NUMS);
    
    /* add a value to each element of the array */
    val = rand()%MAX_NUM;
    printf("adding %d\n", val);
    for_each(nums, val, TOTAL_NUMS, add);
    print_array(nums, TOTAL_NUMS);

    /* subtract a value from each element in the array */
    val = rand()%MAX_NUM;
    printf("subtracting %d\n", val);
    for_each(nums, val, TOTAL_NUMS, sub);
    print_array(nums, TOTAL_NUMS);

    /* multiply each array element by a randomly generated number */
    val = rand() % MAX_NUM;
    printf("multiplying %d\n", val);
    for_each(nums, val, TOTAL_NUMS, mult);
    print_array(nums, TOTAL_NUMS);

    /* divide all elements of the array by a randomly generated number */
    val = rand() % MAX_NUM;
    printf("dividing %d\n", val);
    for_each(nums, val, TOTAL_NUMS, divide);
    print_array(nums, TOTAL_NUMS);
    return EXIT_SUCCESS;
}

/**************************************************************************
 * fill an array with random integers
 *************************************************************************/
void fill_array(int* array, size_t i_count)
{
    unsigned count;
    srand(time(NULL));
    for(count = 0; count < i_count; ++count)
    {
        array[count]=rand()%MAX_NUM;
    }
}

/**************************************************************************
 * print out the first i_count numbers in the int array nums.
 **************************************************************************/
void print_array(int * nums, size_t i_count)
{
    unsigned count;
    for(count = 0; count < i_count; ++count)
    {
        printf("%d\t", nums[count]);
        if((count+1) % WIDTH == 0)
            putchar('\n');
    }
}

/**************************************************************************
 * a for_each() function that iterates over an array of ints. 
 *
 * nums is the array of ints.
 * val is the number to combine with each value in the array and doit is a
 * function pointer which points to a function that defines how to combine
 * val with each array element (add or subtract are possible functions that 
 * might be passed in here.
 *
 * finally, i_count is the number of integers contained in the nums array.
 **************************************************************************/
void for_each(int * nums, int val, size_t i_count, int(*doit)(const int,const int))
{
    unsigned count;

    /* iterate over the array */
    for(count = 0; count < i_count; ++count)
    {
        /* modify each element according to how doit is defined */
        nums[count] = doit(nums[count],val);
    }
}

/**************************************************************************
 * function that defines how to add two ints
 **************************************************************************/
int add(int first,int second)
{
    return first + second;
}

/**************************************************************************
 * function that defines how to subtract one int from another
 *************************************************************************/
int sub(int first,int second)
{
    return first - second;
}

/**************************************************************************
 * funciton that defines how to multiply two ints together
 *************************************************************************/
int mult(int first ,int second)
{
    return first * second;
}

/*************************************************************************
 * function that defines the division operation.
 *************************************************************************/
int divide(int first,int second)
{
    return first / second;
}
