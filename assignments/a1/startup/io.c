/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 4, 2018.
 *****************************************************************************/
#include "io.h"

/**
 * The colour codes for printing out coloured output. You just print out the
 * code to change the current colour being printed outThe colour codes for
 * printing out coloured output. You just print out the
 * code to change the current colour being printed out.
 **/
const char* color_strings[NUM_COLORS] = {
    /* red */ "\x1b[31m",    /* green */ "\x1b[32m",
    /* yellow */ "\x1b[33m",
    /* blue */ "\x1b[34m",   /* magenta */ "\x1b[35m",
    /* cyan */ "\x1b[36m",   /* reset */ "\x1b[0m",
};

/**
 * clear the input buffer so we don't skip prompts. Please note that you don't
 * need to call this function unless you have actually detected that too
 * much input has been received. Please note that as this function is declared
 * static, it must be called in this module and not outside of it.
 **/
static void read_rest_of_line(void) {
        int ch;
        while (ch = getc(stdin), ch != '\n' && ch != EOF)
                ;
        clearerr(stdin);
}

/**
 * prints out the current state of the board
 **/
void print_board(gameboard board) {}

/**
 * acts as a proxy to printf. All output sent here will go to normal output via
 * "stdout"
 **/
int normal_print(const char format[], ...) {
        va_list va_args;
        int output_chars;
        /* initialise the variable args */
        va_start(va_args, format);
        /* pass them to printf */
        output_chars = vprintf(format, va_args);
        /* finish with processing the variable args */
        va_end(va_args);
        /* return the number of chars written out */
        return output_chars;
}

/**
 * acts as a proxy to printf, except the output gets sent to stderr, the
 * error file pointer. . All output sent here will go to normal output via
 * "stdout"
 **/
int error_print(const char format[], ...) {
        va_list va_args;
        int output_chars;
        /* initialise the variable args */
        va_start(va_args, format);
        /* output preamble to an error message: */
        output_chars = fprintf(stderr, "Error: ");
        /* print the error message */
        output_chars += vfprintf(stderr, format, va_args);
        output_chars += fprintf(stderr, "\n");
        return output_chars;
}
