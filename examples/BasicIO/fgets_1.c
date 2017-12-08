/* 
 *  This example program demonstrates the use of fgets
 *  from the standard C library (stdio)
 *  updated by Paul Miller, december, 2015.
 */

#include <stdio.h>
#include <stdlib.h>

#define LSIZE 1024
#define EXTRACHARS 2

int main(void)
{
        char textInput[LSIZE + EXTRACHARS];
        /* fetch up to 1024 chars not counting  the terminating characters 
         * of  \n\0
         */

        while (fgets(textInput, LSIZE + EXTRACHARS, stdin) != NULL)  
        {
                puts(textInput);    /* display it if found   */

        }                       /* loop back until EOF   */

        return EXIT_SUCCESS;
}

/*
 * Notes:
 *
 * 0. This example program will continue looping until EOF is encountered.
 *    The user can simulate EOF during interactive input by pressing
 *    control-D on a blank line (default under Unix) or 
 *    control-Z (MS-DOS/Win)
 *
 * 1. fgets() is a safe string input routine, it is safe because it
 *    requires the caller provide details of the size of the string
 *    buffer so that fgets can ensure it does not fetch more characters
 *    than there is space for within the string buffer. fgets nul 
 *    terminates the array and as such the result is a c string.
 * 
 * 2. if the user (via the operating system) provides a line of text
 *    (lines are delimited with a newline ('\n') when the enter or
 *    return key is pressed (assuming interactive input) shorter
 *    than the available space (LSIZE or less), then the newline will be 
 *    added to the string buffer before the nul-termination.
 *
 * 3. some operating systems (eg. MS-DOS/Windows) will use \r\n 
 *    ie. a carriage return and newline combination to represent the
 *    end of a line, whereas as Unix and some other operating systems
 *    will use just a newline. Before OSX, apple used a \r as a line 
 *    terminator. It is therefore important to know what the line 
 *    terminators are in the operating system in which you are working.
 * 
 */
