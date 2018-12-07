/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 4, 2018.
 *****************************************************************************/
#include "player.h"
#include "shared.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef SCORES_H
#define SCORES_H

/**
 * a socre entry on the score board
 **/
struct score {
        char player[NAMELEN + 1];
        int score;
};

/* maximum size of the scoreboard */
#define NUM_SCORES 10

/* functions to implement for this module. Please see scores.c for further
 * details.
 */
void scoreboard_init(struct score[]);
BOOLEAN scoreboard_add(struct score[], const struct player *);
void scoreboard_print(struct score[]);
#endif
