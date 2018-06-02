/**************************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Assessed lab 1 - debugging
 * Created by Paul Miller
 ***************************************************************************/
/**
 * @file swapper.h This file defines required constants and function
 * prototypes required by the swapper module which also contains the
 * main function.
 *
 * It also includes any header files that the main function will require.
 *************************************************************************/
#include "reader.h"
#include "writer.h"
/**
 * the number of arguments required to be passed into @ref main
 **/
#define NUM_ARGS 2
/**
 * the array offset into argv of the first file name passed in
 **/
#define FIRSTFILE 1
/**
 * the array offset into argv of the second file name passed in
 **/
#define SECONDFILE 1

/**
 * function that prints the contents of a buffer. A buffer is defined as 
 * a 2 dimensional array of char where each line is at a maximum 
 * @ref LINE_LEN in length.
 **/
void print_buffer(char[][LINE_LEN+1], size_t num_lines);
