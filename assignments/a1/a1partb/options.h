#include <string.h>
#include <time.h>

#include "helpers.h"
#include "shared.h"
#ifndef OPTIONS_H
#define OPTIONS_H

/**
 * the index of the cash register array that is occupied by each denomination,
 *if there are any of that denomination
 **/
enum denom_ind
{
        FIVE_CENTS_IND,
        TEN_CENTS_IND,
        TWENTY_CENTS_IND,
        FIFTY_CENTS_IND,
        ONE_DOLLAR_IND,
        TWO_DOLLAR_IND,
        FIVE_DOLLAR_IND,
        TEN_DOLLAR_IND
};

enum denom_val
{
        FIVE_CENTS_VAL = 5,
        TEN_CENTS_VAL = 10,
        TWENTY_CENTS_VAL = 20,
        FIFTY_CENTS_VAL = 50,
        ONE_DOLLAR_VAL = 100,
        TWO_DOLLAR_VAL = 200,
        FIVE_DOLLAR_VAL = 500,
        TEN_DOLLAR_VAL = 1000
};

struct denomination
{
        enum denom_ind index;
        enum denom_val value;
        int count;
};

struct currency
{
        int dollars;
        int cents;
};

#define NUM_DENOMS 8
#define MAX_CHANGES 50

typedef struct denomination cash_register[NUM_DENOMS];
typedef struct currency change_requests[MAX_CHANGES];

struct falsible_register
{
        BOOLEAN success;
        cash_register theregister;
};

#define ONE_CHAR 1
enum ttt_board_cell
{
        TTT_EMPTY_CELL,
        TTT_X_CELL,
        TTT_O_CELL,
        TTT_INVALID = -1
};

enum ttt_char
{
        X_UPPER_CHAR = 'X',
        X_LOWER_CHAR = 'x',
        O_UPPER_CHAR = 'O',
        O_LOWER_CHAR = 'o',
        SPACE_CHAR = ' '
};

#define BOARDHEIGHT 3
#define BOARDWIDTH BOARDHEIGHT

enum ttt_result
{
        TTT_X,
        TTT_O,
        TTT_DRAW,
        TTT_ONGOING,
        TTT_INVALID_RESULT = -1
};

typedef enum ttt_board_cell ttt_board[BOARDHEIGHT][BOARDWIDTH];

void reverse_string(char[]);
void guess_a_number(long);
char* fold(char[], unsigned);
struct falsible_register can_give_change(const cash_register,
                                         const change_requests, int);
BOOLEAN ttt_init_board(ttt_board, const char[]);
enum ttt_result ttt_check_win(ttt_board);
void display_help(void);
#endif
