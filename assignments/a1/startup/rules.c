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

#define MAX_ROLLS 4

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
BOOLEAN apply_moves(const struct move_pair themoves[], int num_moves,
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
