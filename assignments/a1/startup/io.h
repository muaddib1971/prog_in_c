/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2019.
 *****************************************************************************/
#include "board.h"
#include "helpers.h"
#include <ctype.h>
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef IO_H
#define IO_H

/**
 * trailing chars added by fgets after each call
 **/
#define EXTRA_CHARS 2

/**
 * the length of a line in our system
 **/
#define LINE_LEN 80

/**
 * the specification of decimal as required by strtol() and related functions
 **/
#define DECIMAL 10

/**
 * The various results of an i/o operation
 **/
enum input_result
{
        /* the operation failed */
        IR_FAILURE,
        /* the operation succeeded */
        IR_SUCCESS,
        /* the user has chosen to skip their turn */
        IR_SKIP_TURN,
        /* the user has chosen to quit the game */
        IR_QUIT
};

/**
 * three colours to keep track of: red, white and reset which resets the display
 * back to the default colours.
 **/
#define NUM_COLORS 3

/**
 * the array of strings that specify the ansi colour codes for turning on and
 * off specific colours.
 **/
extern const char* color_strings[];

/**
 * the colors that are possible - these match directly to array indexes in the
 * color_strings array.
 **/
enum color
{
        COLOR_RED,
        COLOR_WHITE,
        COLOR_RESET
};

/**
 * tokens that are possible in the game
 **/
enum token
{
        RED_TOKEN = 'X',
        WHITE_TOKEN = 'O',
        EMPTY_TOKEN = ' ',
        INVALID_TOKEN = EOF
};

/**
 * These are examples of C macros. A macro is like a function (mostly) in terms
 * of syntax but does not have the overheads of a function. This code replaces
 * inline each call to it. The downside is that we can't specify the type of the
 * parameters and so if you pass the wrong stuff in, the compiler will complain
 * about the line of code, not this macro.
 *
 * This macro just puts a line of chars in a row based on what you specify. So
 * for example, PUTCHARS('-', 5) would print out 5 dashes.
 **/
#define PUTCHARS(ch, count)                                                    \
        {                                                                      \
                int char_count;                                                \
                for (char_count = 0; char_count < (int)count; ++char_count)    \
                {                                                              \
                        putchar(ch);                                           \
                }                                                              \
        }

/**
 * this is also a macro. it prints out a line of characters in a row followed
 * by a newline character. To print out 80 dashes followed by a newline
 * character I would call this macro as PUTLINE('-', 80)
 **/
#define PUTLINE(ch, count)                                                     \
        {                                                                      \
                PUTCHARS(ch, count);                                           \
                putchar('\n');                                                 \
        }

/**
 * You may add your own data structures here to help with processing of i/o.
 **/

/**
 * student's data structure declarations end here.
 **/

/**
 * globally available functions - you may need to add more of your own.
 **/
void clear_buffer(void);

int normal_print(const char format[], ...);

int error_print(const char format[], ...);

void board_print(board, enum orientation);

#endif
