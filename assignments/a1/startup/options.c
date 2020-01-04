#include "options.h"

#include <assert.h>
#include <ctype.h>

#include "menu.h"
/**
 * This file contains the implementations of the different options that are
 * part of the assignment. This file should contain only the logic to implement
 * each function and return values. It should not contain any input or output.
 * If you need to do input or output, you must expose functions in the menu.c
 * and menu.h library and call those functions in this module.
 **/

/**
 * reverse_string(): takes as an argument a string that you must reverse
 *inplace. You must not move the nul terminator but must swap each char in the
 *first half of the string to the appropriate location in the second half of the
 * string and vice-versa.
 **/
void reverse_string(char str[])
{
}

/**
 * play the guess a number game. Generate a random number between 1 and 10.
 * Give the user ten guesses to guess the number.
 **/
void guess_a_number(void)
{
}

/**
 * Implementation of the can_give_change() algorithm. for the current cash
 * register, can we provide the list of change requests? Please note that
 * this is most easily completed using recursion but it is up to you how you
 * do this. This task is much more freeform as it is considered an
 * advanced task for this assignment.
 **/
struct falsible_register can_give_change(const cash_register reg,
                                         const change_requests requests)
{
        /* replace this comment and the stub with code to calculate whether the
         * change requests can be satisfied with the cash register provided */
        struct falsible_register result;
        result.success = FALSE;
        return result;
}

/**
 * folds a string passed in so that no line is longer than the specified width.
 * This function should behave the same as the unix "fold" command. You should
 * compare your output to calling the fold program at the terminal as follows:
 *     fold -s -w [width] [filename]
 * Where width is the desired width to fold at and filename holds the contents
 * that you wish to fold.
 *
 * The recommended approach here is to jump forward by width characters and
 * then step backwards until you find a space character and replace it with
 * a newline character.
 **/
char* fold(char str[], unsigned width)
{
        /* replace this comment and stub with your actual implementation. */
        return NULL;
}

/**
 * check if there is a win. That is, is there three in a row of either X or O
 * in any row or any column of the board or if there is three in a row in
 * either diagonal direction.
 **/
enum ttt_result ttt_check_win(ttt_board board)
{
        return TTT_ONGOING;
}
