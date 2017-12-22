/***********************************************************************
* CPT220 - Programming in C
* Study Period 4 2017 Assignment #1
* Full Name        : EDIT HERE
* Student Number   : EDIT HERE
* Start up code provided by Paul Miller
***********************************************************************/

#include <ctype.h>
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "gameboard.h"
#include "shared.h"

/**
 * The role of this module is to provide a single place where all input and
 * output is performed from. The reason for doing this is firstly consistency
 * of input and output but also if we decided to change the way we are doing
 * input and output (such as the implementation of a graphical user interface,
 * we would only need to change this module).
 **/

#ifndef GAMEIO_H
#define GAMEIO_H

struct game;

/* the default line length is 80 chars */
#define LINELEN 80
/* trailing characters in a valid string returned from fgets() */
#define EXTRACHARS 2

/**
 * Add below the function prototypes for the public functions available from
 * gameio.c.
 **/
int print_error(const char format[], ...);
int print_message(const char format[], ...);
void display_board(struct game* thegame);
#endif /* GAMEIO_H */
