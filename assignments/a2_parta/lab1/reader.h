/**************************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Assessed lab 1 - debugging
 * Created by Paul Miller
 *************************************************************************/
/**
 * @file reader.h defines the function prototypes required for reading from a
 * file.
 **/
#include "shared.h"
/**
 *  reads the contents of the file specified by filename into an array up to the 
 * maxim number of lines specified.
 **/
BOOLEAN readfile(const char * filename, char contents[][LINE_LEN+1],
    size_t * num_lines);
