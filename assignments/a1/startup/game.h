/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2019.
 *****************************************************************************/
#include "board.h"
#include "io.h"
#include "player.h"
#include "rules.h"
#include <time.h>

#ifndef GAME_H
#define GAME_H
#define NUM_PLAYERS 2

/**
 * the game struct which is the core data structure for our program.
 *
 * There is the array of players which stores the actual player data, the
 * game board, pointers to the current player (player having their turn) and
 * the other player which you can use to manage whose turn it is, and the
 * seed which is the random seed - the startup value for the random number
 * generator.
 **/
struct game
{
        struct player players[NUM_PLAYERS];
        board game_board;
        struct player* current_player;
        struct player* other_player;
        long seed;
};

/**
 * in many places in the program, we need to specify arrays with pairs such
 * as players, dice, etc. I found this enum useful to refer to the first and
 * second value without introducing magic numbers. You don't have to use this
 * enum (you could get a HD without it) but it would be a good practice to do
 * so.
 **/
enum
{
        FIRST,
        SECOND
};

/**
 * You may add more datastructures to this module here
 **/

/**
 * end of student's added data structures
 **/

/**
 * global functions you will need to implement to complete this module. You
 * may feel the need to add more functions and you should feel free to do so.
 **/
BOOLEAN
game_init(struct game* thegame);
void play_game(struct falsible_long);
void
swap_players(struct player**, struct player**);
#endif
