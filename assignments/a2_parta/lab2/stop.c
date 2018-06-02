#include "stop.h"

/*************************************************************************
 * reads in each line of the stop file, trims the newline character and
 * stores this data in the stoplist. Returns either a count of the number
 * stopwords stored or a EOFL constant to represent that an error has 
 * occured.
 ************************************************************************/
long get_stop_list(FILE* stop_file, char stoplist[][MAXSTOPLEN])
{
    /* the count of words that have been inserted into the list */
    long wordcount=0;
    /* each line to read in from a file */
    char line [ MAXSTOPLEN + EXTRASPACES ];
    /* read in each line from the stop file */
    while(fgets ( line, MAXSTOPLEN + EXTRASPACES, stop_file ) != NULL)
    {
        /* if the newline is missing from data read in then 
         * the line could be too long.
         */
        if( line [ strlen ( line )  ] != '\n' )
        {
            fprintf( stderr, "Error: error in reading data from file" );
            fprintf( stderr, "%s\n", line);
            return EOFL;
        }
        /* remove the newline as we don't want to store it */
        line [ strlen ( line ) ] = 0;
        /* store the word from the file */
        strcpy(stoplist [ wordcount ] , line );
    }
    /* test the global errno - when fgets fails it might be the end of 
     * the file or there might be another error.
     */
    if( errno != NO_ERROR )
    {
        perror ( "i/o error" );
        return EOFL;
    }
    return wordcount;
}

/**************************************************************************
 * reads each line from the infile, tokenizes it. It then tests each token
 * to see whether it is in the stop list. If it is not in the stop list, 
 * it is written to the ouput file followed by a newline character.
 *************************************************************************/
void stop_me( FILE* infile, FILE* outfile, 
        char stoplist [][ MAXSTOPLEN ] , unsigned stopcount)
{
    /* next line to be read from the input file */
    char line[MAXWIDTH + EXTRASPACES];
    /* the words that have been read in from input file */
    char tokens[MAXSTOPLEN][MAXWIDTH];
    /* read in each line from a file */
    while(fgets(line, MAXWIDTH + EXTRASPACES, infile) != NULL)
    {
        unsigned numtokens,count;
        /* tokenize each line */
        tokenize(line, DELIMS, tokens, &numtokens);
        for(count = 0; count < numtokens; ++count)
        {
            /* test if this is a stop word, and if it is not, then
             * write it to the output file 
             */
            if(is_stop(tokens[count], stoplist, stopcount))
            {
                fprintf(outfile, "%s\n", tokens[count]);
            }
        }
    }
    if(errno != NO_ERROR)
    {
        perror("io error");
    }
}

/**************************************************************************
 * tests whether a word is contained in the stop list 
 *************************************************************************/
BOOLEAN is_stop(char* word, char list[][ MAXSTOPLEN ] , 
        unsigned stopcount)
{
    /* counter to iterate over the stop list */
    unsigned count;
    for(count = 0; count < stopcount; ++count)
    {
        char list_word[MAXSTOPLEN+1];
        char *current;
        /* make a copy of the word so that the manipulations do not 
         * change the original word
         */
        strcpy(list_word, list[count]);
        /* change the characters of the word to lower case so we are
         * comparing like with like 
         */
        current = list_word;
        while(*current)
        {
            *current = tolower(*current);

        }
        /* check whether the word we wish to store is in the stop list */
        if(!strcmp(word, list_word))
        {
            return TRUE;
        }
    }
    /* this word is not in the stop list */
    return FALSE;
}
