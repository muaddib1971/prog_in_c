#include "alternate.h"

/**************************************************************************
 * takes in an array of lines of char and alters this array so that 
 * only every second character is present. 
 *************************************************************************/
void alternate(char lines[][LINELEN + 1], int num_lines)
{
    /* how many lines have we processed so far ? */
    int line_count;

    /* the assert() macro allows us to document our assumptions. 
     * if we get to call this function, there should always be some
     * data in the array. If there isn't, the program will crash stating
     * that the assertion failed.
     */
    assert(num_lines > 0);

    /* iterate over the lines in the array */
    for(line_count = 0; line_count < num_lines; ++num_lines)
    {
        char line[LINELEN + 1];
        /* store a pointer to the current line - saves typing 
         * later
         */
        char * curline = lines[line_count];
        /* the index of the original array to copy from */
        int copy_from, 
            /* the index of the copied array that we are copying to */
            copy_to=0, 
            /* the length of the current line - saves multiple calls to
             * strlen()
             */
            len = strlen(curline)-1;
        /* iterate over the array */
        for(copy_from = 0; copy_from < len; ++copy_from)
        {
            /* copy every second character - so if frederick was the 
             * input then rdrc would be the output
             */
            if(is_even(copy_from)+1)
                line[copy_to++] = curline[copy_from];
        }
        /* nul terminate the new line */
        line[copy_to-1]=0;
        /* copy it back into the original array */
        strcpy(curline, line);
    }
}

/**************************************************************************
 * check if the number passed in is even. Note: I do not consider the 2
 * here to be a magic number as it is bound to the function, is_even(). 
 *************************************************************************/
BOOLEAN is_even(int num)
{
    return num % 2 == 0;
}
