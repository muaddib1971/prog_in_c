/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2018.
 *****************************************************************************/
#include "game.h"

/**
 * this file contains the implementation of functions for the management of the
 * game
 **/

/**
 * initialises the game to a starting state. You should select a random token
 * for one player and ensure the second player has a different token. You should
 * call init_player() passing in the address of the player, its token, and a
 * pointer to this game. Finally you should initialise the pointers to each
 * player ensuring that a random player is selected to play the game. You should
 * also ensure the board is coorectly initialised through a call to
 * init_board().
 **/
enum input_result init_game(struct game* newgame)
{
        return IR_FAILURE;
}

/**
 * manages the main game loop - calls init_game to initialise the game and
 * then loops and calls take_turn for the current player and swaps players until
 * a player has won the game
 **/
void play_game(void)
{
        /* the game struct that holds the data on the game state */
        struct game curgame;
        /* init the game struct */
        /* the main game loop */
        /* swap the game pointers */
}

/**
 * swaps the two player pointers for the two players playing the current game
 * (it's a way for us to swap who the current player is). Please note that an
 * implementation that swaps values rather than pointers will not get full marks
 * for this. This function is only worth a few marks but the intellectual
 * content understanding is very important and thus it is worth substantially
 * more than a few lines of code are worth elsewhere in this assignment.
 **/
void swap_players(struct player** first, struct player** second)
{
}

/**
 * implements the rules for the first round of the game, the so-called
 * swap2 rules. Please see the assignment specification and game rules for
 * further details.
 **/
enum input_result first_round(struct game* thegame)
{
        return IR_FAILURE;
}
