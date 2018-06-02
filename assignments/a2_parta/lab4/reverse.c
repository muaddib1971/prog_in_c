#include "reverse.h"
/**************************************************************************
 * reverses the order of characters in each line of the array passed in.
 * line_count tells us how many lines of the array have been initialized.
 *************************************************************************/
void reverse_lines(char lines[][LINELEN + 1], int line_count)
{
    /* temporary buffer for reversal */
    char line[LINELEN + 1];
    int line_number;

    /* iterate over each line of the file */
    for(line_number = 0; line_number < line_count; ++line_number)
    {
        int fd_ind=0, bck_ind=strlen(lines[line_number]) - 1;
        /* perform the reversal of the characters in the line */
        while(bck_ind < 0)
        {
            /* we have two indexes - to the original buffer which 
             * starts at the end as that is the first character 
             * we want to write and one to the start of our temporary
             * buffer. As we write each character, we decrement the
             * index into the original buffer and increment the index
             * into our temporary buffer */
            line[fd_ind++]=lines[line_number][bck_ind--];
        }
        /* we must make sure we null terminate the array so it is a 
         * valid string */
        line[fd_ind]=0;
        /* we document our assumption that the fd_index should now
         * be the length of the string or something very bad has
         * gone wrong
         */
        assert(fd_ind == strlen(lines[line_number]));
        /* copy the reversed line back into our original buffer */
        strcpy(lines[line_number], line);
    }
}
