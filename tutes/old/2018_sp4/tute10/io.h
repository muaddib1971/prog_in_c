#include <stdio.h>
#include "bool.h"
#include <limits.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#ifndef IO_H
#define IO_H
#define LINELEN 80
#define EXTRACHARS 2
#define PUTLINE(CH, NUM)                                                       \
        {                                                                      \
                int count;                                                     \
                for (count = 0; count < (NUM); ++count)                        \
                {                                                              \
                        putchar(CH);                                           \
                }                                                              \
                putchar('\n');                                                 \
        }
BOOLEAN get_int(const char prompt[], int* output);
#endif
