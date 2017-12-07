#include "loader.h"

void bubble(char lines[][LINE_LEN+1], unsigned linecount);
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
        bubble(lines, maxlines);
        /*output the sorted data */
        for(curline=0; curline < maxlines; curline++)
        {
            printf("%s\n", lines[curline]);
        }
    }
    return EXIT_SUCCESS;
}

void bubble(char lines[][LINE_LEN+1], unsigned linecount)
{
    unsigned inner, outer;
    BOOLEAN exchange;
    /* iterate over all elements of the list at least once */
    for(outer=1; outer < linecount; outer++)
    {
        /* do a run over the list backwards - swap any elements that 
         * are not sorted. eventually the lower elements 'bubble up'
         * the list - which is why it is called a bubble sort
         */
        /* if there are no exchanges over an iteration of the loop, it
         * means it is sorted
         */
        exchange=FALSE;
        for(inner=linecount-1; inner >= outer; inner--)
        {
            if(strcmp(lines[inner-1], lines[inner]) > 0)
            {
                swap(lines[inner-1], lines[inner]);
                exchange=TRUE;
            }
        }
        printarray(lines, linecount);
        /* an unsorted list will have at least one exchange per 
         * iteration
         */
        if(!exchange)
            break;
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
