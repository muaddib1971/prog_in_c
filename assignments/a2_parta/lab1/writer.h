/**************************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Assessed lab 1 - debugging
 * Created by Paul Miller
 **************************************************************************/
/**
 * @file writer.h This file provides some basic data types and
 * includes header files required for the whole project.
 **/

/* include any shared data structures and here */
#include "shared.h"
/**
 * writes the contents of the buffer passed in (contents) to the filename
 * specified.
 **/
BOOLEAN writefile(const char * filename, char contents[][LINE_LEN+1], 
    size_t num_lines);

