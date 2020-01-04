#include "bool.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#ifndef HELPERS_H
#define HELPERS_H
#define LINELEN 80
#define EXTRACHARS 2
enum input_result
{
        FAILURE, SUCCESS, RTM
};
enum input_result get_string(const char [], char[], size_t); 
#endif
