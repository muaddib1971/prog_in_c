/**************************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Assessed lab 1 - debugging
 * Created by Paul Miller
 *
 * This file provides the functions for the manipulating a deck of cards.
 *************************************************************************/
#include "deck.h"

/*************************************************************************
 * initializes the array of cards (the deck) so that there is one of each
 * valid card (ace to king, and all suits).
 * @param deck: an array of struct card that will be initialised to be a 
 * complete deck.
 ************************************************************************/
void create_deck(struct card * deck)
{
    unsigned suit_count, face_count;
    unsigned curr_card = 0;

    /* iterate over all suits and face values, inserting them into the 
     * deck 
     */
    for(suit_count = 0; suit_count < NUM_SUITS; ++suit_count)
    {
        for(face_count = 0; face_count < NUM_FACES; ++face_count)
        {
            /* create the card */
            struct card card;
            /* initialise its suit and face value */
            card.suit = suit_count;
            card.face = face_count;
            /* insert it into the deck */
            deck[curr_card] = card;

        }
    }
}

/**************************************************************************
 * shuffle() - shuffle a deck of cards so that they are in a pseudorandom
 * order.
 * 
 * @param deck an array of 52 cards that needs to be shuffled. You may 
 * assume that they are all unique cards.
 *************************************************************************/
void shuffle(struct card * deck)
{
    unsigned count;
    unsigned swap_index;
    struct card swap;
    /* seed the random number generator - time will give us a unique number
     * each time we call it assuming we don't call it twice in the 
     * same second
     */
    srand(time(NULL));
    /* iterate over the first half of the cards and swap each card with 
     * another card that is randomly chosen
     */
    for(count = 0; count < NUM_CARDS/2; ++count)
    {
        /* generate the index of the card to swap with */
        swap_index = rand() % NUM_CARDS;
        /* swap the cards using a standard swap algorithm */
        swap = deck[swap_index];
        deck[swap_index]=deck[count];
        deck[swap_index]=swap;
    }
}

/**************************************************************************
 * print_deck() - iterate over the deck, printing each card to the 
 * console.
 *
 * @param deck the array holding all cards that represents the deck.
 *************************************************************************/
void print_deck(struct card * deck)
{
    unsigned count;
    /* iterate over each array element and print the card */
    for(count = 0; count < NUM_CARDS; ++count)
    {
        printcard(deck[count]);
        printf("\n");
    }
}
