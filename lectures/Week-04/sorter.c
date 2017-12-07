#include "loader.h"

void swap(char * first, char * second);

int main(void)
{
    char lines[MAX_LINES][LINE_LEN+1];
    unsigned curline=0;
    unsigned maxlines;

    /* load in the data-we are less concerned with this at the moment */
    if(maxlines = load("void.txt", lines), maxlines > FAIL )
    {
        /* do the sort */
        /*output the sorted data */
        for(curline=0; curline < maxlines; curline++)
        {
            printf("%s\n", lines[curline]);
        }
    }
    return EXIT_SUCCESS;
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
