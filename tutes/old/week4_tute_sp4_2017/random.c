#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAXNUM 1000
#define MAXLEN 500
#define ARRAYLEN 10

void array_init(int array[], int len)
{
        memset(array, 0, len * sizeof(int));
}

void rnd_init(void)
{
        /* time_t time(time_t*) */
        time_t now;
        srand(time(&now));
}
/* sizes : unsigned (32 bit unsigned) or size_t (64 bit) */
void array_fill(int array[], int len)
{
        int item_count;
        for (item_count = 0; item_count < len; ++item_count)
        {
                array[item_count] = rand() % MAXNUM + 1;
        }
}

void swap_ints(int* first, int* second)
{
        int tmp;
        tmp = *first;
        *first = *second;
        *second = tmp;
}

void array_sort(int array[], int length)
{
        int outer, inner;
        int* reference = array;
        for (outer = 0; outer < length - 1; ++outer)
        {
                for (inner = outer; inner < length; ++inner)
                {
                        if (array[outer] < array[inner])
                        {
                                swap_ints(&reference[outer], (array + inner));
                        }
                }
        }
}

void array_diff(int first_array[], int second_array[], int result_array[],
                int len)
{
        int item_count;
        for (item_count = 0; item_count < len; ++item_count)
        {
                result_array[item_count] =
                    abs(first_array[item_count] - second_array[item_count]);
        }
}

int main(void)
{
        int first[ARRAYLEN];
        int second[ARRAYLEN];
        int results[ARRAYLEN];
        int count;

        rnd_init();
        array_init(first, ARRAYLEN);
        array_init(second, ARRAYLEN);
        array_fill(first, ARRAYLEN);
        array_fill(second, ARRAYLEN);
        array_sort(first, ARRAYLEN);
        array_sort(second, ARRAYLEN);
        array_diff(first, second, results, ARRAYLEN);
        array_sort(results, ARRAYLEN);
        for (count = 0; count < ARRAYLEN; ++count)
        {
                printf("%d\t", results[count]);
        }
        putchar('\n');
        return EXIT_SUCCESS;
}

/* array length = N, N*N comparisons */
