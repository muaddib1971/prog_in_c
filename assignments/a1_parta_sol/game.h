#include <stdlib.h>
#include <time.h>
#include <assert.h>

#include "gameboard.h"
#include "gameio.h"
#include "player.h"
#include "rules.h"

#ifndef GAME_H
#define GAME_H

/**
 * The role of this module is for to manage the overall game. This means the
 * management of the game initialization, game loop and finalization and ending
 * the game.
 **/

#define DIMENSION_PROMPT                                                       \
        "You can play tictactoe on a 3x3 board or a 5x5 "                      \
        "board.\nDo you want to play on a board the width of 3 or 5? "
#define NUM_IN_ROW_PROMPT "How many pieces in a row are required for a win? "

/* the valid range for the dimensions of the board */
enum allowed_dimensions
{
        DIM_LOW = 3,
        DIM_HIGH = 5
};
/**
 * specifies the order of the player - where are they in the player array?
 **/
enum player_order
{
        FIRST,
        SECOND
};

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
