/**************************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Assessed lab 1 - debugging
 * Created by Paul Miller
 *
 * This file provides functions to manage a hand
 *************************************************************************/
#include "hand.h"
#include "poker.h"

/*************************************************************************
 * deal() - deal five cards off the top of the deck to the two players
 * passed in
 *
 * @param deck the array of cards to deal from
 * @param playerone the first player
 * @param playertwo the second player
 ************************************************************************/
void deal(struct card * deck, struct player playerone, 
    struct player playertwo)
{
    unsigned cardno = 0;
    /* iterate over the first ten cards in the deck, dealing one in turn
     * to each player
     */
    for(cardno = 0; cardno < HAND_SIZE; ++cardno)
    {
        dealcard(deck, playerone, cardno);
        dealcard(deck, playertwo, cardno);
    }
}

/**************************************************************************
 * deal a card to the appropriate player, stored in the index specified
 * by the cardno.
 *
 * @param deck the array of cards to deal from
 * @param player the player to deal the card to
 * @param cardno the index of the slot in the player's hand to store the
 * dealt card in.
 *************************************************************************/
void dealcard(struct card * deck, struct player player, unsigned cardno)
{
    /* the card that is dealt */
    struct card nextcard;
    /* stores the index of the last card that was dealt - it should be 
     * remembered in between each function call
     */
    static unsigned card_index;
    /* get the card to be dealt, and increment the card_index of the next
     * card to be dealt
     */
    nextcard = deck[card_index];
    /* store the card in the player's hand */
    player.hand[cardno]=nextcard;
}

/**************************************************************************
 * printhand() - print out the whole hand to the screen 
 **************************************************************************/
void printhand(struct player player)
{
    unsigned count;
    /* iterate over the hand, printing each individual card separated 
     * by a tab character
     */
    for(count = 0; count <= HAND_SIZE; ++count)
    {
        printcard(player.hand[count+1]);
        printf("\t");
    }
}
