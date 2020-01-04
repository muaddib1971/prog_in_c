#include "shared.h"
#include "gameboard.h"
#include "gamerules.h"
#include "utility.h"
#ifndef PLAYER_H
#define PLAYER_H
#define NUM_PLAYERS 2
#define MOVE_STR_LEN 7

/* we reuse the cell contents enumeration to mean the colour of the tokens
 * for a player. I try to avoid typedefs but I believe in this context it makes
 * sense.
 */
typedef enum cell_contents colour;

/* the player in a game - they have a name, a score and a token colour. Thes
 * should be initialised in player_init()
 */
struct player
{
        char name[NAMELEN + 1];
        int score; /* count of number of pieces on the board */
        colour token_colour;   
};

enum input_result player_init(struct player *, int);
enum input_result player_turn(gameboard, struct player *);
#endif
