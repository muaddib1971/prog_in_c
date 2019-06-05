/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2019.
 *****************************************************************************/
#include "io.h"
const char* color_strings[NUM_COLORS] = { "\x1b[31m", "\x1b[37m", "\x1b[0m" };
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
 * defines how to print the board given the orientation passed in. Pleas
 * see the asssignment specifications for further details.
 **/
void board_print(board theboard, enum orientation orient)
{
}
