
/*
 *  This example program demonstrates the use of putchar
 *  from the standard C library (stdio)
 *  Updated by Paul Miller, December 2015.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
   char ch = 'A';

   /* putchar prints one character (that is passed as a parameter) to the 
    * standard output. Auto-increment on a char, advances it to the next
    * consecutive character in the underlying character set. eg. ASCII
    * Remember that when all is said and done that a char is still just an
    * integer type - it is just smaller than an int. That's why incrementing
    * works here.
    */

   putchar(ch);
   putchar(++ch);
   putchar(++ch);
   putchar(ch++);
   
   return EXIT_SUCCESS;
}
