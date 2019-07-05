/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2019.
 *****************************************************************************/
#include "bar_list.h"

/**
 * just initialise the bar_list by setting the total count of elements in the
 * bar_list to 0 - so it's an empty list
 **/
void barlist_init(struct bar_list* alist)
{
        alist->token_count = 0;
}

/**
 * adds an token to the bar_list
 **/
BOOLEAN barlist_push(struct bar_list* alist, enum piece thepiece)
{
        if (alist->token_count == MAX_BAR)
        {
                return FALSE;
        }
        alist->bar_array[alist->token_count++] = thepiece;
        return TRUE;
}

/**
 * removes a token from the bar_list
 **/
enum piece barlist_pop(struct bar_list* thelist)
{
        if (thelist->token_count == 0)
        {
                return P_INVALID;
        }
        return thelist->bar_array[--thelist->token_count];
}

/**
 * sets the bar_list back to being an empty list
 **/
void barlist_delete(struct bar_list* thelist)
{
        thelist->token_count = 0;
}
