/***********************************************************************
* CPT220 - Programming in C
* Study Period 4 2017 Assignment #1 
* Full Name        : EDIT HERE
* Student Number   : EDIT HERE
* Start up code provided by Paul Miller
***********************************************************************/

#include "shared.h"

/**
 * this module manages the game rules for the game. It answers such questions as
 * whether the current game is over and whether a particular move is valid and 
 * that kind of thing. Feel free to add additional functions here to implement
 * the game rules. I would advise that it will be simpler to add lots of small
 * functions rather than having one or two big functions. It will be easier to
 * implement and easier to track down problems as and when they occur.
 **/

#ifndef RULES_H
#define RULES_H
/**
 * there are two players in each game
 **/
#define NUM_PLAYERS 2

/**
 * these are forwards declarations to structs required for pointers in the
 * public functions for this module
 **/
struct game;
struct coordinate;

/**
 * the minimum and maximum number required for tokens in a row for a win
 **/
#define MININROW 3
#define MAXINROW 5

/**
 * the various possible states for a game
 **/
enum state
{
        ONGOING,
        DRAW,
        WON
};

/**
 * the game_state struct contains the state of the game and if the game has
 * been won, the pointers to winner and loser will need to be set
 **/
struct game_state
{
        enum state state;
        struct player* winner;
        struct player* loser;
};

/**
 * these are the public functions available for this module. For a description
 * of what these do, please see the rules.c file. Please feel free to add more
 * if you find it necessary.
 **/
BOOLEAN apply_move(struct game*, const struct coordinate*);
struct game_state get_game_state(struct game*);
#endif /* RULES_H */
