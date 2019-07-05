/******************************************************************************
 * Student Name    :
 * RMIT Student ID :
 * COURSE CODE     :
 *
 * Startup code provided by Paul Miller for use in "Programming in C",
 * study period 2, 2019.
 *****************************************************************************/
#include "board.h"

/**
 * iterate from the top and botton, filling in the values according to the
 * arrays and values passed in.
 **/
static void fill_column(board the_board, int colno, int token_count,
                        enum piece top_piece, enum piece bottom_piece)
{
        int count;
        for (count = 0; count < token_count; ++count)
        {
                the_board[count][colno] = top_piece;
        }
        for (count = BOARD_HEIGHT - 1; count > BOARD_HEIGHT - (token_count + 1);
             --count)
        {
                the_board[count][colno] = bottom_piece;
        }
}

/**
 * init_board() - provide the logic to initialise the board to the same data as
 * shown in the assignment specification. Please note that a naive
 * implementation (eg: one without loops) will not get full marks. For full
 * details of the requirement of this function, please see the assignment
 * requirements
 **/
void board_init(board the_board)
{
        /* counter across the columns */
        int xcount;
        /* the number of tokens in each column */
        int token_counts[] = { 5, 0, 0, 0, 3, 0, 5, 0, 0, 0, 0, 2 };
        /* colour at the top of the column */
        enum piece colors_top[] = { P_WHITE, P_EMPTY, P_EMPTY, P_EMPTY,
                                    P_RED,   P_EMPTY, P_RED,   P_EMPTY,
                                    P_EMPTY, P_EMPTY, P_EMPTY, P_WHITE, };
        /* colour at the bottom of the column */
        enum piece colors_bottom[] = { P_RED,   P_EMPTY, P_EMPTY, P_EMPTY,
                                       P_WHITE, P_EMPTY, P_WHITE, P_EMPTY,
                                       P_EMPTY, P_EMPTY, P_EMPTY, P_RED, };
        /* zero out the array */
        memset(the_board, 0, BOARD_WIDTH * BOARD_HEIGHT * sizeof(enum piece));

        /* iterate over the columns, filling them with the spcecified number
         * and colour of tokens specified in our predeclared arrays */
        for (xcount = 0; xcount < BOARD_WIDTH; ++xcount)
        {
                fill_column(the_board, xcount, token_counts[xcount],
                            colors_top[xcount], colors_bottom[xcount]);
        }
}
