#include "main.h"

#include "shared.h"
#include <limits.h>
#include <errno.h>
#include <ctype.h>
#include "options.h"

/**
 * extracts the seed (a long int) from a string passed in
 **/
static long get_seed(const char strseed[])
{
        char* end;
        long result;
#define DECIMAL 10
        /* try to extract a long integer */
        result = strtol(strseed, &end, DECIMAL);
        /* check it is within the valid range */
        if (errno == ERANGE)
        {
                fprintf(stderr, "Error: %s is outside the allowed range for a "
                                "long integer.\n",
                        strseed);
                exit(EXIT_FAILURE);
        }
        /* search for any trailing characters */
        while (isspace(*end))
        {
                ++end;
        }
        if (*end)
        {
                fprintf(stderr, "Error: %s is not a valid seed.\n", strseed);
                exit(EXIT_FAILURE);
        }
        return result;
}

enum
{
        MIN_ARGS = 1,
        CORRECT_ARGS,
        OVERFLOW_ARGS
};

#define SEED_ARG 1
/**
 * you are expected to READ the comments here and fill in your code BETWEEN the
 * comments.
 **/
int main(int argc, char* argv[])
{
        /* the user's menu choice */
        enum menu_choice choice;
        /* the menus themselves */
        menu themenu;

        long seed;
        if (argc < MIN_ARGS || argc >= OVERFLOW_ARGS)
        {
                fprintf(stderr, "Error: invalid arguments passed in. You "
                                "should call this program as follows: ");
                fprintf(stderr, "\tcpt_220_menu [seed]\n");
                fprintf(stderr, "Where seed is an optional argument which is a "
                                "positive integer seed for the random number "
                                "generator.\n");
                return EXIT_FAILURE;
        }
        seed = argc == CORRECT_ARGS ? get_seed(argv[SEED_ARG]) : EOF;
        /* initialise the menu with the data to be displayed to the user */
        init_menu(themenu);
        do
        {
                BOOLEAN success = FALSE;
                /* display the menu to the user repeatedly until the user
                 * chooses to
                 * quit */
                choice = select_menu_item(themenu);
                /* handle errors */
                if (choice == MNU_INVAL)
                {
                        error_output("invalid option selected");
                }
                else if (choice == MNU_GUESS)
                {
                        /* check for guess choice - if it if guess a number,
                         * pass in the
                         * seed as well as no further input is required */
                        guess_a_number(seed);
                }
                else
                {
                        /* process the user input and run the appropriate menu
                         * item */
                        menu_process_choice(choice);
                }
                if (!success)
                {
                        fprintf(stderr, "Option not run successfully\n");
                }
        } while (choice != MNU_QUIT);
        return EXIT_SUCCESS;
}
