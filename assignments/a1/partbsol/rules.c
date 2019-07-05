/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2019.
 *****************************************************************************/
#include "rules.h"
#include "game.h"
#include "player.h"

/**
 * this function determines the player order and player tokens, and direction
 * of play for the game.
 *
 * start by rolling two dice for each player. the player with the higher sum
 * of dice rolls will go first. Make them the current player in the game struct
 * and set their token to X and their color to white, and their direction to
 * clockwise. Set the other player pointer to point to the other player. Set
 * their direction to anticlockwise, their token to O and their color to
 * red.
 **/

void determine_player_order(struct game* thegame)
{
        /* using char to represent to dice roll as it saves space rather than
         * int */
        char dice_rolls[NUM_PLAYERS][NUM_DICE] = { { 0 } };
        int player_count;
        int roll_count;
        char roll_totals[NUM_PLAYERS] = { 0 };

        /**
         * keep rolling dice for each player until player has a roll total
         * larger than the other
         **/
        while (roll_totals[FIRST] == roll_totals[SECOND])
        {
                for (player_count = 0; player_count < NUM_PLAYERS;
                     ++player_count)
                {
                        /* do two dice rolls */
                        char* cur_rolls = dice_rolls[player_count];
                        for (roll_count = 0; roll_count < NUM_DICE;
                             ++roll_count)
                        {
                                dice_rolls[player_count][roll_count] =
                                    DICE_ROLL();
                        }
                        /* add the values for the two dice rolls */
                        roll_totals[player_count] =
                            cur_rolls[FIRST] + cur_rolls[SECOND];
                        /* print out the dice rolls for the current player */
                        normal_print("%s rolls a %d and a %d\n",
                                     thegame->players[player_count].name,
                                     cur_rolls[FIRST], cur_rolls[SECOND]);
                }
        }
        /* decide who the first player will be - the one with the higher
         * dice roll
         */
        if (roll_totals[FIRST] > roll_totals[SECOND])
        {
                thegame->current_player = &thegame->players[FIRST];
                thegame->other_player = &thegame->players[SECOND];
        }
        else
        {
                thegame->current_player = &thegame->players[SECOND];
                thegame->other_player = &thegame->players[FIRST];
        }
        /* set the properties for the first and second player for starting
         * the game
         */
        thegame->current_player->token = P_WHITE;
        thegame->other_player->token = P_RED;

        thegame->current_player->orientation = OR_CLOCKWISE;
        thegame->other_player->orientation = OR_ANTICLOCKWISE;
        /* print out the details of each player so we can see they have been
         * set
         */
        normal_print(
            "%s is playing first and their token colour is %swhite%s.\n",
            thegame->current_player->name, color_strings[COLOR_WHITE],
            color_strings[COLOR_RESET]);
        normal_print(
            "%s is the other player and their token color is %sred%s.\n",
            thegame->other_player->name, color_strings[COLOR_RED],
            color_strings[COLOR_RESET]);
}

/**
 * test for valid moves. Have a look at the assignment specifications for
 * full details. If a move is valid, you will have to add the move offsets to
 * the changes array so they can be applied in apply_moves.
 **/
BOOLEAN validate_moves(const struct move selected_moves[], int num_moves,
                       const struct player* curplayer, const int dicerolls[],
                       struct move_pair changes[])
{
        return FALSE;
}

/**
 * apply the moves listed in themoves. These are offset pairs that were inserted
 * in the "changes" array in the validate_moves() function.
 **/

BOOLEAN
apply_moves(const struct move_pair themoves[], int num_moves,
            struct player* curplayer)
{
        return FALSE;
}

/**
 * determines whether the player has won the game. the player has won the game
 * when they have no tokens on the board and there are no tokens in their bar
 * list.
 **/

BOOLEAN has_won_game(const struct player* curplayer)
{
        return FALSE;
}
