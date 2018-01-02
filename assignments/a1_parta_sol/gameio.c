#include "gameio.h"
#include "game.h"

/**
 *
 **/
void read_rest_of_line(void)
{
        int ch;
        while (ch = getc(stdin), ch != '\n' && ch != EOF)
                ;
        clearerr(stdin);
}

/**
 * provided function you can use to duplicate a string
 **/
char* strdup(const char orig[])
{
        char* copy = malloc(strlen(orig) + 1);
        if (!copy)
        {
                print_error(strerror(errno));
                return NULL;
        }
        strcpy(copy, orig);
        return copy;
}

/**
 * reads in a string from the keyboard, handling any errors
 **/
enum input_result read_string(const char prompt[], char output[], size_t maxlen)
{
        return IR_FAILURE;
}

/**
 * displays a prompt as passed in from the calling function. It then calls
 * read_string() to read in a string buffer. It then attempts to parse that
 * buffer for a valid integer, by calling the strtoint function that does the
 * validation and parsing work
 **/
enum input_result read_int(const char prompt[], int* result)
{
        return FALSE;
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
 * displays the board heading (the labels that go along the top). Please note
 * that this function is static because there is no requirement for this
 * function to be available outside of this module.
 **/
static void display_board_header(int dimension)
{
        int count;
        /* indent this line for formatting */
        printf("   |");
        /* iterate over each column and display its header number */
        for (count = 0; count < dimension; ++count)
        {
                printf(" %d |", count + 1);
        }
        putchar('\n');
        /* print dashes under the header line for the board */
        PRINT_CHARS('-', CELLWIDTH + CELLWIDTH * dimension);
        putchar('\n');
}

/**
 * displays the game board for the game. The game board array itself it the
 * same size regardless of the official board_dimension but it only draws a
 * board sufficient to draw the game state's board.
 **/
void display_board(struct game* thegame)
{
        int ycount, xcount;
        /* display the header */
        display_board_header(thegame->board_dimension);
        /* iterate over all the cells in both the y and x directions */
        for (ycount = 0; ycount < thegame->board_dimension; ++ycount)
        {
                /* print out the row label */
                printf(" %d ", ycount + 1);
                for (xcount = 0; xcount < thegame->board_dimension; ++xcount)
                {
                        /* print out the char representation of the token stored
                         * in this array location */
                        printf("| %c ",
                               token_chars[thegame->board[ycount][xcount]]);
                }
                printf("|\n");
                /* print out a line of dashes for formatting */
                PRINT_CHARS('-',
                            CELLWIDTH + CELLWIDTH * (thegame->board_dimension));
                putchar('\n');
        }
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

/**
 * displays the main menu from which the user can select to play a game or
 * exit.
 **/
void display_menu(void)
{
        /* define the menu items */
        char* menu[NUM_MENU_ITEMS] = { "Play Game", "Exit" };
        int count;
        PRINT_HEADING("Welcome to tictactoe");
        /* print out the menu items */
        for (count = 0; count < NUM_MENU_ITEMS; ++count)
        {
                printf("%d) %s\n", count + 1, menu[count]);
        }
}

/**
 * gets the choice from the user for which menu item they wish to select
 **/
enum choice get_menu_choice(void)
{
        int choice;
        enum input_result result;
        /* read the response from the user */
        while (result = read_int("Please enter your choice: ", &choice),
               result == IR_FAILURE)
        {
        }
        /* we treat rtm as an error here unlike elsewhere */
        if (result == IR_RTM)
        {
                print_error("invalid choice entered.\n");
                display_menu();
                return get_menu_choice();
        }
        return choice - 1;
}
