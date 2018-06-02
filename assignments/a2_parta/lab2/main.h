#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stop.h"
#include "fsupport.h"


#define NUM_ARGS 3
enum arg_position
{
    INFILE, STOPFILE, OUTFILE
};

/* print how to use this program */
void print_usage(void);
