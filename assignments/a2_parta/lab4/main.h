#include <stdlib.h>
#include <stdio.h>
#include "fsupport.h"
#include "reverse.h"

/* how many command line arguments are expected to be passed in ? */
#define NUMARGS 2

/* enumeration that defines what the argument in each position of 
 * argv means
 */
enum arg_position
{
    INPUT, OUTPUT
};

/* print a message explaining how to use the program */
void print_usage(void);
