#include "gameboard.h"
#include "player.h"

/* The template for the starting board. This is an example of where a global
 * variable might come in handle. Note that since it is a static const 
 * it is only available within this file (that's what static means) and 
 * it is not modifiable (that's what const means).
 */

static gameboard template_board = 
{
        {
                CC_RED, CC_EMPTY, CC_RED, CC_EMPTY, CC_RED, CC_EMPTY, CC_RED, 
                CC_EMPTY
        },
        {
                CC_EMPTY, CC_RED, CC_EMPTY, CC_RED, CC_EMPTY, CC_RED, CC_EMPTY, 
                CC_RED
        },
        {
                CC_RED, CC_EMPTY, CC_RED, CC_EMPTY, CC_RED, CC_EMPTY, CC_RED, 
                CC_EMPTY
        },
        {
                CC_EMPTY, CC_EMPTY, CC_EMPTY, CC_EMPTY, CC_EMPTY, CC_EMPTY, 
                CC_EMPTY, CC_EMPTY
        },
        {
                CC_EMPTY, CC_EMPTY, CC_EMPTY, CC_EMPTY, CC_EMPTY, CC_EMPTY, 
                CC_EMPTY, CC_EMPTY
        },
        {
                CC_EMPTY, CC_WHITE, CC_EMPTY, CC_WHITE, CC_EMPTY, CC_WHITE, 
                CC_EMPTY, CC_WHITE
        },
        {
                CC_WHITE, CC_EMPTY, CC_WHITE, CC_EMPTY, CC_WHITE, CC_EMPTY, 
                CC_WHITE, CC_EMPTY
        },
        {
                CC_EMPTY, CC_WHITE, CC_EMPTY, CC_WHITE, CC_EMPTY, CC_WHITE, 
                CC_EMPTY, CC_WHITE
        }
};

/**
 * simply copy the above template board into the board parameter passed into
 * this function.
 **/
void gameboard_init(gameboard board)
{
        memcpy(board, template_board, sizeof(gameboard));
}

/**
 * print the heading line for the gameboard
 **/
static void print_board_heading()
{
        int count;
        printf("   |");
        /* print out the numbers for the each column */
        for( count=0; count < BOARDWIDTH; ++count)
        {
                printf(" %d |", count+1);		
        }
        /* remove last character written to stdout */
        unputc(stdout);
        putchar('\n');
        /* print a line of dashes underneath this heading row */
        PUT_DASHES(CH_BOARD_WIDTH);
        putchar('\n');
}

/**
 * print one row from the game board
 **/
static void print_board_line(enum cell_contents line[], int rownum)
{
        int count;
        /* used for any cell whose contents is CC_EMPTY */
        const char * spaces = "   ";
        printf(" %d |", rownum);
        /* print out the contents of each cell in this row */
        for(count = 0; count < BOARDWIDTH; ++count)
        {
                /* the format specifier for each cell where we wish to 
                 * display a coloured token
                 */
                const char * format = " %s%c%s |";
                switch(line[count])
                {
                        case CC_EMPTY:
                                printf("%s|", spaces);
                                break;
                        case CC_RED:
                                printf(format, RED_COLOUR, NORMAL_TOKEN,
                                                RESET_COLOUR);
                                break;
                        case CC_K_RED:
                                printf(format, RED_COLOUR, KING_TOKEN,
                                                RESET_COLOUR);
                                break;
                        case CC_WHITE:
                                printf(format, WHITE_COLOUR, NORMAL_TOKEN,
                                                RESET_COLOUR);
                                break;
                        case CC_K_WHITE:
                                printf(format, WHITE_COLOUR, KING_TOKEN,
                                                RESET_COLOUR);
                }
        }
        putchar('\n');
}

/**
 * Display the game board. Your display should precisely match the provided
 * output example in the assignment specifications. I have provided colour
 * codes in the header file so you can easily output the colours of red and 
 * white.
 **/
void gameboard_display(gameboard board)
{
        int count;
        print_board_heading();
        for(count = 0; count < BOARDHEIGHT; ++count)
        {
                print_board_line(board[count], count+1);
                PUT_DASHES(CH_BOARD_WIDTH);
                putchar('\n');
        }
        putchar('\n');
}

/**
 * this function modifies the gameboard based on the move passed in. It should 
 * validate that the move is valid and if not, return FALSE. It should then 
 * remove the token from it's starting point and place it in its ending point.
 * If this is an attack move, it should remove the piece taken from the board.
 * Finally if a piece has made it to the other end of the board, it should 
 * replace the normal piece with a KING piece of the same colour.
 *
 * NOTE: The false value returned here should be deleted and replaced with 
 * the appropriate return value. This return value is a standard place-holder
 * when creating skeleton code: a function that is not implemented yet should
 * always fail.
 **/
BOOLEAN apply_move(gameboard board, struct move* move, 
                struct player* player)
{
        /* only apply a move if it is valid */
        if(is_valid_move((const enum cell_contents(*)[BOARDHEIGHT])board, 
                                move, player))
        {
                struct location start = move->start;
                struct location end = move->end;
                /* grab the token that is to be moved */
                enum cell_contents cur_token = board[start.y][start.x];
                /* remove that token from its starting point */
                board[start.y][start.x] = CC_EMPTY;
                /* place the token at its ending point */
                board[end.y][end.x] = cur_token;
                /* if this is an attack move, remove the piece that we 
                 * have taken off the board
                 */
                if(is_attack_move(move))
                {
                        struct location middle = get_mid(&(move->start), 
                                        &(move->end));
                        board[middle.y][middle.x] = CC_EMPTY;
                }
                /* if this piece has reached the opposite end of the 
                 * board, crown it as a king
                 */
                if(end.y == TOP_ROW || end.y == BOTTOM_ROW ) 
                {
                        board[end.y][end.x] = king(player->token_colour);
                }
        }
        else
        {
                return FALSE;
        }
        return TRUE;
}
