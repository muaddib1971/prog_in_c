/**************************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Assessed lab 1 - debugging
 * Created by Paul Miller
 *
 * This file simply has the main function for calling functions in other 
 * parts of the game.
 *************************************************************************/
#include "poker.h"
int main(void)
{
    /* the two players that 'play' the game */
    struct player playerone, playertwo;
    /* the deck of cards for the game */
    struct card deck[NUM_CARDS];
    /* the name of a player for user input */
    char name;
    /* initialise and shuffle the deck */
    create_deck(deck);
    shuffle(deck);
    /* print the contents of the deck */
    print_deck(deck);
    /* get the names for each player and store them in the appropriate 
     * struct
     */
    get_name(&name, "\nEnter the name for player one");
    strcpy(playerone.name, &name);
    get_name(&name, "\nEnter the name for player two");
    strcpy(playertwo.name, &name);
    /* deal the cards for the two players */
    deal(deck, playerone, playertwo);
    printf("and the hands: \n");
    /* print out their hands */
    printf("%s's hand: ", playerone.name);
    printhand(playerone);
    printf("\n%s's hand: ", playertwo.name);
    printhand(playertwo);
    printf("\n");
    /* all done! */
    return EXIT_SUCCESS;
}
