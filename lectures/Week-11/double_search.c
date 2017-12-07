#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_NUMS 100
#define MAX_NUM 100
#define DIVISOR 10.0
#define WIDTH 5
#define NUM_SEARCHES 10

void fill_doubles(double *, size_t);
void print_doubles(const double*, size_t);
void double_sort(double*, size_t);
int double_cmp(const void*,const void*);
void search_doubles(const double*, size_t);
int main(void)
{
    double nums[TOTAL_NUMS];
    /* initialise the array with a series of random numbers */
    fill_doubles(nums, TOTAL_NUMS);
    /* print them out to show they are in random order */
    print_doubles(nums, TOTAL_NUMS);
    search_doubles(nums, TOTAL_NUMS);
    /* sort them using qsort */
    double_sort(nums, TOTAL_NUMS);
    printf("\n\n");
    /* print them out after sorting to show the sort worked */
    print_doubles(nums, TOTAL_NUMS);
    search_doubles(nums, TOTAL_NUMS);
    return EXIT_SUCCESS;
}

/* fill an array with random doubles */
void fill_doubles(double * numbers, size_t d_count)
{
    unsigned count;
    /* seed the random number generator */
    srand(time(NULL));
    for(count = 0; count < d_count; ++count)
    {
        /* fill each spot with a random number between 0 and 10 */
        numbers[count]=(rand()%MAX_NUM)/DIVISOR;
    }
}

/* print out all the numbers in a double array */
void print_doubles(const double *array, size_t d_count)
{
    unsigned count;
    for(count = 0; count < d_count; ++count)
    {
        /* print WIDTH numbers per line */
        printf("%f\t", array[count]);
        if((count+1) % WIDTH == 0)
            printf("\n");
    }
    printf("\n");
}

/* do the sorting with qsort */
void double_sort(double* array, size_t d_count)
{
    qsort(array, d_count, sizeof(double), double_cmp);
}

/* comparison function. doubles are only compared up to the 
 * second decimal place. As with most floating point operations 
 * there may be some approximation here.
 */
int double_cmp(const void * first, const void * second)
{
    double d_first = *((double*)first);
    double d_second = *((double*)second);
    double cmp = d_first - d_second;
    /* round at second decimal place */
    return ((int)(cmp*100));
}

/* search for a random needle
 */
void search_doubles(const double* array, size_t d_count)
{
    unsigned count;
    /* perform a series of searches for random needles */
    for(count = 0; count < NUM_SEARCHES; ++count)
    {
        /* generate random needle - what's a needle? */
        double needle = (rand()%MAX_NUM)/DIVISOR;
        /* perform the search */
        double * result = 
            bsearch(&needle, array, d_count, sizeof(double), 
                double_cmp);
        if(result)
        {
            printf("%f was found.\n\n", *result);
        }
        else
        {
            printf("%f was not found.\n\n", needle);
        }
    }
}
