#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TOTAL_NUMS 100
#define MAX_NUM 1000
#define WIDTH 10

void fill_array(int*, size_t);
#undef div
int add(int,int);
int sub(int,int);
int mult(int,int);
int divide(int,int);

void for_each(int * nums, int val, size_t i_count, int(*)(const int,const int));

void print_array(int * nums, size_t i_count);

