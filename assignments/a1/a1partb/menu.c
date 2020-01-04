#include "menu.h"

#include <stdarg.h>
#include <string.h>

#include "helpers.h"
#include "options.h"
#include "shared.h"

/**
 * The famous read_rest_of_line() function.
 * It reads chars from stdin (most of the time the keyboard) until we
 * reach either the end of the operating system's input buffer or we
 * reach a newline character (that's the end of the buffer that we should
 * read).
 **/
static void read_rest_of_line(void)
{
        int ch;
        while (ch = getc(stdin), ch != '\n' && ch != EOF)
                ;
        clearerr(stdin);
}

/**
 * these functions are left unimplemented as there are still marks available for
 * them. If you are one of those students who could not figure out fgets, you
 * need to solve this as it's an essential part of programming to be able to
 * do buffer handling.
 **/
enum input_result get_int(const char prompt[], int* output)
{
        return IR_FAILURE;
}

enum input_result get_string(const char prompt[], char output[], size_t maxlen)
{
        return IR_FAILURE;
}
/**
 * initialises the menu - that is copies the required string values into the
 * provided menu array. Please note that hardcoding of array indexes here
 * will result in a 50% penalty on this requirement.
 **/
void init_menu(char menu[NUM_MENU_ITEMS][SCREENWIDTH + 1])
{
        char menu_template[NUM_MENU_ITEMS][SCREENWIDTH + 1] = {
                "reverse a string",             "play guess a number",
                "fold a string",                "validate tictactoe winner",
                "check if change can be given", "access the help menu",
                "quit the program"
        };
        memcpy(menu, menu_template, sizeof(menu_template));
}

/**
 * displays the menu as specified by the assignment document. It must be
 * displayed exactly as outlined in the assignment specification.
 **/
void display_menu(char menu[NUM_MENU_ITEMS][SCREENWIDTH + 1])
{
        char* heading = "Welcome to my menu";
        int count;
        /* display heading */
        puts(heading);
        /* display underline */
        PUTLINE('-', strlen(heading));
        /* display each line of the menu */
        for (count = 0; count < NUM_MENU_ITEMS; ++count)
        {
                normal_output("%d) %s\n", count + 1, menu[count]);
        }
}

/**
 * allows the user to select a menu item to run from the menu
 **/
enum menu_choice select_menu_item(char menu[NUM_MENU_ITEMS][SCREENWIDTH + 1])
{
        /* please note that this is a stub return value. You must delete this
         * comment and the return value below it or I will penalise for this */
        int choice;
        enum input_result result;
        /* display the menu */
        display_menu(menu);
        /* get the user's choice */
        result = get_int("Please enter your choice: ", &choice);
        if (result == IR_FAILURE)
        {
                error_output("Option could not be run successfully.\n");
                return result;
        }
        return IR_SUCCESS;
}

void display_help(void)
{
}

/**
 * process input from the menu and launch each of the options
 **/
void menu_process_choice(enum menu_choice selected_choice)
{
        switch (selected_choice)
        {
                case MNU_REV:
                {
                        reverse_string(NULL);
                }
                break;
                case MNU_FOLD:
                {
                        fold(NULL, 0);
                }
                break;
                case MNU_TICTACTOE:
                {
                        ttt_board aboard;
                        ttt_check_win(aboard);
                }
                break;
                case MNU_CHG:
                {
                        cash_register reg;
                        change_requests reqs;
                        int num_requests = 0;
                        can_give_change(reg, reqs, num_requests);
                }
                break;
                case MNU_HELP:
                {
                        display_help();
                }
                break;
                default:
                {
                        error_output("invalid option selected.\n");
                }
        }
}

/**
 * simply calls printf to do the outputting to a file.
 **/
int normal_output(const char format[], ...)
{
        va_list vl;
        int result;
        va_start(vl, format);
        result = vprintf(format, vl);
        va_end(vl);
        return result;
}

/**
 * simply display a prefix of Error: then display whatever message(s) have
 * been passed in
 **/
int error_output(const char format[], ...)
{
        va_list vl;
        int result = 0;
        va_start(vl, format);
        result += fprintf(stderr, "Error: ");
        result = vfprintf(stderr, format, vl);
        va_end(vl);
        return result;
}
