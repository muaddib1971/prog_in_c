/**************************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Assessed lab 1 - debugging
 * Created by Paul Miller
 *
 * defines any data structures and constants needed for managing a hand
 * as well as any function prototypes required.
 *************************************************************************/
#include "card.h"

/* forwards declaration of a player as most functions in this module need
 * this and it avoids circular includes
 */
struct player;
/* deal 5 cards to each player from the top of the deck */
void deal(struct card * deck, struct player playerone, 
    struct player playertwo);
/* handle the dealing of each individual card */
void dealcard(struct card * deck, struct player playerone, 
    unsigned cardno);
/* print out a player's hand */
void printhand(struct player player);
