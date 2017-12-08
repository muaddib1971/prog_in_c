/***********************************************************************
* CPT220 - Programming in C
* Study Period 4 2017 Assignment #1 
* Full Name        : EDIT HERE
* Student Number   : EDIT HERE
* Start up code provided by Paul Miller
***********************************************************************/

#include "gameboard.h"
#include "gameio.h"
#include "shared.h"
#ifndef PLAYER_H
#define PLAYER_H

/**
 * The purpose of this module is the manage players in the game. Feel free
 * to add data types and functions to assist in managing of players to this
 * module.
 **/

/* forwards declaration of the game struct so we can have a pointer to it in
 * function declarations
 */
struct game;

/* the two types of players in the game */
enum player_type
{
        HUMAN,
        COMPUTER
};

/**
 * the player struct - each player has a name, a type, and a token enum. 
 * the player also has a pointer to the current game as a player really doesn't 
 * exist outside of a game.
 **/
struct player
{
        char name[NAMELEN + 1];
        enum player_type type;
        enum token token;
        struct game* thegame;
};

/**
 * a global array of the chars representing the contents of the game board. 
 * This is labelled extern as the memory is allocated elsewhere - this 
 * declaration just records the fact that there will be such an array.
 **/
extern const char token_chars[];

/**
 * the number of token chars in the token_chars array
 **/
#define NUMTOKENCHARS 3

/**
 * the public functions available from this module. Please see player.c for a 
 * description of each of these functions. 
 **/
void init_player(struct player*, enum player_type, struct game*);
void take_turn(struct player*);

#endif /* PLAYER_H */
