#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#ifndef FSUPPORT

#define FSUPPORT
/* functions that perform graceful opening of a file for reading
 * or writing
 */
FILE* gropen(char* infile);
FILE* gwopen(char* outfile);
/* the length of a line in the file */
#define LINELEN 8
/* the extra spaces required for fgets() */
#define EXTRASPACES 2
/* definition of the boolean datatype */
typedef enum
{
        FALSE,
        TRUE
} BOOLEAN;
/* close the files passed in */
void close_files(FILE*, FILE*);

/* functions that read and write the contents of a file to / from
 * memory
 */
BOOLEAN read_file(FILE*, char[][LINELEN + 1], int*);
BOOLEAN save_file(FILE*, char[][LINELEN + 1], int);
#endif
