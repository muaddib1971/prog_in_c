/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 4, 2018.
 *****************************************************************************/
#include "shared.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

#ifndef BOARD_H
#define BOARD_H
/**
 * possible values for a board cell: red player holds it, blue player holds it,
 * it might be blank. Invalid value is at the end of each enum for the purposes
 * of use in a switch statement - -1 always represents an invalid value in my
 * enumerations.
 **/
enum cell { C_NOUGHT, C_CROSS, C_BLANK, C_INVALID = EOF };

/**
 * the board is always 6 x 6 for all boards in this game.
 **/
#define BOARDHEIGHT 8
#define BOARDWIDTH BOARDHEIGHT

/**
 * the board type is simply an alias to a 2d array of cell being BOARDHEIGHT X
 * BOARDWIDTH in dimensions. For iteration purposes, it is more efficient for
 * the height to be specified first as it means a normal iteration over the
 * board is a strict iteration over sequential memory.
 **/
typedef enum cell gameboard[BOARDHEIGHT][BOARDWIDTH];

/**
 * functions defined for the board type. Full documentation of the type is
 * included in the .c module and further information is also provided in the
 * assignment specification.
 **/
void board_init(gameboard);

#endif /* BOARD_H */
