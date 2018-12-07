/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 4, 2018.
 *****************************************************************************/
#include "board.h"
#include "player.h"
#include "rules.h"
#include "shared.h"
#include <stdlib.h>
#include <time.h>

/* protect the contents of this header file from multiple inclusion */
#ifndef GAME_H
#define GAME_H

/**
 * the game struct that stores the state of the game
 **/
struct game {
        gameboard board;
        int wincount;
        struct player* players;
        struct player* current;
        struct player* other;
};

/**
 * there are two players for each game
 **/
#define NUMPLAYERS 2

/**
 * functions implemented for this module. For more information, see the comments
 * in the .c file
 **/

BOOLEAN init_game(struct game*);

struct player* play_game(struct player[]);

void swap_players(struct player**, struct player**);

#endif /* end of include guard */
