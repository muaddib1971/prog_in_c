/**************************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Assessed lab 1 - debugging
 * Created by Paul Miller
 *
 * This file provides the functions for the manipulating a card.
 *************************************************************************/
#include "card.h"


/**************************************************************************
 * suit() - stores a string representation of the card's suit in the 
 * name variable passed in. 
 *
 * @param card the card from which we want to extract the suit.
 * @param name the array to store the name of the suit in.
 *************************************************************************/
void suit(struct card card, char * name)
{
    /* the array of strings that represent the string values for 
     * each suit.
     */
    char * suits[NUM_SUITS] =
    {
        "HEARTS", "DIAMONDS", "CLUBS", "SPADES"
    };
    /* simply copy the string in the appropriate array element into name
     * and we are done!
     */
    strcpy(name, suits[card.suit-1]);
}

/**************************************************************************
 * face() - stores a string representation of the card's face value in the 
 * name variable passed in.
 *
 * @param card the card from which we want to extract the face value.
 * @param name the array to store the name of the face value in.
 *************************************************************************/
void face(struct card card, char * name)
{
    /* array of strings that hold the string representations of each 
     * face value
     */
    char * faces[NUM_FACES] = 
    {
        "ACE", "TWO", "THREE", "FOUR", "FIVE", "SIX",
        "SEVEN", "EIGHT", "NINE", "TEN", "JACK", "QUEEN", "KING"
    };
    /* just copy the string related to the face value from the above array
     * and we are done!
     */
    strcpy(name, faces[card.face-1]);
}

/**************************************************************************
 * printcard() - print out a card's data by extracting the strings for 
 * the suit and face and printing these to the console.
 *
 * @param card the card we wish to print out.
 *************************************************************************/
void printcard(struct card card)
{
    char suit_name[SUITLEN+1];
    char face_name[FACELEN+1];
    /* extract the suit and face as strings */
    suit(card, suit_name);
    face(card, face_name);
    /* print out the data we have extracted */
    printf("%s of %s", face_name, suit_name);
}
