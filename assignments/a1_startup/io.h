/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2018.
 *****************************************************************************/
#include "board.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * these are the data structures defined to support i/o in the system. You
 * should only do i/o in this module so that if we decided to change how i/o
 * worked we would only need to rewrite this module
 **/

#ifndef IO_H /*include guard for the io module - ensures this header file is   \
                included at most once in any source file */
#define IO_H

/**
 * enumeration that specifies the various return values you should be returning
 * handling from functions that read input from the keyboard.
 **/
enum input_result
{
        /* the i/o operation failed - this is often due to buffer overflow */
        IR_FAILURE,
        /* the i/o operation succeeded */
        IR_SUCCESS,
        /* there was a request to return to the main menu such as when quitting
           the game */
        IR_RTM
};

/**
 * These constants are related to i/o operations in general. LINELEN is used to
 * specify a default line length which is the stand unix terminal width. This is
 * used so that output will display the same on everyone's terminal. EXTRACHARS
 * are the two extra chars stored by a successful call to fgets. Finally DECIMAL
 * is used with strtol to specify that the numerical string being processed
 * should be treated as a DECIMAL number.
 **/
#define LINELEN 80
#define EXTRACHARS 2
#define DECIMAL 10

/* the number of menu items in the main menu */
#define NUM_MENU_ITEMS 3

/* colour constants - these are used for turning on and off the red and white
 * colours for displaying the game board. REDCOLOR sets the current colour to
 * red, WHITECOLOR sets the current colour to white and RESETCOLOR resets the
 * colour to the default colours for the terminal. You are advised to simply use
 * the game_tokens global variable which has predefined constants for each
 * colour */
#define REDCOLOR "\033[0;31m"
#define WHITECOLOR "\033[37;1m"
#define RESETCOLOR "\033[0;0m"

/**
 *  the number of token types - empty, red, white, invalid
 **/
#define NUM_TOKEN_TYPES 4

/**
 * global variable that holds the strings for printing an empty square, a red
 * token or a white token.
 **/
extern const char* game_tokens[];

/**
 * public functions implemented for this module
 **/
void read_rest_of_line(void);

int error_print(const char*, ...);

int normal_print(const char*, ...);

void display_board(board);
#endif /* include guard for the io module */
