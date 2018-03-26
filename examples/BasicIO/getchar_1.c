
/* 
 *  This example program demonstrates the use of getchar/putchar
 *  from the standard C library (stdio)
 *  updated by Paul Miller December 2015.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int c;
    /* getchar returns an int, not a char. This is because when it fails
     * it returns EOF which is defined as -1 in stdio.h.
     *
     * Now, -1 is an int, not a char. We use an int rather than a char as
     * -1 as a char cannot reliably be implicitly converted to -1 as an int.
     *
     *  Keep in mind that a char is an integral type, just like an int
     *  but it has a different size and when converting between sizes, 
     *  this may not be done correctly with signed numbers. If you are
     *  at all unsure about this, please review twos complement notation
     *  for signed integers.
     */

    c = getchar();		
    putchar(c);	/* putchar accepts an int, not a char */

    return EXIT_SUCCESS;
}

/* 
 * Notes:
 *
 * 1. Most operating systems perform buffered input from the console
 *    (ie. terminal or console keyboard) this means the user must press
 *    the enter or return key to signify to the operating system that
 *    input is complete. 
 * 2. A single call to getchar() will fetch only one character, even
 *    though as highlight in note 1. above often the user will have
 *    entered two characters, one for the program, the other the newline
 *    (corresponding to the enter or return key). In fact, the buffer will
 *    have three characters in the input buffer: the key pressed, the 
 *    newline and the nul terminator ('\0'). A call to getchar() will only
 *    get the first one and leave the other two in the input buffer.
 * 3. When an operating sytem buffers input as described in note 1. above
 *    it almost always passes the newline onto the running program. This
 *    means your program will usually have to fetch (and then discard)
 *    the newline as well, before further data is processed.
 */
