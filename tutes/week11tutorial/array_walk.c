#include <stdlib.h>
#include <stdio.h>

void array_walk(void *start, size_t size_elt, size_t num_elements,
                void (*operation)(void *))
{
        size_t count;
        for (count = 0; count < num_elements; ++count)
        {
                void *element = ((char *)start) + count * size_elt;
                operation(element);
        }
}

void int_add_one(void *elem)
{
        *((int *)elem) += 1;
}

void dbl_mlt_two(void *elem)
{
        double *numptr = elem;
        *numptr *= 2;
}

void print_int_array(void *elem)
{
        printf("%d\n", *((int *)elem));
}

void print_dbl_array(void *elem)
{
        printf("%f\n", *((double *)elem));
}

int main(void)
{
        int intarray[5] = { 1, 3, 5, 7, 9 };
        double dblarray[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };

        array_walk(intarray, sizeof(int), 5, int_add_one);
        array_walk(dblarray, sizeof(double), 5, dbl_mlt_two);

        array_walk(intarray, sizeof(int), 5, print_int_array);
        array_walk(dblarray, sizeof(double), 5, print_dbl_array);

        return EXIT_SUCCESS;
}
