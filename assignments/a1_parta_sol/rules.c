#include "rules.h"
#include "game.h"

/**
 * defines whether a game is over. I handle all boards in the same way using
 * constants and variables that have been designed for the game
 **/
struct game_state get_game_state(struct game* thegame)
{
        struct game_state cur_game_state = { ONGOING, NULL, NULL };
        return cur_game_state;
}

/**
 * tests if a move is valid and if it is then it applies the move to the
 * gameboard and otherwise it returns FALSE
 **/
BOOLEAN
apply_move(struct game* thegame, const struct coordinate* coord)
{
        return FALSE;
}
