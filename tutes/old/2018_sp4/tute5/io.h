#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef IO_H
#define IO_H
#define MAX_NUMS 10

#define EXTRACHARS 2
struct num_list {
    int nums[MAX_NUMS];
    int count;
};

typedef enum { FALSE, TRUE } BOOLEAN;

BOOLEAN load_file(const char[], char[]);
BOOLEAN extract_nums(const char line[], struct num_list* nums);
int sum_nums(struct num_list*);
BOOLEAN write_nums(const char fname[], struct num_list* nums, int sum);
#endif
