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
 * initialises the menu - that is copies the required string values into the
 * provided menu array. Please note that hardcoding of array indexes here
 * will result in a 50% penalty on this requirement.
 **/
void init_menu(char menu[NUM_MENU_ITEMS][SCREENWIDTH + 1])
{
}

/**
 * displays the menu as specified by the assignment document. It must be
 * displayed exactly as outlined in the assignment specification.
 **/
void display_menu(char menu[NUM_MENU_ITEMS][SCREENWIDTH + 1])
{
}

/**
 * allows the user to select a menu item to run from the menu
 **/
enum menu_choice select_menu_item(char menu[NUM_MENU_ITEMS][SCREENWIDTH + 1])
{
        /* please note that this is a stub return value. You must delete this
         * comment and the return value below it or I will penalise for this */
        return MNU_INVAL;
}

/**
 * process input from the menu and launch each of the options
 **/
void menu_process_choice(enum menu_choice selected_choice)
{
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
