#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include "fsupport.h"

#ifndef STOP_H
#define STOP_H
/* the maximum number of stopwords stored by the system */
#define MAXSTOPWORDS 1024
/* the maximum length of a stop word */
#define MAXSTOPLEN 20
/* definition of an EOF constant as a long */
#define EOFL -1L
/* if errno equals this value the last operation was a success */
#define NO_ERROR 0
#define DELIMS " .,;:'-!~`=+/\\\"\n"

/* reads in the stop list from a file */
long get_stop_list( FILE* stop_file, char stoplist [][ MAXSTOPLEN ] );
/* filters the input file's contents for the stop words and writes them to
 * the output file 
 */
void stop_me( FILE* infile, FILE* outfile, 
        char stoplist [][ MAXSTOPLEN ] , unsigned stopcount );
/* tests if a word is a stop word - that is if it is in the list of stop
 * words that have been read in
 */
BOOLEAN is_stop(char *, char[][ MAXSTOPLEN ] , unsigned stopcount );
#endif
