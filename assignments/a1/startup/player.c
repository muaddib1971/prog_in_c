/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 4, 2018.
 *****************************************************************************/
#include "player.h"
#include "game.h"

/**
 * initialise the player by prompting and reading the player's name from
 * the keyboard. Set the rest of the elements of the player struct to sensible
 * values. and capture the game pointer in the player's game pointer so we
 * don't have to repeatedly pass it around later.
 **/
enum input_result player_init(struct player* curplayer, int playernum,
                              struct game* curgame) {
        return IR_FAILURE;
}

/**
 * Prints out the current board and whose turn it is.  It then
 * handles input (and validation of input) for a turn. It then checks if the
 * the move requested is valid and if it is it applies it. For most of these
 * actions, a function should be called in another module.
 **/
enum input_result player_turn(struct player* curplayer) {
        return IR_FAILURE;
}
