#include <stdio.h>
#include <stdlib.h>
#include "fsupport.h"
#include "alternate.h"
/* number of arguments for a valid invocation of the program */
#define NUMARGS 2
/* the position of each argument in the argv array */
enum arg_position
{
    IN, OUT
};

void print_usage(void);

