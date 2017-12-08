#include "game.h"
#include "utility.h"
#include "scoreboard.h"
#include "menu.h"
#ifndef DRAUGHTS_H
#define DRAUGHTS_H

#define P_AGAIN_RESP_LEN 1

/* enum menu_choice get_choice(void); */

void process_add_to_scoreboard(scoreboard, struct player * );
BOOLEAN check_play_again(void);

#endif
