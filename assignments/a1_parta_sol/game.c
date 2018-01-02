#include "game.h"
#include "rules.h"

/**
 * this function swaps the pointers to the two players in the game. It is the
 * code responsible for changing the current player. Please note that many
 * of you will find it difficult to figure out what to do for this function.
 * This is considered a high distinction requirement and as such not something
 * that everyone is expected to be able to do. For this reason, this function
 * is worth 5 bonus marks.
 **/
void swap_players(struct player** first, struct player** second)
{
}

/**
 * This function is responsible for the initialisation of the game (and thus
 * the game struct. First initialise all structures to be empty (including
 * players and the board. Next, ask the player for the player's name and assign
 * the token values to the players and also initialise the computer player,
 **/
void init_game(struct game* thegame)
{
        enum input_result result;
        BOOLEAN success = FALSE;
        /* zero out the structure */
        memset(thegame, 0, sizeof(struct game));
        /* prompt the user for the board dimension */
        while (!success)
        {
                /* prompt for the dimensions of the game board */
                result = read_int(DIMENSION_PROMPT, &thegame->board_dimension);
                if (result == IR_FAILURE)
                {
                        continue;
                }
                /* if the user presses ctrl-d or enter on a new line, prompt for
                 * whether the user wishes to quit */
                if (result == IR_RTM)
                {
                        /* confirm quitting the game */
                }
                /* test that the board dimensions are valid - 3x3 or 5x5 */
                if (!VALID_DIMENSION(thegame->board_dimension))
                {
                        print_error("%d is not a valid board dimension. "
                                    "Please try again.\n",
                                    thegame->board_dimension);
                        continue;
                }
                success = TRUE;
        }
        success = FALSE;
        /**
         * If a board size of 5 is selected, we prompt the user for the number
         * in a row that is required for a win. This can be 3,4, or 5 tokens.
         **/
        if (thegame->board_dimension == DIM_HIGH)
        {
                while (!success)
                {
                        result =
                            read_int(NUM_IN_ROW_PROMPT, &thegame->num_in_row);
                        if (result == IR_FAILURE)
                        {
                                continue;
                        }
                        if (result == IR_RTM)
                        {
                                /* confirm quitting the game */
                        }
                        if (!VALID_NUM_IN_ROW(thegame->num_in_row))
                        {
                                print_error("%d is not withing the allowed "
                                            "range for the number of tokens"
                                            "in a row. It must be 3, "
                                            "4 or 5.\n",
                                            thegame->num_in_row);
                                continue;
                        }
                        success = TRUE;
                }
        }
        else
        {
                /* for a board of 3x3, the number in a required for a win is
                 * always 3 */
                thegame->num_in_row = thegame->board_dimension;
        }
        /* select the player order and token randomly */
        if (rand() % NUM_PLAYERS == FIRST)
        {
                thegame->current = &thegame->players[FIRST];
                thegame->other = &thegame->players[SECOND];
        }
        else
        {
                thegame->current = &thegame->players[SECOND];
                thegame->other = &thegame->players[FIRST];
        }
        thegame->current->token = NOUGHT;
        thegame->other->token = CROSS;
        /* initialise the game board */
        gameboard_init(thegame->board);

        /* initialise the first player in the array as a human player and the
         * second player in the array as computer. This does NOT determine which
         * player goes first due to earlier randomisation */
        init_player(thegame->players + FIRST, HUMAN, thegame);
        init_player(thegame->players + SECOND, COMPUTER, thegame);
}

/**
 * the main function that manages the game loop
 **/
void play_game(void)
{
        struct game thegame;

        /* set the initial values of the game "object" */
        init_game(&thegame);
        display_board(&thegame);
}
