#include "loader.h"

/*************************************************************************
 * loads the contents of a text file into an array and returns the 
 * number of lines that were loaded. The assumption is that each line 
 * of the file is at most LINE_LEN characters long
 ************************************************************************/
unsigned load(char * fname, char lines[][LINE_LEN+1])
{
    /* memory that we read each line into */
    char line[LINE_LEN + EXTRA_SPACES];
    /* how many lines have we read ? */
    unsigned curline=0;
    /* the file we are reading from */
    FILE * fpread = fopen(fname, "r");

    /* if there was a problem reading from the file return an error 
     * indicator
     */
    if(!fpread)
    {
        perror("opening file");
        return FAIL;
    }
    /* otherwise, read lines from the file until we get to the end of the 
     * file 
     */
    while(fgets(line, LINE_LEN+EXTRA_SPACES, fpread))
    {
        /* test that the line was not too long */
        if(line[strlen(line)-1]!='\n')
        {
            fprintf(stderr, "Error: line too long in input file.\n\n");
            fclose(fpread);
            return FAIL;
        }
        /* remove the new line as we now know the line was within the 
         * allowed line length 
         */
        line[strlen(line)-1]=0;
        /* copy the line into our array */
        strcpy(lines[curline++], line);
        /* test that we have not overreached the maximum number of 
         * lines to read
         */
        if(curline >= MAX_LINES)
        {
            fprintf(stderr, "Maximum lines reached.\n\n");
            fclose(fpread);
            return FAIL;
        }
    }
    /* close the file */
    fclose(fpread);
    /* return the number of lines read into the array */
    return curline;
}

/**************************************************************************
 * prints out the lines in the array passed in inside a box for formatting
 *************************************************************************/
void printarray(char lines[][LINE_LEN+1], unsigned height)
{
    unsigned width;
    unsigned count;
    /* we need the longest element to know how big the bounding box
     * needs to be
     */
    width=find_longest(lines, height);

    putchar('\n');
    /* print the top of the box */
    putline(width + 2);
    /* print each line of the file */
    for(count=0; count < height; ++count)
    {
        printf("|%*s|\n",width, lines[count]);
    }
    /* print the bottom of the box */
    putline(width+2);
    printf("\n\n\n");
}

/**************************************************************************
 * finds the length of the longest string in an array of strings.
 *************************************************************************/
unsigned find_longest(char lines[][LINE_LEN+1], unsigned height)
{
    /* the length of the longest line found so far */
    unsigned longest=0;
    /* simple counter */
    unsigned count;

    for(count = 0; count < height; ++count)
    {
        /* if the length of the current line is longer than we have 
         * seen, store it
         */
        unsigned length = strlen(lines[count]);
        if(length > longest)
            longest = length;
    }
    return longest;
}

void putline(unsigned length) 
{ 
    unsigned count; 
    for(count = 0; count < (length); ++count) 
    { 
        putchar('-'); 
    } 
    putchar('\n'); 
}
