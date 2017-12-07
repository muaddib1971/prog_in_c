#include "loader.h"

void shell(char [][LINE_LEN+1], unsigned);
void swap(char * first, char * second);
#define NUM_INTERVALS 4

int main(void)
{
    char lines[MAX_LINES][LINE_LEN+1];
    unsigned curline=0;
    unsigned maxlines;

    /* load in the data-we are less concerned with this at the moment */
    if(maxlines = load(INPUT_FILE, lines), maxlines > FAIL )
    {
        /* do the sort */
        shell(lines, maxlines);
        /*output the sorted data */
        for(curline=0; curline < maxlines; curline++)
        {
            printf("%s\n", lines[curline]);
        }
    }
    return EXIT_SUCCESS;
}

void shell(char lines[][LINE_LEN+1], unsigned linecount)
{
    unsigned intervals[]={9,5,3,1}, intno;
    int inner,outer;
    for(intno=0; intno < NUM_INTERVALS; ++intno)
    {
        for(outer=intervals[intno]; outer < linecount; ++outer)
        {
            for(inner = outer - intervals[intno]; 
                strcmp(lines[inner+intervals[intno]], lines[inner]) < 0 
                    && inner >= 0;
                --inner)
            {
                swap(lines[inner+intervals[intno]], lines[inner]);
            }
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
