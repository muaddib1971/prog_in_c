/**************************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Assessed lab 1 - debugging
 * Created by Paul Miller
 *
 * This file provided the type definitions, constants and function 
 * prototypes for managing a card in a deck.
 *************************************************************************/
#include "shared.h"
#ifndef CARD_H
#define CARD_H
/* the number of suits in a deck */
#define NUM_SUITS 4
/* the number of faces in each suit from ACE counting up to KING */
#define NUM_FACES 13
/* the number of cards in a deck */
#define NUM_CARDS 52
/* the maximum length of a string to represent the face value of a card */
#define FACELEN 5
/* the maximum length of a string to represent the suit of a card */
#define SUITLEN 8
/* the number of cards each player gets */
#define HAND_SIZE 5

/* what are the different types of suit? */
enum suit
{
    HEARTS, DIAMONDS, CLUBS, SPADES
};

/* what are the different face values available in a suit? */
enum face
{
    ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN,
    KING
};

/* a card has a suit and a face value */
struct card
{
    enum suit suit;
    enum face face;
};

/** function prototypes **/

/* store the string representation for the suit of a card */
void suit(struct card card, char * name);
/* store the string representation for the face value of a card */
void face(struct card card, char * name);
/* print each individual card to the console as a string */
void printcard(struct card card);
#endif
