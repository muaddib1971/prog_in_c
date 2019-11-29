#include "file_funcs.h"

#define NUMARGS 2
#define FILEARG argv[1]
void jumble(char*);
int main(int argc, char* argv[])
{
        /* the user's choice from the menu */
        enum menu_choice menu_result;
        /* a way we could implement a menu as array of structs where the first
         * element is the text for the menu item and the second element is a
         * function pointer */
        struct menu_item menu_items[NUM_MENU_OPTIONS] = {
                { "shuffle each line", shuffle },
                { "save every second char", every_other },
                { "shift all chars up by one value", shift },
                { "quit", quit }
        };

        /* check the number of command line arguments */
        if (argc != NUMARGS)
        {
                fprintf(stderr,
                        "Error: invalid number of command line arguments.\n");
                return EXIT_FAILURE;
        }
        /* ask the user what item they want to select from the menu */
        for (;;)
        {
                menu_result = menu(menu_items);
                menu_items[menu_result].act(FILEARG);
        }
        return EXIT_SUCCESS;
}

/**
 * display a menu and get the user to select the action they want from the menu.
 **/
enum menu_choice menu(struct menu_item items[])
{
        int count;
        int choice;
        enum input_result result;

        /* print out the menu */
        printf("enter your choice\n");
        printf("-----------------\n");
        for (count = 0; count < NUM_MENU_OPTIONS; ++count)
        {
                printf("%d) %s\n", count + 1, items[count].title);
        }
        /* get the choice from the user */
        while (result = get_int(&choice),
               result = FAILURE || choice > NUM_MENU_OPTIONS || choice <= 0)
        {
                fprintf(stderr, "Error: invalid choice selected.\n");
        }
        return choice - 1;
}

/**
 * buffer clearign code - call this whenever there is buffer overflow
 **/
static void read_rest_of_line(void)
{
        int ch;
        while (ch = getc(stdin), ch != '\n' && ch != EOF)
                ;
        clearerr(stdin);
}

/**
 * get a string from the user. That string must be a maximum of maxlen. The
 * array passed in must be at least maxlen+EXTRACHARS in length.
 **/
enum input_result get_string(char string[], int maxlen)
{
        /* read the string from the user - if a ctrl-d was pressed or enter was
         * pressed on an empty line, we just return the 'empty' constant */
        if (!fgets(string, maxlen + EXTRACHARS, stdin) || *string == '\n')
        {
                return EMPTY;
        }
        /* test for buffer overflow */
        if (string[strlen(string) - 1] != '\n')
        {
                fprintf(stderr, "Error: buffer overflow.\n");
                read_rest_of_line();
                return FAILURE;
        }
        /* all good so remove the newline char */
        string[strlen(string) - 1] = 0;
        return SUCCESS;
}

/**
 * retrieves a string from the keyboard and retrieves any integer data from
 * that string.
 **/
enum input_result get_int(int* result)
{
        char line[LINELEN + EXTRACHARS];
        enum input_result ir_result;
        long longresult;

        char* end;
        /* get the string from the keyboard */
        while (ir_result = get_string(line, LINELEN), ir_result == FAILURE)
                ;
        /* if there was no data entered, just pass that up */
        if (ir_result == EMPTY)
        {
                return EMPTY;
        }
        /* extract the numeric data */
        longresult = strtol(line, &end, DECIMAL);
        /* check if the number entered was numeric */
        while (isspace(*end))
        {
                ++end;
        }
        if (*end)
        {
                fprintf(stderr, "Error: non-numeric data entered.\n");
                return FAILURE;
        }
        /* check that the number is within the allowed ranger */
        if (longresult > INT_MAX || longresult < INT_MIN)
        {
                fprintf(stderr, "Error: value outside the range of an int.\n");
                return FAILURE;
        }
        *result = longresult;
        return SUCCESS;
}
