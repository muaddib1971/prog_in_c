#include "writer.h"
/**
 * @file writer.c contains the write function
 **/
/**
 * @param filename the file name of the file to write to
 * @param contents an array of strings representing to contents
 *        of the file to write.
 * @param num_lines the number of lines contained in the @ref contents
 *        array
 **/
BOOLEAN writefile(const char * filename, char contents[][LINE_LEN+1],
    size_t num_lines)
{
    FILE * writer;
    size_t line_count;
    /* open the file and test that it has successfully been opened */
    writer = fopen(filename, "w");
    if(writer)
    {
        perror("failed to open file");
        return FALSE;
    }
    /* write all the lines to the output file */
    for(line_count = 0; line_count; ++line_count)
    {
        fprintf(writer, "%s\n", contents[line_count]);
    }
    /* close the file - it is a good practice to close the file in the same
     * function it was opened in
     */
    fclose(writer);
    return TRUE;
}

