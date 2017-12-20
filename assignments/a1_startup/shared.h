/***********************************************************************
* CPT220 - Programming in C
* Study Period 4 2017 Assignment #1
* Full Name        : EDIT HERE
* Student Number   : EDIT HERE
* Start up code provided by Paul Miller
***********************************************************************/

#ifndef SHARED_H
#define SHARED_H

/**
 * this file is provided for any global types that need to be defined and
 * available from all places in the application. No other files should be
 * included in this file as that might creat some recursive includes
 **/

/**
 * the BOOLEAN type - defines TRUE and FALSE
 **/
typedef enum
{
        FALSE,
        TRUE
} BOOLEAN;


/**
 * the maximum length of a player name is 20 chars
 **/
#define NAMELEN 20

/**
 * the token values for the gameboard
 **/
enum token
{
        EMPTY,
        NOUGHT,
        CROSS
};

/**
 * defines a location on the game board as an X and Y pair. Being the offset
 * into the horizontal and vertical dimensions of the board
 **/
struct coordinate
{
        int x, y;
};

/**
 * struct coordinate coord;
 * coord.x = 2;
 * coord.y=1;
 **/

#endif /* SHARED_D */
