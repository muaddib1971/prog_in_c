/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2019.
 *****************************************************************************/
#include "main.h"

/**
 * function converts string data to a long and sets its BOOLEAN member to FALSE
 * if anything goes wrong.
 **/
struct falsible_long
longfromstr(const char* str)
{
        /**
         * pointer to the next character after what we successfully parses with
         * strtol().
         **/
        char* end;
        /**
         * the result that we will return
         **/
        struct falsible_long result;
        /**
         * parse the string
         **/
        result.thelong = strtol(str, &end, DECIMAL);
        /**
         * ignore spaces at the end of the string
         **/
        while (isspace(*end))
        {
                ++end;
        }
        /**
         * if an invalid argument was passed into strtol or the number converted
         * is outside the range of a long, this operation failed so display
         * an error and exit.
         **/
        if (errno == EINVAL || errno == ERANGE)
        {
                result.success = FALSE;
                error_print("%s\n", strerror(errno));
                return result;
        }
        /**
         * if there was trailing data that was not numeric, display an error
         * message and return FALSE
         **/
        if (*end)
        {
                result.success = FALSE;
                error_print("the provided value is not numeric. \n");
        }
        result.success = TRUE;
        return result;
}

/**
 * main function that kickstatts the program
 **/
int
main(int argc, char* argv[])
{
        /**
         * a falsible number - set it to 0 as if no seed is passed it that's
         *what it should be.
         **/
        struct falsible_long seed = { 0 };
        /* was no seed passed in? */
        if (argc != MAXARGS)
        {
                play_game(seed);
                return EXIT_SUCCESS;
        }
        else
        {
                /* retrieve the seed from argv 1 */
                seed = longfromstr(argv[SEED_ARG]);
                /* if we did not succeed in retrieving the seed,
                 * exit the program
                 */
                if (!seed.success)
                {
                        return EXIT_FAILURE;
                }
                /* start the game, passing in the seed */
                play_game(seed);
        }
        return EXIT_SUCCESS;
}
