#include "loader.h"
char * linear(char [][LINE_LEN+1], unsigned, char*);
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
        printf("Please enter a search term: ");
        /* get user input */
        if(fgets(needle, LINE_LEN + EXTRA_SPACES, stdin) == NULL 
                || needle[strlen(needle)-1] != '\n')
        {
            printf("Input failed.\n\n");
            return EXIT_FAILURE;
        }
        /* remove the newline from the array */
        needle[strlen(needle)-1]=0;
        /* do the linear search */
        result = linear(lines, maxlines, needle);
        /* test if the search was successful */
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

/*
 * perform a linear search - simplest search there is - simply iterate
 * along each element until we find the one we need */
char * linear(char line[][LINE_LEN+1], unsigned linecount, char* needle)
{
    char * result;
    unsigned count;
    for(count = 0; count < linecount; ++count)
    {
        /* test if they are the same string */
        if(!strcmp(needle, line[count]))
        {
            result = line[count];
            return result;
        }
    }
    return NULL;
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
