#include "shared.h"
#include "player.h"

#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#define MAXNUMSCORES 10

struct score
{
        char name[NAMELEN + 1];
        int value;
};

typedef struct score scoreboard[MAXNUMSCORES];

void scoreboard_init(scoreboard);
struct player * scoreboard_add(scoreboard, struct player *);
void scoreboard_display(scoreboard);
#endif /* SCOREBOARD_H */
