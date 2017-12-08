#include "gamerules.h"
#include "player.h"

/**
 * returns the absolute difference between two integers
 **/
static int diff(int a, int b)
{
        /* abs() return magnitude of an integer (ignoring its sign) */
        return abs(a-b);
}

/**
 * this function expects the locations passed in to be the start and 
 * end points for a valid attack move. An attack move is a move where 
 * 
 **/
struct location get_mid(const struct location * start,
                const struct location * end)
{
        struct location err_loc = {EOF,EOF};
        struct location result;
        int min_x,min_y;
        if(diff(start->x, end->x) != ATTACK_DISTANCE ||
                        diff(start->y, end->y) != ATTACK_DISTANCE){
                return err_loc;
        }
        min_x = MIN(start->x, end->x);
        min_y = MIN(start->y, end->y);
        ++min_x;
        ++min_y;
        result.x = min_x;
        result.y = min_y;
        return result;
}

int direction(enum cell_contents colour)
{
        return colour == CC_RED ? CC_RED_DIR : 
                colour == CC_WHITE ? CC_WHITE_DIR : CC_EMPTY;
}

static BOOLEAN valid_attack(const gameboard board, struct location * start, 
                struct location * end, enum cell_contents player_colour)
{
        struct location middle = get_mid(start, end);
        enum cell_contents midcell = board[middle.y][middle.x];
        enum cell_contents startcell = board[start->y][start->x];
        if(diff(start->x, end->x) != ATTACK_DISTANCE ||
                        diff(start->y, end->y) != ATTACK_DISTANCE)
        {
                return FALSE;
        }
        if(IS_EMPTY(board, *start) || 
                        king(startcell) != king(player_colour))
        {
                return FALSE;
        }
        if(IS_EMPTY(board, middle) || king(midcell) == 
                        king(player_colour))
        {
                return FALSE;
        }
        if(!IS_EMPTY(board, *end))
        {
                return FALSE;
        }
        return TRUE;
}

static enum cell_contents color(const gameboard board, 
                struct location * loc)
{
        return board[loc->y][loc->x];
}

/**
 * tests whether the move passed in is valid given the current board state and
 * given that the player pointer passed in points to the current player. You 
 * should implement the testing criteria (on only those criteria) mentioned
 * for this requirement in the assignment specifications. 
 **/
BOOLEAN is_valid_move(const gameboard board, const struct move* move, 
                struct player* player)
{
        struct location start = move->start;
        struct location end = move->end;
        int diff_x = diff(start.x, end.x);
        int diff_y = diff(start.y, end.y);
        int y_move = start.y - end.y;
        /* are the starting coordinates within the bound of the board ? */
        if(start.x < 0 || start.y < 0 || start.x >= BOARDWIDTH || 
                        start.y >= BOARDHEIGHT)
        {
                return FALSE;
        }
        /* are the ending coordinates within the bounds of the board ? */
        if(end.x < 0 || end.y < 0 || end.x >= BOARDWIDTH || 
                        end.y >= BOARDHEIGHT)
        {
                return FALSE;
        }
        /* if the end point contains a token this is an invalid move */
        if(!IS_EMPTY(board, end) || 
                        king(color(board, &start)) 
                        != king(player->token_colour))
        {
                return FALSE;
        }
        /* kings can move up or down the board */
        if(IS_KING(board, start))
        {
                /* normal move */
                if(diff_x == 1 && diff_y == 1)
                {
                        return TRUE;
                }
                /* attack move - if it is a valid attack, it is a 
                 * valid move
                 */
                else if(diff_x == ATTACK_DISTANCE 
                                && diff_y == ATTACK_DISTANCE)
                {
                        if(valid_attack(board, &start, &end, 
                                                player->token_colour))
                        {
                                return TRUE;
                        }
                }
        }
        /* normal token */
        else
        {
                /* normal move - the difference in x and y is 1 and 
                 * the piece is being moved in the correct direction
                 */
                if(diff_x == 1 && diff_y == 1)
                {
                        return y_move == direction(player->token_colour);
                }
                /* attack move - piece is being moved in the correct 
                 * direction and it is an attack move (the distance being
                 * moved in the x and y is 2 places - we need to validate 
                 * that it is a valid attack move
                 */
                else if(valid_attack(board, &start, &end, player->token_colour)
                                && y_move == direction(player->token_colour)
                                * ATTACK_DISTANCE)
                {
                        return TRUE;
                }
        }
        return FALSE;
}

