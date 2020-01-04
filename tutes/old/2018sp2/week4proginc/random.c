#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define ARRAYMAX 20

void init_array(int array[], int size)
{
        /*
        int * item;
        int items[ARRAY_SIZE];
        char * str = "foo";
        */

        int count;

        for (count = 0; count < size; ++count)
        {
                array[count] = rand();
        }
}

static void int_swap(int* a, int* b)
{
        int temp = *a;
        *a = *b;
        *b = temp;
}

void sort_array(int array[], int size)
{
        int outer, inner;
        for (outer = 0; outer < size - 1; ++outer)
        {
                for (inner = outer + 1; inner < size; ++inner)
                {
                        /*array[3]
                            * (array + 3)
                             pointer arithmetic !! */
                        if (array[outer] > array[inner])
                        {
                                int_swap(array + inner, array + outer);
                        }
                        /*
                            int_swap(&array[inner], &array[outer]);
                            */
                }
        }
}

void array_diff(const int first_array[], const int second_array[],
                int diff_array[], int size)
{
        int count;
        for (count = 0; count < size; ++count)
        {
                diff_array[count] =
                    abs(first_array[count] - second_array[count]);
        }
}

void array_print(int array[], int size)
{
        int count;
        for (count = 0; count < size; ++count)
        {
                printf("%d\n", array[count]);
        }
}

int main(void)
{
        int first_array[ARRAYMAX], second_array[ARRAYMAX], diff_array[ARRAYMAX];
        srand(time(NULL));
        init_array(first_array, ARRAYMAX);
        init_array(second_array, ARRAYMAX);
        sort_array(first_array, ARRAYMAX);
        sort_array(second_array, ARRAYMAX);
        array_diff(first_array, second_array, diff_array, ARRAYMAX);
        array_print(diff_array, ARRAYMAX);
        return EXIT_SUCCESS;
}
