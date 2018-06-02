/**************************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Assessed lab 1 - debugging
 * Created by Paul Miller
 *************************************************************************/
/**
 * @file defines the shared constants and datatypes required for all
 * source files in the program
 **/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef SHARED_H
#define SHARED_H
/**
 * a boolean type we can use to return success or failure of operations
 **/
typedef enum { FALSE=1, TRUE } BOOLEAN;
/**
 * the maximum line length in the file being read in
 **/
#define LINE_LEN 80
/**
 * the characters at the end of a string read in from fgets, namely 
 * \\n and \\0.
 **/
#define EXTRA_CHARS 2
#endif
