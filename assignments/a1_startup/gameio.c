/***********************************************************************
* CPT220 - Programming in C
* Study Period 4 2017 Assignment #1 
* Full Name        : EDIT HERE
* Student Number   : EDIT HERE
* Start up code provided by Paul Miller
***********************************************************************/

#include "gameio.h"
#include "game.h"

/**
 * function that performs buffer clearing when you detect that too much input
 * has been entered. Have a look at the course examples to see how to use this
 * function correctly. Understanding of the operation of buffering is essential
 * to understanding input and output in C and there is a lot of misunderstanding
 * of this topic. If you struggle with this, please ensure that you ask lots of 
 * questions.
 **/
void read_rest_of_line(void)
{
        int ch;
        while (ch = getc(stdin), ch != '\n' && ch != EOF)
                ;
        clearerr(stdin);
}


/**
 * this function provides a printf like interface for you to use to print out
 * error messages from your program. You provide the format specifier as the
 * first argument followed by any other arguments. It does some minor formatting
 * such as prepending "Error: " to all your error messages which is required
 * for my tester of your program
 **/
int print_error(const char format[], ...)
{
        int numchars;
        va_list arg_list;
        numchars = fprintf(stderr, "Error: ");
        /* retrieve the argument list */
        va_start(arg_list, format);
        /* pass the argument list to vprintf */
        numchars += vfprintf(stderr, format, arg_list);
        /* stop processing the argument list */
        va_end(arg_list);
        return numchars;
}

/**
 * displays the game board for the game. The game board array itself it the
 * same size regardless of the official board_dimension but it only draws a
 * board sufficient to draw the game state's board.
 **/
void display_board(struct game* thegame)
{
}

/**
 * function to allow you to print out general informational messages
 **/
int print_message(const char format[], ...)
{
        /* print out a leading info tag */
        int numchars = printf("%s", "Info: ");
        /* extract the data passed from the ... and pass it into printf */
        va_list arg_list;
        va_start(arg_list, format);
        numchars += vprintf(format, arg_list);
        va_end(arg_list);
        /* return the number of chars printed consistent with the printf
         * interface */
        return numchars;
}

