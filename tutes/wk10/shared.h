#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#ifndef SHARED_H
#define SHARED_H

#define NAMELEN 20

/* the boolean type - we use this to return TRUE or FALSE from a function. 
 * Note: given that TRUE is defined as not FALSE, you shouldn't depend 
 * of TRUE being 1. You can however depend of FALSE being 0
 */
typedef enum { FALSE, TRUE } BOOLEAN;

/* a location on the gameboard as x and y coordinates */
struct location
{
        int x, y;
};

/* a move which is really a start and and end location. So a move is moving 
 * from one location to another
 */
struct move
{
        struct location start;
        struct location end;
};

#define MOVE_MIN 1
#define MOVE_MAX 8
#define UNUSED(X) (void)(X)
#define PUT_DASHES(N) \
{ \
        int count;\
        for(count = 0; count < ((int)(N)); ++count)\
        { \
                putchar('-');\
        }\
}

#endif
