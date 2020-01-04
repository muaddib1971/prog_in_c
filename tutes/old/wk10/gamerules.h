#include "shared.h"
#include "gameboard.h"

#ifndef GAMERULES_H
#define GAMERULES_H
#define ATTACK_DISTANCE 2

#define MIN(X,Y) (X) < (Y) ? (X) : (Y)
#define UP -1
#define DOWN 1
#define CC_WHITE_DIR DOWN
#define CC_RED_DIR UP

#define LUDIAG {-1,-1}
#define LUKDIAG {-2,-2}
#define RUDIAG {1,-1}
#define RUKDIAG {2,-2}
#define LLDIAG {-1,1}
#define LLKDIAG {-2, 2}
#define RLDIAG {1,1}
#define RLKDIAG {2,2}

#define IS_KING(BOARD,LOC) ((BOARD)[(LOC).y][(LOC).x] == (CC_K_RED)        \
                || (BOARD)[(LOC).y][(LOC).x] == (CC_K_WHITE))

#define IS_EMPTY(BOARD, LOC) ((BOARD)[(LOC).y][(LOC).x] == CC_EMPTY)

#define ENEMY(X) ((X) == CC_EMPTY ? CC_EMPTY : (X) == CC_RED ? CC_WHITE : \
CC_RED)

/**
 * the various states the game could be in which can be returned from
 * is_game_over()
 **/
enum game_state
{
        GS_CONTINUING, GS_WON, GS_LOST, GS_DRAW
};

struct player;

BOOLEAN is_valid_move(const gameboard board, const struct move* , struct player*);
BOOLEAN is_attack_move(struct move*);
enum game_state is_game_over(gameboard board, struct player *); 
void finalise_scores(gameboard, struct player*, struct player *);
enum cell_contents king(enum cell_contents);
BOOLEAN has_valid_moves(gameboard, struct player*, int, int);
struct location get_mid(const struct location*, const struct location*);
void calc_score(gameboard, struct player*);
int direction(enum cell_contents);


#endif
