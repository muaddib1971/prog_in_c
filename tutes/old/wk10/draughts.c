#include "draughts.h"
#include "menu.h"
/**
 * The starting point for the application. You should have a loop where you
 * prompt the user of your program what their menu choice and based on 
 * their choice, call play_game() to start a game, call display_scores()
 * to display the scoreboard or quit the program.
 **/
int main(void)
{
        /* the scoreboard that keeps track of all the winners of games 
         * played
         */
        scoreboard scboard;
        struct menu_item menu[NUM_CHOICES];
        /* the players to play the game */
        struct player players[NUM_PLAYERS],
                      /* a pointer to the winner of the last game played */
                      *winner;
        struct menu_item choice;
        /* initialise the scoreboard to empty */
        scoreboard_init(scboard);

        init_menu(menu);

        while(choice.number != MC_QUIT)
        {
                BOOLEAN play_again = TRUE;
                /* display menu */

                choice = get_menu_func(menu);
                switch(choice.number)
                {
                        /* perform the user's choice */
                        case MC_PLAY:
                                /* if there was a winner, add them to the 
                                 * scoreboard */
                                while(play_again)
                                {
                                        winner = choice.func(players);
                                        if(winner)
                                        {
                                                process_add_to_scoreboard(
                                                                scboard, 
                                                                winner);
                                        }
                                        play_again = check_play_again();
                                }
                                break;
                        case MC_DISPLAY:
                                /* display the scoreboard */
                                choice.func(scboard);
                                break;
                        case MC_QUIT:
                                /* quit the game */
                                choice.func(NULL);
                                break;
                        default:
                                printf("%d\n", choice.number);
                                /* we should never get here */
                                assert(FALSE);
                }
        }
        return EXIT_SUCCESS;
}

/**
 * checks if the player wishes to play again or not.
 **/
BOOLEAN check_play_again(void)
{
        char input[P_AGAIN_RESP_LEN + EXTRA_CHARS];
        char response;
        enum input_result result;

        /* get response from the user - do any buffer handling required */
        while(result = get_string_from_user("Do you wish to play "
                                "again (y/n) ? ", input, 
                                P_AGAIN_RESP_LEN + EXTRA_CHARS),
                        result == IR_FAILURE)
        {
                fprintf(stderr, "Error: invalid input. Please try again.\n"
                       );
        }
        /* check for a valid response */
        response = *input;
        if(response != 'y' && response != 'Y' && response != 'n' && 
                        response != 'N')
        {
                fprintf(stderr, "Error: y or n required. Please try again."
                                "\n");
                return check_play_again();
        }
        /* return a code based on the response entered */
        return response == 'y' || response =='Y';
}

/**
 * this function is simply a helper function to cut down on the code in 
 * main. It adds the player to the scoreboard and validates that the 
 * action was successful. 
 **/
void process_add_to_scoreboard(scoreboard scboard, struct player * winner)
{
        if(!scoreboard_add(scboard, winner))
        {
                fprintf(stderr, "Failed to add to scoreboard.\n");
        }
}

/**
 * This function just formats and displays the main menu to be used in this
 * program.
 **/
#if 0
static void display_menu(void)
{

#define MENU_HEADING "Welcome to English Draughts"
        int count;
        putchar('\n');
        /* display heading and underline it */
        puts(MENU_HEADING);
        PUT_DASHES(strlen(MENU_HEADING));
        /* newline at end of heading */
        putchar('\n');
        /* display the menu options */
        for(count = 0; count < NUM_CHOICES; ++count)
        {
                printf("%d %s\n", count + 1, choices[count]);
        }
}
#endif