/**
 * this function tests whether the current player has lost the game. A game is
 * lost when a player has no further legal moves they can make. You need to 
 * test for legal moves in all directions. You may find a helper function makes
 * this code much easier to write.
 **/
enum game_state is_game_over(gameboard board, struct player * player)
{
        int y,x;
        enum game_state result = GS_LOST;
        /* set the score to 0 as we will count up the tokens */
        player->score = 0;
        /* iterate over each cell in the board */
        for(y = 0; y < BOARDHEIGHT; ++y)
        {
                for(x = 0; x < BOARDWIDTH; ++x)
                {
                        /* if the cell contains a token of the same colour
                         * as the player token, increment the player's 
                         * score. We convert them both to kings so we 
                         * are comparing like with like.
                         */
                        if(king(board[y][x]) == king(player->token_colour))
                        {
                                ++player->score;
                                /* if there are any valid moves, the 
                                 * game is not over 
                                 */
                                if(has_valid_moves(board, player, x, y))
                                {
                                        result = GS_CONTINUING;
                                }
                        }
                }
        }
        return result;
} 

/**
 * This function must be called at end of each turn and the beginning of the 
 * game if you are deciding to go for the "Tracking Scores" bonus marks. 
 * This function should set the player's score to 0 and then iterate over the 
 * board and if the colour of the token in the current cell is the same as the 
 * colour of the player's token, add one to the score. 
 **/
void calc_score(gameboard board, struct player* player)
{
        int xcount, ycount;
        /* reset the player score to 0 */
        player->score = 0;
        /* iterate over each element of the board */
        for(ycount = 0; ycount < BOARDHEIGHT; ++ycount)
        {
                for(xcount = 0; xcount < BOARDWIDTH; ++xcount)
                {
                        /* if the current token is the same colour as 
                         * player's token then increment the count
                         */
                        if(king(board[ycount][xcount]) 
                                        == king(player->token_colour)) 
                        {
                                ++player->score;
                        }
                }
        }
}
/**
 * At the end of the game we want to finalise the scores for both 
 * players - simply calls calc_score() for each player
 **/
void finalise_scores(gameboard board, struct player* first,
                struct player * second)
{
        calc_score(board, first);
        calc_score(board, second);
}

/**
 * converts a token into its 'king' equivalent. That is a red token of 
 * either king or normal gets converted to a red king. A while token of
 * either king or normal gets converted to a while king. An empty cell
 * is converted to an empty cell. 
 **/
enum cell_contents king(enum cell_contents cell)
{
        switch(cell)
        {
                case CC_RED:
                case CC_K_RED:
                        return CC_K_RED;
                        break;
                case CC_WHITE:
                case CC_K_WHITE:
                        return CC_K_WHITE;
                default:
                        return CC_EMPTY;
        }

}

BOOLEAN has_valid_moves(gameboard board, struct player* player, 
                int x, int y)
{
        const int max_moves = 8;
        /* test for normal moves */
        struct location  shifts[] =
        {
                LUDIAG, RUDIAG, LLDIAG, RLDIAG,
                LUKDIAG, RUKDIAG, LLKDIAG, RLKDIAG
        };
        struct location start;
        int count;

        start.x = x;
        start.y = y;

        for(count = 0; count < max_moves; ++count)
        {
                struct location end = location_add(start, shifts[count]);
                struct move attempted_move;
                attempted_move.start = start;
                attempted_move.end = end;

                if(is_valid_move((const enum cell_contents(*)[BOARDHEIGHT])
                        board, &attempted_move, player))
                {
                        return TRUE;
                }

        }
        return FALSE;
}

BOOLEAN is_attack_move(struct move * move)
{
        int diff_x = diff(move->start.x, move->end.x);
        int diff_y = diff(move->start.y, move->end.y);
        return diff_x == ATTACK_DISTANCE && diff_y == ATTACK_DISTANCE;
}
