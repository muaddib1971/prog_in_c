/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 4, 2018.
 *****************************************************************************/
#include "board.h"
#include "shared.h"
#include <math.h>
#include <stdarg.h>
#ifndef RULES_H
#define RULES_H

struct game;
struct player;

struct coordinate {
        int x, y;
};

BOOLEAN is_valid_move(const struct coordinate *, gameboard);

void apply_move(const struct coordinate *, struct player *);

BOOLEAN is_winner(struct player *);

void calculate_score(struct player *);
#endif
