#include "shared.h"
#include "gameboard.h"
#include "gamerules.h"
#include "player.h"
#include <time.h>

#ifndef GAME_H
#define GAME_H
enum player_order
{
        PO_FIRST_PLAYER, PO_SECOND_PLAYER
};
struct player * play_game(struct player []);
void randomize_game(struct player[], int * curplayer);
void swap_players(struct player ** current, struct player ** other);
#endif /* GAME_H */
