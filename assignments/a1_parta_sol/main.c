#include "main.h"
#include "shared.h"

int main(void)
{
        BOOLEAN quit = FALSE;
        /* initialise the random number generator for all later calls. This
         * should be done exactly once in each program */
        srand(time(NULL));
        /**
         * in a loop, display the menu and prompt the user for their menu choice
         * and then perform that choice - either play a game or quit.
         **/
        while (!quit)
        {
                enum choice choice;
                display_menu();
                choice = get_menu_choice();
                switch (choice)
                {
                        case PLAY_GAME:
                                play_game();
                                break;
                        case QUIT_PROGRAM:
                                quit = TRUE;
                                break;
                        default:
                                print_error("invalid choice entered.\n");
                }
        }
        return EXIT_SUCCESS;
}
