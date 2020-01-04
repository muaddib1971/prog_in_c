#include "player.h"
/**
 * this function should initialise the player's data to default values (all 0)
 * and ask the player for their name. You should save their name to the player
 * struct. Note: I have added a playernum variable here so that you can 
 * distinguish between players. Please see the sample output in the assignment
 * specifications for expected behaviour here.
 **/
enum input_result player_init(struct player * newplayer, int playernum)
{
        char name[NAMELEN + EXTRA_CHARS];
        enum input_result result;
        char prompt[LINELEN + 1];
        sprintf(prompt, "Please enter the name of player %d: ", playernum);
        while(result = get_string_from_user(prompt, name, 
                                NAMELEN + EXTRA_CHARS),
                        result == IR_FAILURE)
        {
                fprintf(stderr, "input error. Please try again.\n");
        }
        if(result == IR_RTM)
        {
                return IR_RTM;
        }
        memset(newplayer, 0, sizeof(struct player));
        strcpy(newplayer->name, name);
        return IR_SUCCESS;
}

/**
 * This function handles each player's turn. In each turn, you should display
 * whose turn it is, their color and if you are implementing score tracking
 * the number of tokens they currently have on the board. You should then 
 * prompt them to enter their turn. You should then tokenize their input and
 * store the information in a struct move. This should then be passed into
 * apply_move() which will do the work of validating and applying the move.
 *
 * Note: it is your responsibility to ensure all operations and successful and
 * notify the user if they are not.
 **/
enum input_result player_turn(gameboard board, struct player * player)
{
        char move_str[MOVE_STR_LEN + EXTRA_CHARS];
        char * prompt = "Please enter a move in the form of x1,y1-x2,y2: ";
        struct move current_move;
        enum input_result result;

        printf("It is %s's turn and their tokens are %s in colour.\n"
                        "They currently have %d tokens.\n",
                        player->name, 
                        player->token_colour==CC_RED ? "red" : "white",
                        player->score
              );
        while(result = get_string_from_user(prompt, move_str,
                                MOVE_STR_LEN + EXTRA_CHARS),
                        result == IR_FAILURE)
        {
                fprintf(stderr, "Error in user input. Please try again.\n");
        }
        if(result == IR_RTM)
        {
                return IR_RTM;
        }
        if(!extract_move(&current_move, move_str))
        {
                fprintf(stderr, 
                                "Error: the move you entered was not valid.\n"
                                "Please try again.\n\n");
                return IR_FAILURE;
        }
        if(!is_valid_move((const enum cell_contents(*)[BOARDHEIGHT])board, 
                &current_move, player))
        {
                fprintf(stderr, "Error: That was not a valid move.\n\n");
                return IR_FAILURE;
        }
        apply_move(board, &current_move, player);
        return IR_SUCCESS;
}
