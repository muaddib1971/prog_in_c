/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2019.
 *****************************************************************************/
#include "rules.h"
#include "game.h"
#include "player.h"

#define MAX_ROLLS 4

void determine_player_order(struct game* thegame)
{
}

BOOLEAN validate_moves(const struct move selected_moves[], int num_moves,
                       const struct player* curplayer, const int dicerolls[],
                       struct move_pair changes[])
{
        return FALSE;
}

BOOLEAN apply_moves(const struct move_pair themoves[], int num_moves,
                    struct player* curplayer)
{
        return FALSE;
}

BOOLEAN has_won_game(const struct player* curplayer)
{
        return FALSE;
}
