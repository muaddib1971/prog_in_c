/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2018.
 *****************************************************************************/
#include "player.h"

/**
 * defines the data structures and the function for manipulating the scoreboard
 **/

#ifndef SCOREBOARD_H
#define SCOREBOARD_H

/**
 * A Score in the scoreboard. We store the names of the winner and the loser and
 * how many moves it took to win
 **/
struct score
{
        char winner[NAMELEN + 1];
        char loser[NAMELEN + 1];
        int moves;
};

/**
 * the number of scores that can be stored on the scoreboard.
 **/
#define MAX_SCORES 10

/**
 * The scoreboard data structure - basically a fixed sized array list.
 **/
struct scoreboard
{
        struct score scores[MAX_SCORES];
        int num_scores;
};

/**
 * public functions advertised for this module
 **/
void init_scoreboard(struct scoreboard*);

BOOLEAN add_to_scoreboard(struct scoreboard*, struct player[], struct player*);

void display_scoreboard(struct scoreboard*);
#endif /* SCOREBOARD_H */
