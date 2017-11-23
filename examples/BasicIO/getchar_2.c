
/* 
 *  This example program demonstrates the use of getchar/putchar
 *  in a loop, and demonstrates testing for EOF and highlights the
 *  presence of a newline in the input passed to C programs by the
 *  operating system.
 *  updated by Paul Miller December 2015
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
        int c;

        while ( (c = getchar()) != EOF )
        {
                if (c == '\n')
                {
                        /* note: we cast the result of these functions
                         * to void to emphasize that we are ignoring 
                         * the return value.
                         */
                        /* display a \n in place of any newline */
                        (void)putchar('\\');
                        /* encountered, just to highlight them  */
                        (void)putchar('n');    
                }                     
                else
                {
                        (void)putchar(c);		
                }
        }

        return EXIT_SUCCESS;
}

/* 
 * Notes:
 *
 * 1.  This program will continue looping until the operating system
 *     indicates to getchar() that EOF (end of file) has been reached.
 *     Normally EOF is a concept that is applied to disk files, however
 *     it has been given a meaning for interactive (keyboard) input
 *     as well. Operating systems provide a means for the interactive
 *     user to request that EOF be simulated. Under most Unix operating
 *     systems control-D is used by default for this purpose. Under MS-DOS
 *     (and Windows) control-Z is used. If you are using another platform
 *     you will have to consult documentation to find out how to simulate
 *     EOF via interactive keyboard commands.
 *    
 * 2.  Under Unix control-D must usually be entered on a blank line
 *     (ie. after a newline) However, often two control-D keystrokes 
 *     in a row will achieve the same.
 * 
 * 3.  EOF is defined as -1 in stdio.h (and sometimes elsewhere). This
 *     is a signed integer value, and is the most significant reason for
 *     using an int variable to hold the return value from getchar().
 *     Failure to use an int variable for the holding the return value
 *     from getchar() could easily mean that on some systems EOF will
 *     not be correctly detected.
 *
 *     Let's look at this a bit more closely. In two's complement binary, 
 *     -1 is represented by all ones, so -1 in 8 bit is: 11111111, and 
 *     -1 in 32 bits is 11111111 11111111 11111111 11111111.
 *
 *     The problem however is in the conversion from char (8 bits) to int
 *     (32 bits). It is unspecified in the standard how a negative number
 *     is converted to a larger type so if we do the following: 
 *
 *     signed char ch = -1;
 *     int i = ch;
 *
 *     The value contained in the address of i could be either of the 
 *     following:
 *
 *     00000000 00000000 00000000 11111111
 *     11111111 11111111 11111111 11111111
 *
 *     Now, in a comparison such as (ch == EOF), ch will be promoted to
 *     an int and a similar conversion will happen. If 'i' in the above
 *     example holds the first value, then ch will never be equal to EOF.
 */
