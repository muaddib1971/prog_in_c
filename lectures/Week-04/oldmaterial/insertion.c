#include "loader.h"
/* this file demonstrates the use of the insertion sort algorithm to 
 * sort an array of strings 
 */
void insertion(char[][LINE_LEN+1], unsigned);
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
        insertion(lines, maxlines);
        /*output the sorted data */
        for(curline=0; curline < maxlines; curline++)
        {
            printf("%s\n", lines[curline]);
        }
    }
    return EXIT_SUCCESS;
}

/**************************************************************************
 * the implementation of the insertion sort algorithm
 *************************************************************************/
void insertion(char lines[][LINE_LEN+1], unsigned linecount)
{
    int outer, inner;
    /* we begin with a sublist of two (top two items) */
    for(outer=1; outer < linecount; ++outer)
    {
        /* we add one item at a time (the next item down) and keep
         * that sublist sorted */
        for(inner=outer-1; 
            inner >= 0 && strcmp(lines[inner+1], lines[inner]) < 0;
            --inner)
        {
            swap(lines[inner+1],lines[inner]);
        }
        printarray(lines, linecount);
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
