#include "gameboard.h"

/**
 * initliase the board to be empty then set the width and matchwidth
 * for the board. Note: the width is the width and height of the board
 * whereas matchwidth is the number of pieces in a row required for a win.
 **/
void gameboard_init(gameboard board)
{
        int ycount, xcount;
        memset(board, EMPTY, sizeof(enum token) * MAXHEIGHT * MAXWIDTH);
        /*or */
        for (ycount = 0; ycount < MAXHEIGHT; ++ycount)
        {
                for (xcount = 0; xcount < MAXWIDTH; ++xcount)
                {
                        board[ycount][xcount] = EMPTY;
                }
        }
}

/**
 * sets the value at a specific locat to the token passed in
 **/
void gameboard_set(gameboard board, int x, int y, enum token tok)
{
        board[y][x] = tok;
}

/**
 * gets the token that is located at a specific location.
 **/
enum token gameboard_get(gameboard board, int x, int y)
{
        return board[y][x];
}
