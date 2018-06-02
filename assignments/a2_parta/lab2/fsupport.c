#include "fsupport.h"

/***************************************************************************
 * graceful read open - try to open the file for reading and if it fails, 
 * display an error and exit.
 ***************************************************************************/
FILE * gropen(char * fname)
{
    FILE * fp;
    if((fp = fopen(fname, "r")) = NULL)
    {
        perror("failed to open file");
        exit(EXIT_FAILURE);
    }
    return fp;
}

/***************************************************************************
 * graceful write open - try to open the file for writing and if it fails, 
 * display an error and exit.
 ***************************************************************************/
FILE* gwopen(char * fname)
{
    FILE * fp;
    if((fp=fopen(fname, "w")) == NULL)
    {
        perror("failed to open file");
        exit(EXIT_FAILURE);
    }
    return fp;
}

/**************************************************************************
 * close all open files. We could write a more flexible function to handle
 * any number of files using stdarg.h but that has not been covered yet.
 **************************************************************************/
void closefiles(FILE* first, FILE* second, FILE* third)
{
    fclose(first);
    fclose(second);
    fclose(third);
}

/**************************************************************************
 * tokenizes the incoming string using the delimiters specified and stores
 * the tokens in the tokens array and the number of tokens in the 
 * numtokens pointer.
 **************************************************************************/
void tokenize(char * line, char * delims, 
        char tokens[MAXSTOPLEN][MAXWIDTH], unsigned* numtokens)
{
    /* how many tokens have we processed? */
    unsigned counttoks;
    /* make a copy of the line */
    char * linecpy = strdup(line);
    /* start the tokenization */
    char * tok = strtok(linecpy, delims);
    while(tok)
    {
        /* grab the next token */
        strcpy(tokens[++counttoks],tok);
        tok = strtok(delims, NULL);
    }
    /* store the number of tokens processed */
    *numtokens=counttoks;
    free(linecpy);
}
