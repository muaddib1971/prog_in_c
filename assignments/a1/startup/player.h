/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2019.
 *****************************************************************************/
#include "bar_list.h"
#include "board.h"
#include "io.h"
#include "rules.h"

#ifndef PLAYER_H
#define PLAYER_H
/**
 * forwards declaration of the game struct so we can have pointers to a game
 * without knowing the internal details of a game struct.
 **/
struct game;
/**
 * The maximum length of a player name in the game.
 **/
#define NAME_LEN 20
/**
 * maximum prompt length needed for any part of the game
 **/
#define MAXPROMPTLEN 240

/**
 * definition of a player - they have a name, score, token (ie, colour),
 * a bar_list (that's the tokens that have been kicked off the board by
 * the oponent, a pointer to the current game (that just means we have
 * fewer variables to pass around), an orientation (which way around the board
 * that the player goes).
 **/
struct player
{
        char name[NAME_LEN + 1];
        int score;
        enum piece token;
        struct bar_list bar_list;
        struct game* curgame;
        enum orientation orientation;
};

/**
 * you may add your own data structures to this module
 **/

/**
 * end of the student's data structures for this module
 **/

/**
 * globally visible functions available and required to be implemented. You
 * may add your own if you see the need.
 **/
BOOLEAN
player_init(struct player*, struct game*);
enum input_result
player_take_turn(struct player*);
#endif
