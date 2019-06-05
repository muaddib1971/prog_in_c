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
#include "shared.h"
#ifndef RULES_H
#define RULES_H
/**
 * forwards declarations that allow us to have pointers to the type specified
 * (game or player).
 **/
struct game;
struct player;
#define MAX_MOVES 4

/**
 * the direction a piece should be placed. So from bottom we build the pieces
 * upwards and from the top we add the pieces downwards.
 **/
enum direction
{
        DIR_UP,
        DIR_DOWN
};

/**
 * a piece location is a combination of the x and y values for a piece and the
 * direction that the pieces are built in a column. y is always 0 or 13 for
 * the top or bottom of the board - so if y is 0 then direction must be
 * DIR_DOWN and likewise when y is 13, direction must be DIR_UP. This may seem
 * complicated but I found this simpler to work with.
 **/
struct piece_location
{
        int x, y;
        enum direction direction;
};

/**
 * a move_pair represents the start and the end of a move - so the start column,
 * start y and direction for the opposite ends of a move
 **/
struct move_pair
{
        struct piece_location start;
        struct piece_location end;
};

/**
 * You may provide your own data type declarations here for this module
 **/

/**
 * end of the student's data type declarations
 **/

/**
 * functions that you will need to implement in rules.c
 **/
void determine_player_order(struct game *);
BOOLEAN validate_moves(const struct move[], int, const struct player *,
                       const int[], struct move_pair[]);
BOOLEAN apply_moves(const struct move_pair[], int, struct player *);
BOOLEAN has_won_game(const struct player *);
#endif
