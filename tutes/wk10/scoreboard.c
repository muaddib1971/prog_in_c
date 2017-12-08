#include "scoreboard.h"

/**
 * initialise the scoreboard to an empty state. This means the names of all
 * the players should be an empty string.
 **/
void scoreboard_init(scoreboard board)
{
        memset(board, 0, sizeof(scoreboard));

}

/**
 * adds the winner of the last game to the scoreboard. If you are not 
 * tracking scores, you should insert these sorted by name. However if you 
 * are tracking the scores, sort them the score value with the highest scores
 * earlier in the scoreboard array.
 *
 * Sorting involves searching for the insertion point in the array and then 
 * moving all elements below that element down by one. Finally you should insert
 * the new data.
 **/
struct player * scoreboard_add(scoreboard board, struct player * winner)
{
        int count;
        for(count = 0; count < MAXNUMSCORES && *board[count].name;
                ++count)
        {
                if(board[count].value > 0 
                        && board[count].value < winner->score)
                {
                        break;
                }
                /* nothing to do as this is just a searching loop */
        }
        if(count == MAXNUMSCORES)
        {
                return NULL;
        }
        else
        {
                memmove(&board[count+1], &board[count], 
                        (MAXNUMSCORES - count) * sizeof(struct score));
                strcpy(board[count].name, winner->name);
                board[count].value = winner->score;
        }
        return winner;
}

/**
 * displays the scores in sorted order. You should use the output format as 
 * shown in the assignment specification as precisely as possible. Diversions
 * from that format will attract a deduction in marks. 
 **/
static void display_scoreboard_heading(void)
{
        char * heading = "Draughts - List of Winners";
        char * fmtstring = "%-*s| %s\n";
        char subheading[LINELEN+1];
        puts(heading);
        PUT_DASHES(strlen(heading));
        putchar('\n');
        sprintf(subheading, fmtstring, NAMELEN, "Name", "Won by");
        printf("%s", subheading);
        PUT_DASHES(strlen(subheading)-1);
        putchar('\n');
}

static void printscore(struct score * score)
{
        char * fmtstring = "%-*s| %d\n";
        printf(fmtstring, NAMELEN, score->name, score->value);
}

static int count_scores(scoreboard board)
{
        int count;
        for(count = 0; count < MAXNUMSCORES; ++count)
        {
                if(!*board[count].name)
                {
                        break;
                }
        }
        return count;
}

void scoreboard_display(scoreboard board)
{
        int count;
        if(count_scores(board) == 0)
        {
                printf("The scoreboard is currently empty.\n");
        }
        else
        {
                display_scoreboard_heading();
                for(count = 0; count < MAXNUMSCORES && *board[count].name;
                        ++count)
                {
                        printscore(&board[count]);
                }
        }
}
