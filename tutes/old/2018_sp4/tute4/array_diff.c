#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAYSIZE 10

/* this function generously dontated by Ben Cooper */
void array_fill(int array[])
{
        int i;
        for (i = 0; i < ARRAYSIZE; ++i)
        {
                array[i] = rand();
        }
}

static void int_swap(int* first, int* second)
{
        int temp;
        temp = *first;
        *first = *second;
        *second = temp;
}

void array_sort(int array[])
{
        int outer, inner;
        for (outer = 0; outer < ARRAYSIZE - 1; ++outer)
        {
                for (inner = outer + 1; inner < ARRAYSIZE; ++inner)
                {
                        if (array[inner] > array[outer])
                        {
                                int_swap(&array[inner], &array[outer]);
                                /* int_swap(array + inner, array + outer); */
                        }
                }
        }
}

void array_diff(int first_array[], int second_array[], int diff_array[])
{
        int count;
        for (count = 0; count < ARRAYSIZE; ++count)
        {
                diff_array[count] =
                    abs(first_array[count] - second_array[count]);
        }
}

/**
 * I have rewritten this to use an iterator approach
 **/
void array_print(int array[])
{
        int* curr_elt;
        for (curr_elt = array; curr_elt < array + ARRAYSIZE; ++curr_elt)
        {
                printf("%d\n", *curr_elt);
        }
}

int main(void)
{
        int first_array[ARRAYSIZE];
        int second_array[ARRAYSIZE];
        int diff_array[ARRAYSIZE];

        srand(time(NULL));
        array_fill(first_array);
        array_fill(second_array);
        array_sort(first_array);
        array_sort(second_array);
        array_diff(first_array, second_array, diff_array);
        array_sort(diff_array);
        array_print(diff_array);
        return EXIT_SUCCESS;
}
