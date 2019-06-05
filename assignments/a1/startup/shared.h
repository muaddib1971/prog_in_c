/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2019.
 *****************************************************************************/
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#ifndef SHARED_H
#define SHARED_H
/**
 * The boolean type - defines values for FALSE (0) and TRUE (1)
 **/
typedef enum
{
        FALSE,
        TRUE
} BOOLEAN;

/**
 * in some places I might want to return FALSE when something fails but
 * also a number when it succeeds
 **/
struct falsible_long
{
        long thelong;
        BOOLEAN success;
};

/**
 * which way around the board do we go? I've provided it here because it
 * was needed in several different places in the program
 **/
enum orientation
{
        OR_CLOCKWISE,
        OR_ANTICLOCKWISE
};

/**
 * a move has an index on the board it starts at and a count of how many
 * places to move the piece
 **/
struct move
{
        int index, count;
};
extern const struct move error_move;
#endif
