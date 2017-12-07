#include "loader.h"
#include "shaker.h"
char * binary(char [][LINE_LEN+1], unsigned,unsigned, char*);
void shake(char lines[][LINE_LEN+1], unsigned linecount);
void swap(char * first, char * second);

int main(void)
{
    char lines[MAX_LINES][LINE_LEN+1];
    unsigned maxlines;

    /* load in the data-we are less concerned with this at the moment */
    if(maxlines = load(INPUT_FILE, lines), maxlines > FAIL )
    {
        /* do the search */
        char needle[LINE_LEN + EXTRA_SPACES];
        char * result;
        /* perform the sort */
        shake(lines, maxlines);
        /* get user input for what to search for */
        printf("Please enter a search term: ");
        if(fgets(needle, LINE_LEN + EXTRA_SPACES, stdin) == NULL 
            || needle[strlen(needle)-1] != '\n')
        {
            printf("Input failed.\n\n");
            return EXIT_FAILURE;
        }
        needle[strlen(needle)-1]=0;
        /* perform the search */
        result = binary(lines, 0, maxlines-1, needle);
        if(result == NULL)
        {
            printf("needle not found\n\n");
        }
        else
        {
            printf("%s was found.\n\n", result);
        }
    }
    printarray(lines, maxlines);
    return EXIT_SUCCESS;
}


/* perform the binary search algorithm */
char * binary(char lines[][LINE_LEN+1], unsigned left, unsigned right,
	      char* needle)
{
    /* the base case - our search indexes have overlapped */
    if(left > right)
    {
        return NULL;
    }
    else
    {
        unsigned mid = (left+right)/2;
        int result;
        /* perform our string comparison */
        result = strcmp(needle, lines[mid]);
        /* if we have found our target */
        if(result == 0)
        {
            return lines[mid];
        }
        /* if the search target is lower than the current item, look to the 
         * left
         */
        else if(result < 0)
        {
            return binary(lines, left, mid-1, needle);
        }
        else
        {
            /* otherwise look to the right */
            return binary(lines, mid+1, right, needle);
        }
    }
}

/* the shake sort algorithm - what we are using to presort our array */
void shake(char lines[][LINE_LEN+1], unsigned linecount)
{
    unsigned item;
    BOOLEAN exchange;
    do
    {
        exchange=FALSE;
        /* perform an upwards wave */
        for(item=linecount-1; item > 0; item--)
        {
            /* if we find an element to exchange, perform the exchange and 
             * record this fact
             */
            if(strcmp(lines[item-1], lines[item]) > 0)
            {
                swap(lines[item-1], lines[item]);
                exchange=TRUE;
            }
        }
        for(item=1; item < linecount; item++)
        {
            /* if we find an element to exchange, perform the exchange and 
             * record this fact
             */
            if(strcmp(lines[item-1], lines[item]) > 0)
            {
                swap(lines[item-1], lines[item]);
                exchange=TRUE;
            }
        }
        printarray(lines, linecount);
        /* continue while the array is not completely sorted */
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
