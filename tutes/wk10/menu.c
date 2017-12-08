#include "menu.h"

BOOLEAN init_menu(struct menu_item menu[])
{

        int count;
        enum menu_choice numbers[] = 
        {
                MC_PLAY, MC_DISPLAY, MC_QUIT
        };
        /* the choices that a player can make */
        char * strings[] = {
                "Play Game", "Display Scores", "Quit"
        };
        /* array of function pointers -> */
        playfunc funcs[] = 
        {
                play_game, scoreboard_display, quit
        };
        for(count = 0; count < NUM_CHOICES; ++count)
        {
                menu[count].number = numbers[count];
                strcpy(menu[count].string, strings[count]);
                menu[count].func = funcs[count];
        }
        return TRUE;
}

struct menu_item get_menu_func(struct menu_item menu[])
{
        int count; 
        int input;
        for(count = 0; count < NUM_CHOICES; ++count)
        {
                printf("%d) %s\n", menu[count].number, 
                        menu[count].string);

        }
        /* get user input */
        while(get_int_from_user("Please enter your choice: ", &input) 
                != IR_SUCCESS);
        if(input < MIN_CHOICE || input > MAX_CHOICE)
        {
                fprintf(stderr, "Error: %d is not a valid input.\n"
                        "Please try again.\n\n", input);
                return get_menu_func(menu);
        }
        return menu[input-1];
}

struct player * quit(void)
{
        exit(EXIT_SUCCESS);
        return NULL;
}
