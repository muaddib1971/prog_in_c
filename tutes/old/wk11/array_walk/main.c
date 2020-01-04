#include "walk.h"
#include <stdio.h>

void dbl_add_ten(void*);
void dbl_sub_ten(void*);
void int_add_ten(void*);
void int_sub_ten(void*);
void print_double(void*);
void print_int(void*);


int main(void)
{
    int int_array[] = {
        1,3,5,6,8,9
    };
    double dbl_array[] = {
        1.1, 3.3, 5.5, 9.9, 3.14, 12.1 
    };

    array_walk(int_array, sizeof(int), 6, print_int);
    printf("\n\n");
    array_walk(dbl_array, sizeof(double), 6, print_double);
    printf("\n\n");
    array_walk(dbl_array, sizeof(double), 6, dbl_add_ten);
    array_walk(int_array, sizeof(int), 6, int_add_ten);
    array_walk(int_array, sizeof(int), 6, print_int);
    printf("\n\n");
    array_walk(dbl_array, sizeof(double), 6, print_double);
    printf("\n\n");
    return EXIT_SUCCESS;
}

void dbl_add_ten(void* num)
{
    *((double*)num)+=10;
}
void dbl_sub_ten(void* num)
{
    *((double*)num) -= 10;
}
void int_add_ten(void* num)
{
    *((int*)num) += 10;
}

void int_sub_ten(void* num)
{
    *((int*)num)+=10;
}
void print_double(void* num)
{
    printf("%f\t", *((double*)num));
}

void print_int(void* num)
{
    printf("%d\t", *((int*)num));
}
