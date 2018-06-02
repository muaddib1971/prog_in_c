/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2018.
 *****************************************************************************/
#include "board.h"
#include "io.h"
#include <limits.h>

/**
 * this file defines the player struct that keeps track of information about
 * each player as the game progresses.
 **/

#ifndef PLAYER_H
#define PLAYER_H
/* forwards declaration of the game struct so we can pointers to game passed in
 * as parameters in this module */
struct game;

/* the maximum length of a player's name */
#define NAMELEN 20

/* the player struct - represents a player in the game */
struct player
{
        /* the player's name */
        char name[NAMELEN + 1];
        /* their token type */
        enum cell token;
        /* a pointer to the current game - this allows us to not have to pass
         * this in as a parameter to functions that already have a pointer to
         * the player */
        struct game* curgame;
};

/**
 * publicly callable functiohs from this module
 **/
enum input_result init_player(struct player*, enum cell, struct game*, int);

enum input_result take_turn(struct player*);

#endif
