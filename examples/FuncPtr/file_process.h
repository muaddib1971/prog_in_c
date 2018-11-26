#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#ifndef FILEPROCESS
#define FILEPROCESS
#define EXTRACHARS 2
typedef enum
{
        FALSE,
        TRUE
} BOOLEAN;
void shuffle(char line[]);
void every_other(char line[]);
void shift(char line[]);
void quit(char linep[]);
int read_file(const char[], char * []);
BOOLEAN write_file(const char[], char * [], int);
void free_lines(char * [], int);
#endif
