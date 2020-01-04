#include "shared.h"
#ifndef HELPERS_H
#define HELPERS_H
/*******************************************************************************
 * helpers.h: This module contains the function prototypes and data defintions
 * required for the helpers module. The Helpers module contains any functions
 * you implemented that don't fit nicely into one of the existing modules.
 ******************************************************************************/

#define PUTLINE(CH, LEN)                                                       \
        {                                                                      \
                int count;                                                     \
                for (count = 0; count < LEN; ++count)                          \
                {                                                              \
                        putchar(CH);                                           \
                }                                                              \
                putchar('\n');                                                 \
        }

/**
 * put the function prototypes for this module here.
 **/
#endif
