#include <stdio.h>
#include <stdlib.h>
size_t givesize(int* ptr)
{
        return sizeof(ptr);
}

int main(void)
{
        int array[10];
        printf("size of a char: %ld\n", sizeof(char));
        printf("size of a short: %ld\n", sizeof(short));
        printf("size of an int: %ld\n", sizeof(int));
        printf("size of a long: %ld\n", sizeof(long));
        printf("size of array: %ld\n", sizeof(array));
        printf("size of array when passed to a function: %ld\n",
               givesize(array));
        return EXIT_SUCCESS;
}
