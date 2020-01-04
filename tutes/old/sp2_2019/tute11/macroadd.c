#include <stdio.h>
#include <stdlib.h>
#define DIV(X, Y) ((X) / (Y))

void array_walk(void *array, size_t length, size_t size,
                void (*process)(void *))
{
        void *iterator = array;
        int count;
        for (count = 0; count < length; ++count)
        {
                process(iterator);
                iterator = ((char *)iterator) + size;
        }
}

void add_two(void *ptr)
{
        int *p_i = ptr;
        *p_i += 2;
}

void print_int(void *ptr)
{
        int *p_i = ptr;
        printf("%d\n", *p_i);
}

int main(void)
{
        int array[5] = { 1, 3, 5, 7, 9 };
        int a = 5, b = 2, c = 4, d = 2;
        array_walk(array, 5, sizeof(int), add_two);
        array_walk(array, 5, sizeof(int), print_int);
        int result = DIV(a + b, c + d);
        printf("The result was: %d\n", result);
        return EXIT_SUCCESS;
}

/* 5+2/4+2 */
