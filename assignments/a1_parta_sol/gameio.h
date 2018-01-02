#include <ctype.h>
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "gameboard.h"
#include "shared.h"

/**
 * The role of this module is to provide a single place where all input and 
 * output is performed from. The reason for doing this is firstly consistency
 * of input and output but also if we decided to change the way we are doing
 * input and output (such as the implementation of a graphical user interface,
 * we would only need to change this module). 
 **/

#ifndef GAMEIO_H
#define GAMEIO_H

/**
 * a macro that prints out a character N times
 **/
#define PRINT_CHARS(ch, len)                                                   \
        {                                                                      \
                int count;                                                     \
                for (count = 0; count < (int)len; ++count)                     \
                {                                                              \
                        putchar(ch);                                           \
                }                                                              \
        }

/**
 * prints out the text specified with dashes underneath it
 **/
#define PRINT_HEADING(heading)                                                 \
        {                                                                      \
                size_t len = strlen(heading);                                  \
                printf("%s\n", heading);                                       \
                PRINT_CHARS('-', len);                                         \
                putchar('\n');                                                 \
        }

/* needed for strtol to specify that the string being processed contains
 * decimal integer data
 */
#define DECIMAL 10
/* the default line length is 80 chars */
#define LINELEN 80
/* defines a response length of 1 for responses that only require one character
 */
#define CHARLEN 1
/* trailing characters in a valid string returned from fgets() */
#define EXTRACHARS 2
/* the width of each cell specified for formatting */
#define CELLWIDTH 4
/* the number of menu items to display */
#define NUM_MENU_ITEMS 2

/**
 * the possible menu choices that a user may select
 **/
enum choice
{
        PLAY_GAME,
        QUIT_PROGRAM
};

/* forward declare the game struct so I can have pointers to a game in this
 * file. */
struct game;

/**
 * this enumeration represents the possible results of an input or output
 * operation. A failure is when something went wrong, success is one nothing
 * went wrong. rtm is returned when ctrl-d or enter is entered on a new line.
 **/
enum input_result
{
        IR_FAILURE,
        IR_SUCCESS,
        IR_RTM
};

/**
 * these are the public functions available from gameio.c. Please see the
 * implementations there for more details.
 **/
enum input_result read_string(const char[], char[], size_t);
BOOLEAN strtoint(const char[], int*);
enum input_result read_int(const char[], int*);
enum input_result read_coordinates(const char[], struct coordinate*);
int print_error(const char[], ...);
BOOLEAN strtocoord(const char[], struct coordinate*);
void display_board(struct game*);
int print_message(const char[], ...);
void display_menu(void);
enum choice get_menu_choice(void);
BOOLEAN quit_response(void);

#endif /* GAMEIO_H */
