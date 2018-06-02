#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#ifndef FSUPPORT
#define FSUPPORT
#define MAXWIDTH 100
#define MAXSTOPLEN 20
#define EXTRASPACES 2
/* gracefully open a file for reading */
FILE* gropen( char * infile);
/* gracefully open a file for writing */
FILE* gwopen( char * outfile);
/* close open files */
void closefiles(FILE*,FILE*,FILE*);
/* tokenize a string and store the tokens in a 2d char array */
void tokenize( char *, char *, char[MAXSTOPLEN][MAXWIDTH], 
        unsigned*);
/* required to bring in the strdup function that is not part of the 
 * ansi standard
 */
char * strdup( char *);
/*definintion of the boolean type */
typedef enum
{
    FALSE, TRUE
} BOOLEAN;

#endif
