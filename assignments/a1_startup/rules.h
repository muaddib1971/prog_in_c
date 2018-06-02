/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2018.
 *****************************************************************************/
#include "board.h"
#include "shared.h"

/**
 * this module defines the rules of the game. This is separated into its own
 * file so we could easily create a different game just by changing the rules.
 **/

#ifndef RULES_H
#define RULES_H

/* forwards declaration of the game and player structs so we can use pointers to
 * them in this header file. In rule.c we will include the actual header files
 * so we can implement the functions for this module */
struct game;
struct player;

/* the number in a row required for a win */
#define NUMINROW 5

/* coordinate is an x-y pair that specifies a location on the board */
struct coordinate
{
        int x, y;
};

/**
 * publicly advertised functions for this module
 **/
BOOLEAN is_winner(const struct player*);

BOOLEAN move_is_valid(const struct player*, const struct coordinate*);

BOOLEAN apply_move(board, const struct coordinate*, enum cell);
#endif
