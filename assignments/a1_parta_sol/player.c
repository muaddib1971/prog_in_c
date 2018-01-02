#include "player.h"
#include "game.h"

/**
 * provides a mapping from tokens to chars for display
 **/
const char token_chars[NUMTOKENCHARS] = { ' ', 'O', 'X' };

/**
 * initialises a player based on user input and the game pointer passed into
 * the init_player function. We do this because there's no such thing as a
 * player outside of a game. If we did not do this we would have to pass thegame
 * into player every time we called a function in player.
 **/
void init_player(struct player* new_player, enum player_type type,
                 struct game* thegame)
{
        /* get the name of the player and store it */
        char name[NAMELEN + EXTRACHARS];
        char prompt[LINELEN + 1];
        enum input_result result;
        if (type == HUMAN)
        {
                /* initialise the prompt where are to send into the get_string()
                 * function */
                sprintf(prompt, "Please enter the name for the human player: ");
                while (result = read_string(prompt, name, NAMELEN),
                       result == IR_FAILURE)
                        ;
                strcpy(new_player->name, name);
                new_player->type = HUMAN;
        }
        else
        {
                /* for the computer player, set the name and player type as
                 * there's no need for anything else
                 */
                strcpy(new_player->name, "Computer");
                new_player->type = COMPUTER;
        }
        /* initalise any other data */
        new_player->thegame = thegame;
}

/**
 * This function handles turns for both human and computer players.
 *
 * In all cases, display the state of the board first.
 *
 * If this is a human player, prompt for their move validate it and if it
 * is valid, apply it. If it is not valid, reprompt until a valid ove is
 * entered.
 *
 * If this is a computer player, generate random x and y values for a move. Test
 * if the move is a valid move, apply it, otherwise try again generating a new
 * random x and y pair.
 **/
void take_turn(struct player* curplayer)
{
}
