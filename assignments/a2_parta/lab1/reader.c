#include "reader.h"
/**
 * @file reader.c contains the implementation of the @ref read function
 **/

/**
 * @param filename the name of the file to read
 * @param contents a 2 dimensional char array to read data into
 * @param num_lines the number of lines that ca  be contained in the 
 * contents array.
 **/
BOOLEAN readfile(const char * filename, char contents[][LINE_LEN+1],
    size_t * num_lines)
{
    size_t line_count;
    FILE * reader;
    char line[LINE_LEN + EXTRA_CHARS];

    /* open the file and check for success */ 
    reader = fopen(filename, "r");
    /* test if reader is NULL */
    if(!reader)
    {
        perror("Failed to open file");
        return FALSE;
    }
    /* zero out the whole array */
    memset(contents, sizeof(char) * (LINE_LEN+1) * BUFSIZ, 0);
    /* read each line from the file, up to a maximum of 8196 lines */
    while(fgets(line, LINE_LEN+EXTRA_CHARS, reader) != NULL 
        && line_count < BUFSIZ-1)
    {
        /* remove the newline from the string */
        line[strlen(line)-1]=0;
        /* copy it to the array of lines in the file */
        strcpy(contents[line_count++], line);
    }
    /* if we have read in more lines than we are allowed */
    if((line_count = BUFSIZ))
    {
        fprintf(stderr, "Error: file is too large\n");
        fclose(reader);
        return FALSE;
    }
    /* store the number of lines we read in */
    num_lines = &line_count;

    /* we were successful */
    return TRUE;
}
