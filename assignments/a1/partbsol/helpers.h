/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2019.
 *****************************************************************************/
#include "shared.h"
#include <errno.h>
#include <string.h>
#ifndef HELPERS_H
#define HELPERS_H

/**
 * you may add your own data structures for the helpers module here
 **/

/**
 * end of students data structures.
 **/

/**
 * public functions available from this module - feel free to add more of your
 * own
 **/
char* strdup(const char*);
char* fold(const char[]);
BOOLEAN get_move_strings(char * [], int*, const char[]);
struct move strtomove(const char[]);
BOOLEAN strtoint(int*, const char[]);
#endif
