/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2019.
 *****************************************************************************/
#include "io.h"
#include "helpers.h"
const char* color_strings[NUM_COLORS] = { "\x1b[31m", "\x1b[37m", "\x1b[0m" };
const struct move error_move = { EOF, EOF };
/**
 * function that does buffer clearing when there is a buffer overflow on
 * input - only call this function when there is an actual buffer overflow as
 * otherwise you will have additional problems
 **/
void clear_buffer(void)
{
        int ch;
        /* while there are still chars to read and we have not reached
         * the newline char, keep reading */
        while (ch = getc(stdin), ch != EOF && ch != '\n')
                ;
        /* reset the error status on the stdin file pointer */
        clearerr(stdin);
}

/**
 * this function simply calls printf. It is implemented here so that if we
 * wish to change our output target (such as using a gui) we could change our
 * implementation here and it would not affect any other code in our project.
 **/
int normal_print(const char format[], ...)
{
        int char_count;
        va_list vlist;
        va_start(vlist, format);
        char_count = vprintf(format, vlist);
        va_end(vlist);
        return char_count;
}

/**
 * this function prints out error messages to the stderr file pointer. It is
 * standard practice to output all error messages to stderr rather than
 * stdout (where printf sends messages).
 **/
int error_print(const char format[], ...)
{
        int char_count = 0;
        va_list vlist;
        char_count += fprintf(stderr, "Error: ");
        va_start(vlist, format);
        char_count += vfprintf(stderr, format, vlist);

        return char_count;
}

/**
 * print the heading for the board
 **/
static void print_heading(void)
{
        char* heading = "Backgammon - Current board state";
        puts(heading);
        PUTLINE('-', strlen(heading));
}

/**
 * print the top row based on the orientation of the current player
 **/
static void print_top_row(enum orientation orient)
{
        int xcount;
        /* for clockwise, print the numbers 12 down to 1 */
        if (orient == OR_CLOCKWISE)
        {
                for (xcount = BOARD_WIDTH; xcount > 0; --xcount)
                {
                        normal_print("| %-2d ", xcount);
                }
        }
        else
        {
                /* for anticlockwise, print the numbers 13 to 24 */
                for (xcount = BOARD_WIDTH + 1; xcount <= 2 * BOARD_WIDTH;
                     ++xcount)
                {
                        normal_print("| %-2d ", xcount);
                }
        }
        putchar('\n');
        /* put a line of dashes under the row */
        PUTLINE('-', (CELL_WIDTH + 1) * (BOARD_WIDTH));
}

/**
 * print the bottom row of the table
 **/
static void print_bottom_row(enum orientation orient)
{
        int xcount;
        /* if the player's orientation is clockwise print 13 to 24 */
        if (orient == OR_CLOCKWISE)
        {
                for (xcount = BOARD_WIDTH + 1; xcount <= BOARD_WIDTH * 2;
                     ++xcount)
                {

                        normal_print("| %-2d ", xcount);
                }
        }
        else
        {
                /* if the player's orientation is anticlockwise, print the
                 * numbers 12 down to 1
                 */
                for (xcount = BOARD_WIDTH; xcount > 0; --xcount)
                {

                        normal_print("| %-2d ", xcount);
                }
        }
        putchar('\n');
        PUTLINE('-', (CELL_WIDTH + 1) * (BOARD_WIDTH));
}

/**
 * print a row of the board
 **/
static void print_row(int rownum, board theboard)
{
        int count;
        putchar('|');
        for (count = 0; count < BOARD_WIDTH; ++count)
        {
                /* for each cell, print the appropriate code for a blank, red or
                 * white token
                 */
                switch (theboard[rownum][count])
                {
                        case P_EMPTY:
                                normal_print(" %2c |", EMPTY_TOKEN);
                                break;
                        case P_RED:
                                normal_print(
                                    " %s%2c%s |", color_strings[COLOR_RED],
                                    RED_TOKEN, color_strings[COLOR_RESET]);
                                break;
                        case P_WHITE:
                                normal_print(
                                    " %s%2c%s |", color_strings[COLOR_WHITE],
                                    WHITE_TOKEN, color_strings[COLOR_RESET]);
                                break;
                        default:
                                error_print(
                                    "Oh noes, invalid value in the board!!\n");
                                return;
                }
        }
        putchar('\n');
        PUTLINE('-', (CELL_WIDTH + 1) * (BOARD_WIDTH));
}

/**
 * print out the board according to the orientation of the current player
 **/
void board_print(board theboard, enum orientation orient)
{
        int row_count;
        print_heading();
        print_top_row(orient);

        for (row_count = 0; row_count < BOARD_HEIGHT; ++row_count)
        {
                print_row(row_count, theboard);
        }
        print_bottom_row(orient);
}

/**
 * read strings from the keyboard input
 **/
enum input_result read_string(const char prompt[], char input[], int size)
{
        return IR_FAILURE;
}

/**
 * read an int from the keyboard
 **/
enum input_result read_int(const char prompt[], int* input)
{
        return IR_FAILURE;
}
