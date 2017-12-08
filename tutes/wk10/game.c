#include "game.h"

/**
 * This is the core of the game - it manages the game loop. This function 
 * should implement the algorithm specified under the "Play Game" assignment
 * specification.
 **/
struct player * play_game(struct player players[])
{
        gameboard board;
        int count;
        struct player * current, *other;
        BOOLEAN continuing = TRUE;
        int starting_player;
        int other_player;
        enum game_state gs_current;
        enum input_result result;
        struct player * winner = NULL, * loser = NULL;

        /* initialise the players */
        for(count = 0; count < NUM_PLAYERS; ++count)
        {
                if(result = player_init(&players[count], count + 1), 
                        result == IR_RTM)
                {
                        return NULL;
                }
        }
        /* randomize the player colours and who goes first */
        randomize_game(players, &starting_player);
        /* assign the first player based on colour - white should 
         * move first 
         */
        other_player = starting_player ? PO_FIRST_PLAYER : PO_SECOND_PLAYER; 
        current = &players[starting_player];
        other = &players[other_player];
        /* set up the game board */
        gameboard_init(board);
        /* calculate initial scores - both should be 12 at this point */
        calc_score(board, current);
        calc_score(board, other);
        /* actual game loop begins */
        while(continuing)
        {                
                /* display the board */
                gameboard_display(board);
                /* test if this player has no possible moves. If that's the
                 * case then quit the game
                 */
                if(gs_current = is_game_over(board,current),
                                gs_current != GS_CONTINUING)
                {
                        break;
                }
                /* have the player take their turn, including input 
                 * validation 
                 */
                while(result = player_turn(board, current), 
                                result == IR_FAILURE)
                {
			/* do nothing as adequate output is provided in 
			 * player_turn()
			 */
                }
                /* if the player has indicated they wish to quit the
                 * game, then we exit the loop
                 */
                if(result == IR_RTM)
                {
                        break;
                }
                /* calculate the score for the two players */
                calc_score(board, current);
                calc_score(board, other);
                /* change who the current player is */
                swap_players(&current, &other);
        }

        /* make sure the scores for the two players is up to date */
        finalise_scores(board, current, other);
        if(current->score == other->score)
        {
                gs_current = GS_DRAW;
        }
        /* based on the current game state, select the player who has 
         * won the game
         */
        switch(gs_current)
        {
                case GS_DRAW:
                        break;
                case GS_WON:
                        winner = current;
                        loser = other;
                        break;
                default:
                        winner = other;
                        loser = current;
        }
        /* if there was a winner, subtract the loser's token count
         * from the winner's token count
         */
        if(winner)
        {
                winner->score -= loser->score;
        }
        return winner;
}

/**
 * randomises the colours for the two players. As white always goes first, the
 * index of the players array that holds the player with the white token will
 * be returned through the curplayer pointer. That is, it is what we call an 
 * "out" parameter. Don't forget to SEED the random number generator ...
 **/
void randomize_game(struct player players[], /* out */ int * curplayer)
{
        int colour; 
        int other;
        /* seed the random number generator */
        srand(time(NULL));
        /* select a random colour to assign */
        colour = rand() % NUM_PLAYERS;
        /* return the random number selected to the calling function 
         * via the curplayer variable which is an "out" parameter 
         */
        *curplayer = colour;
        /* assign the colours */
        other = colour ?  PO_FIRST_PLAYER : PO_SECOND_PLAYER;
        players[colour].token_colour=CC_WHITE;
        players[other].token_colour=CC_RED;
}

/**
 * This function takes in pointers to the two player pointers used in play_game
 * and it swaps them. Some of you will find this requirement very hard. I do 
 * encourage you to work this through though as this technique is commonly used
 * in C. You may assume there will be a question on pointers to pointers on the
 * exam as well.
 **/
void swap_players(struct player ** current, struct player ** other)
{
        struct player * temp = *current;
        *current = *other;
        *other = temp;
}
