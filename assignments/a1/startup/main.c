/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 4, 2018.
 *****************************************************************************/
#include "main.h"
int main(void) {
        /**
         * allocation of players they are available after the end of the game.
         * Please note we are required to do this as items on the system
         * stack are removed once we leave the block in which they were
         * allocted.
         **/
        struct player players[NUMPLAYERS];
        /* pointer to the winner - at the end of the game if this is not NULL,
         * this is the winner of the game just played
         */
        struct player *winner;
        /* scoreboard for the program - add winners to this scoreboard */
        struct score scores[NUM_SCORES];
        /* initialise the scores */
        scoreboard_init(scores);
        /* repeatedly display the menu until the decision is made to quit.
         * Allow the options to play the game, display high scores or
         * quit
         */
        return EXIT_SUCCESS;
}
