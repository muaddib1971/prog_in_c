/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2019.
 *****************************************************************************/
#include "helpers.h"
#include "io.h"

/**
 * duplicates a string passed in by allocating memory for it and copying the
 * data. Please note that this function is implemented in C99 but I find it to
 * be a rather convenient function so I often implement it in my ansi C code.
 **/
char*
strdup(const char* orig)
{
        /**
         * allocate sufficient memory for the string, including the nul
         * terminator
         **/
        char* new = malloc(strlen(orig) + 1);
        /**
         * check that the allocation succeeded and if it did not, print an
         * error message
         **/
        if (!new)
        {
                error_print(strerror(errno));
                return NULL;
        }
        /**
         * copy the data
         **/
        strcpy(new, orig);
        return new;
}

/**
 * function that folds a string passed in so that it can be printed with no
 * wraparound on an 80 column display
 **/
char*
fold(const char origline[])
{
        /* get the length of the string so we know when we have finished
         * processing it
         */
        int len = strlen(origline);
        int numleft = len;
        /**
         * duplicate the string so we leave the original the way it was
         **/
        char* copy = strdup(origline);
        /**
         * current points to the current char in the string
         **/
        char* current;
        /* check that our copy succeeded */
        if (!copy)
        {
                return NULL;
        }
        /* copy the old string into the newly allocated space */
        strcpy(copy, origline);
        /* start iteration - set current to the start of our string and move
         * along by a single screen width
         */
        current = copy;
        current += LINE_LEN;
        numleft -= LINE_LEN;
        /**
         * continue this process until we have exhausted the string
         **/
        while (numleft > 0)
        {
                /* search for the last space character */
                while (!isspace(*current))
                {
                        --current;
                }
                /* replace it with a newline character */
                *current = '\n';
                /* jump to the next line */
                current += LINE_LEN;
                numleft = len - (current - copy);
        }
        return copy;
}
