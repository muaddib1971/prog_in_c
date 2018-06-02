/**************************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Assessed lab 1 - debugging
 * Created by Paul Miller
 *
 * This file provided the type definitions, constants and function 
 * prototypes for managing a card deck.
 *************************************************************************/
#include "card.h"
#include <time.h>
/* populate a deck with cards */
void create_deck(struct card * deck);
/* output the cards in the order they appear in the deck */
void print_deck(struct card * deck);
/* shuffle the deck of cards */
void shuffle(struct card * deck);
