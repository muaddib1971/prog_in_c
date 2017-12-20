/***********************************************************************
* CPT220 - Programming in C
* Study Period 4 2017 Assignment #1 
* Full Name        : EDIT HERE
* Student Number   : EDIT HERE
* Start up code provided by Paul Miller
***********************************************************************/

#include "shared.h"
#include <string.h>

/**
 * This module is provided to help you manage the gameboard. All functions and 
 * data types introduced by you here should be consistent with that aim. 
 **/

/* include guard ensuring this module is included onces for every .c file */
#ifndef BOARD_H
#define BOARD_H

/* the width and height of the game board array */
#define MAXWIDTH 5
#define MAXHEIGHT 5



/**
 * defines the gameboard type which is just an alias for a 2d array of enum
 * token
 **/
typedef enum token gameboard[MAXHEIGHT][MAXWIDTH];

/**
 * public functions for this module. Please see gameboard.c for further details
 **/
void gameboard_init(gameboard);
#endif /* BOARD_H */
