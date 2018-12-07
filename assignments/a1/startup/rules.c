/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 4, 2018.
 *****************************************************************************/
#include "rules.h"
#include "game.h"

/**
 * validates that the move passed in would be legal if applied
 **/
BOOLEAN is_valid_move(const struct coordinate *coord, gameboard board) {
        return FALSE;
}

/**
 * applies the move to the board
 **/
void apply_move(const struct coordinate *coord, struct player *curplayer) {
}

/**
 * iterates over all locations on the board and counts up how many tokens
 * occur in a row. The score for the player shall be the maximum number of
 * their tokens in a row vertically, horizontally or diagonally from any
 * position on the board.
 **/
void calculate_score(struct player *curplayer) {
}

/**
 * tests for a winner by searching the board for any sequence that is greater
 * than or equal to the current player's token being wincount times in a row.
 **/
BOOLEAN is_winner(struct player *curplayer) {
        return FALSE;
}
