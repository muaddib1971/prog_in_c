/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 4, 2018.
 *****************************************************************************/
#include "board.h"
#include "helpers.h"
#include "io.h"
#include <stdio.h>
#include <string.h>

#ifndef PLAYER_H
#define PLAYER_H

/**
 * data structure definitions for the player module
 **/
#define NAMELEN 20

/**
 * predeclare the game struct so that we can use pointers to it in this header
 * file
 **/
struct game;

/**
 * data structure to represent the details on each player. A player shall have
 * a name, a current score (maximum number of their token in a row) as well as
 * their token colour. We also store a pointer to the game as that way we don't
 *
 **/
struct player {
        char name[NAMELEN + 1];
        int score;
        enum cell token;
        struct game* curr_game;
};

enum input_result player_init(struct player*, int, struct game*);
enum input_result player_turn(struct player*);
#endif
