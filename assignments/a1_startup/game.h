/***********************************************************************
* CPT220 - Programming in C
* Study Period 4 2017 Assignment #1 
* Full Name        : EDIT HERE
* Student Number   : EDIT HERE
* Start up code provided by Paul Miller
***********************************************************************/

#include <stdlib.h>
#include <time.h>

#include "gameboard.h"
#include "gameio.h"
#include "player.h"
#include "rules.h"

/**
 * The role of this module is for to manage the overall game. This means the 
 * management of the game initialization, game loop and finalization and ending
 * the game.
 **/

#ifndef GAME_H
#define GAME_H

/* this struct holds the game state at each moment */
struct game
{
        /**
         * the width / height of the board that is being played on
         **/
        int board_dimension;

        /**
         * the number in a row required to win a game
         **/
        int num_in_row;

        /**
         * the array of the actual player data
         **/
        struct player players[NUM_PLAYERS];

        /**
         * pointers to the current player and the other player. These are
         * used to manage whose turn it is.
         **/
        struct player* current;
        struct player* other;

        /**
         * the 2d game board. This is defined in the gameboard.c/h module
         **/
        gameboard board;

        /**
         * has the user decided to quit the game?
         **/
        BOOLEAN quit;
};

/**
 * "public" functions implemented for this module. Please see game.c for
 * comments and and explanation of how they work.
 **/
void swap_players(struct player**, struct player**);
void init_game(struct game*);
void play_game(void);

#endif /* GAME_H */
