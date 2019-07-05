/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2019.
 *****************************************************************************/
#include "shared.h"
#include "board.h"
#ifndef BARLIST_H
#define BARLIST_H
#define MAX_BAR 15

/**
 * The bar_list data structure provided to you. It is just and array with the
 * count of how many elements
 **/
struct bar_list
{
        enum piece bar_array[MAX_BAR];
        int token_count;
};

/**
 * functions I have implemented for you in bar_list.c
 **/
void barlist_init(struct bar_list*);
BOOLEAN barlist_push(struct bar_list*, enum piece);
enum piece barlist_pop(struct bar_list*);
void barlist_delete(struct bar_list*);
#endif
