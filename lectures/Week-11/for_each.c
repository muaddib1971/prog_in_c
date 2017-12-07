#include "for_each.h"
#define TOTAL_NUMS 100
#define MAX_NUM 1000
#define WIDTH 5
#define DIVISOR 50.0

int main(void)
{
    int val;
    double dval;
    int nums[TOTAL_NUMS];
    double dnums[TOTAL_NUMS];
    
    /* fill the array and print its initial state */
    printf("\n\n-- int run --\n\n");
    fill_int_array(nums, TOTAL_NUMS);
    print_array(nums, TOTAL_NUMS, sizeof(int),  print_int);
    
    /* add a random value to all elements of the array */
    val = rand()%MAX_NUM;
    printf("adding %d\n", val);
    for_each(nums, &val, TOTAL_NUMS, sizeof(int), add_int);
    print_array(nums, TOTAL_NUMS, sizeof(int), print_int);

    /* subtract random amount from each element */
    val = rand()%MAX_NUM;
    printf("subtracting %d\n", val);
    for_each(nums, &val, TOTAL_NUMS, sizeof(int), sub_int);
    print_array(nums, TOTAL_NUMS, sizeof(int), print_int);

    /* multiply each element by a random amount */
    val = rand() % MAX_NUM;
    printf("multiplying %d\n", val);
    for_each(nums, &val, TOTAL_NUMS, sizeof(int), mult_int);
    print_array(nums, TOTAL_NUMS, sizeof(int), print_int);

    /* divide each element by a random amount */
    val = rand() % MAX_NUM;
    printf("dividing %d\n", val);
    for_each(nums, &val, TOTAL_NUMS, sizeof(int), div_int);
    print_array(nums, TOTAL_NUMS, sizeof(int), print_int);

    /* repeat the above process with doubles */
    printf("\n\n-- double run --\n\n");
    
    fill_double_array(dnums, TOTAL_NUMS);
    print_array(dnums, TOTAL_NUMS, sizeof(double), print_double);
    
    dval = (rand()%MAX_NUM)/DIVISOR;
    printf("adding %f\n", dval);
    for_each(dnums, &dval, TOTAL_NUMS, sizeof(double), add_double);
    print_array(dnums, TOTAL_NUMS, sizeof(double), print_double);

    dval = (rand()%MAX_NUM)/DIVISOR;
    printf("subtracting %f\n", dval);
    for_each(dnums, &dval, TOTAL_NUMS, sizeof(double), sub_double);
    print_array(dnums, TOTAL_NUMS, sizeof(double), print_double);

    dval = (rand() % MAX_NUM) / DIVISOR;
    printf("multiplying %f\n", dval);
    for_each(dnums, &dval, TOTAL_NUMS, sizeof(double), mult_double);
    print_array(dnums, TOTAL_NUMS, sizeof(double), print_double);

    dval = (rand() % MAX_NUM)/DIVISOR;
    printf("dividing %f\n", dval);
    for_each(dnums, &dval, TOTAL_NUMS, sizeof(double), div_double);
    print_array(dnums, TOTAL_NUMS, sizeof(double), print_double);
    return EXIT_SUCCESS;
}

/* fill the int array - just seed the random number generator and fill the 
 * array with random numbers between 0 and MAX_NUM */
void fill_int_array(int* array, size_t i_count)
{
    unsigned count;
    srand(time(NULL));
    for(count = 0; count < i_count; ++count)
    {
        array[count]=rand()%MAX_NUM;
    }
}

/* do the same as above but for doubles */
void fill_double_array(double * array , size_t elt_count)
{
    unsigned count;
    for(count = 0; count < elt_count; ++count)
    {
        array[count]=(rand() % MAX_NUM)/DIVISOR;
    }
}

/* generic print function. */
void print_array(void * nums, size_t count, size_t size, 
    void(*printfunc)(const void*))
{
    unsigned elts_processed;
    /* grab the address of the first element */
    void * current = nums;
    /* iterate over the elements and print them */
    for(elts_processed= 0; elts_processed < count; ++elts_processed, 
        /* note this low level pointer arithmetic. We cast to char* so 
         * there is an implicit multiplication by 1
         */
        current = ((char*)current) + size)
    {
        printfunc(current);
    }
}

/* the foreach function - the powerhouse of this application */
/* notice how all parameters passed in are either void pointers or memory
 * sizes (size_t). This allows us to treat the data in a generic way and 
 * only in the client functions is the type resolved.
 */
void for_each(void * nums, void* val, size_t elt_count, size_t elt_size,
    void(*doit)(const void*,const void*, void*))
{
    unsigned count;
    void * current = nums;

    /* iterate over the memory */
    for(count = 0; count < elt_count; ++count, 
        current = ((char*)current) + elt_size)
    {
        /* perform the required function */
        doit(current, val, current);
    }
}

/* functions for each arithmetic operation. Note that the first two pointers
 * are const void * as they are meant only for input and should not
 * be altered by this function */
void add_int(const void* first,const void* second, void * output)
{
    /*assigning from void * so no cast is required */
    int * result = output;
    const int * ifirst = first;
    const int * isecond = second;
    *result = *ifirst + *isecond;
}

void sub_int(const void* first,const void* second, void* output)
{
    int * result = output;
    const int * ifirst = first;
    const int * isecond = second;
    *result = *ifirst - *isecond;
}

void mult_int(const void * first ,const void* second, void* output)
{
    int * result = output;
    const int * ifirst = first;
    const int * isecond = second;
    *result = *ifirst * *isecond;
}

void div_int(const void * first, const void* second, void* output)
{
    int * result = output;
    const int* ifirst = first;
    const int * isecond = second;
    *result = *ifirst / *isecond;
}

void add_double(const void* first,const void* second, void * output)
{
    double * result = output;
    const double * ifirst = first;
    const double * isecond = second;
    *result = *ifirst + *isecond;
}

void sub_double(const void* first,const void* second, void* output)
{
    double * result = output;
    const double * ifirst = first;
    const double * isecond = second;
    *result = *ifirst - *isecond;
}

void mult_double(const void * first ,const void* second, void* output)
{
    double * result = output;
    const double * ifirst = first;
    const double * isecond = second;
    *result = *ifirst * *isecond;
}

void div_double(const void * first, const void* second, void* output)
{
    double * result = output;
    const double * ifirst = first;
    const double * isecond = second;
    *result = *ifirst / *isecond;
}

/* generic printing functions - these know about the underlying data and so 
 * they can cast to the correct type
 */
void print_int(const void * data)
{
    static unsigned count = 0;
    const int * output = data;
    printf("%d\t", *output);
    ++count;
    if(count % WIDTH == 0)
        printf("\n");
}

void print_double(const void * data)
{
    static unsigned count=0;
    const double* output = data;
    printf("%f\t", *output);
    ++count;
    if(count % WIDTH == 0)
        printf("\n");
}
