#include "loader.h"
void selection(char[][LINE_LEN+1], unsigned);
void swap(char * first, char * second);

int main(void)
{
    char lines[MAX_LINES][LINE_LEN+1];
    unsigned curline=0;
    unsigned maxlines;

    /* load in the data-we are less concerned with this at the moment */
    if(maxlines = load(INPUT_FILE, lines), maxlines > FAIL )
    {
        /* do the sort */
        selection(lines, maxlines);
        /*output the sorted data */
        for(curline=0; curline < maxlines; curline++)
        {
            printf("%s\n", lines[curline]);
        }
    }
    return EXIT_SUCCESS;
}


void selection(char lines[][LINE_LEN+1], unsigned lineouter)
{
    BOOLEAN exchange;
    unsigned outer,inner,smallest;

    for(outer=0; outer < lineouter-1; ++outer)
    {
        /* the proportion of the list < outer has been sorted */
        exchange=FALSE;
        smallest=outer;
        /* loop through the list finding the smallest item that has not 
         * been sorted
         */
        for(inner=outer+1; inner < lineouter-1; ++inner)
        {
            if(strcmp(lines[inner],lines[smallest]) < 0)
            {
                exchange=TRUE;
                smallest=inner;
            }
        }
        if(exchange)
        {
            swap(lines[outer], lines[smallest]);
        }
        else
        {
            break;
        }
        printarray(lines, lineouter);
    }
}

/* convenience function to copy string data so we don't have to deal 
 * with it in each algorithm
 */
void swap(char * first, char * second)
{
    char swapper[LINE_LEN+1];
    strcpy(swapper, first);
    strcpy(first, second);
    strcpy(second, swapper);
}
