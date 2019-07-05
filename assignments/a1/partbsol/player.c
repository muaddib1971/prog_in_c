/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2019.
 *****************************************************************************/
#include "player.h"
#include "game.h"

/**
 * do the work to initialise a player here. Please refer to the assignment
 * specifications for what you need to do here.
 **/
BOOLEAN player_init(struct player* aplayer, struct game* thegame)
{
        enum input_result iresult;
        char name[NAME_LEN + EXTRA_CHARS];
        /**
         * zero out the player struct
         **/
        memset(aplayer, 0, sizeof(*aplayer));
        /* set the bar_list to empty */
        barlist_init(&aplayer->bar_list);
        /**
         * read the player's name
         **/
        while (iresult = read_string("Please enter the name of the player",
                                     name, NAME_LEN),
               iresult == IR_FAILURE)
                ;
        /**
         * on ctrl-d or enter, return back to game_init()
         **/
        if (iresult == IR_QUIT || iresult == IR_SKIP_TURN)
        {
                return FALSE;
        }
        /**
         * copy in the name entered
         **/
        strcpy(aplayer->name, name);
        /**
         * set the game ponter for the player
         **/
        aplayer->curgame = thegame;
        return TRUE;
}

/**
 * implement the taking of a turn and turn validation in this function and
 * functions called from here. Please refer to the assignment specifications
 * for details on what you need to do here.
 **/
enum input_result player_take_turn(struct player* current_player)
{
        return IR_SUCCESS;
}
