/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2018.
 *****************************************************************************/
#include "board.h"
#include "player.h"
#include "rules.h"

/**
 * This .h file and the accompanying .c file (game.c) manage the overall game.
 * Key to this is the game struct. The key data structures that don't have a
 * file of their own are defined here. This module also manages the game loop
 * which is the key to progress of the game.
 **/

#ifndef GAME_H

#define GAME_H
#define NUM_PLAYERS 2

/**
 * the game struct defines the information about the game state that is passed
 *to the various functions that are part of the implementation of a game.
 **/
struct game
{
        struct player players[NUM_PLAYERS];
        board gameboard;
        struct player* current, *other;
};

/**
 * public interface specifications for functions implemented in this module
 **/
enum input_result init_game(struct game*, struct player[]);

play_game(void);

enum input_result first_round(struct game*);

void swap_players(struct player**, struct player**);

#endif
