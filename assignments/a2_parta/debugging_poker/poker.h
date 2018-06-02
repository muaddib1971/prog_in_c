/**************************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Assessed lab 1 - debugging
 * Created by Paul Miller
 *
 * defines any additional data structures required for the main function
 * defined in poker.c
 *************************************************************************/
#include "hand.h"
#include "deck.h"
#include "input.h"
/* defines  player as having a name and a current hand  of cards */
struct player
{
    char name[NAMELEN];
    struct card hand[HAND_SIZE+1];
};
