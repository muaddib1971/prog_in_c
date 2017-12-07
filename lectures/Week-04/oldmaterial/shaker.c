#include "loader.h"

void shake(char lines[][LINE_LEN+1], unsigned linecount);
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
        shake(lines, maxlines);
        /*output the sorted data */
        for(curline=0; curline < maxlines; curline++)
        {
            printf("%s\n", lines[curline]);
        }
    }
    return EXIT_SUCCESS;
}

void shake(char lines[][LINE_LEN+1], unsigned linecount)
{
    unsigned item;
    BOOLEAN exchange;
    do
    {
        exchange=FALSE;
        for(item=linecount-1; item > 0; item--)
        {
            printf("item: %d\n", item);
            if(strcmp(lines[item-1], lines[item]) > 0)
            {
                swap(lines[item-1], lines[item]);
                exchange=TRUE;
            }
        }
        if(exchange)
        {
            for(item=1; item < linecount; item++)
            {
                if(strcmp(lines[item-1], lines[item]) > 0)
                {
                    swap(lines[item-1], lines[item]);
                    exchange=TRUE;
                }
            }
        }
        printarray(lines, linecount);
    }while(exchange);
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
