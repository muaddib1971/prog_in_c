/*
 *  This example program demonstrates the use of puts
 *  from the standard C library (stdio)
 *  Updated December 2015 by Paul Miller
 */

#include <stdio.h>
#include <stdlib.h>

int main() 
{
   char text[] = "Test String";

   /* puts() prints a string to the standard output. It prints all the chars
    *  starting from the pointer to a char (passed as a partameter) till it
    *  encounters a nul-terminator. Note that it also appends a new line
    *  character to the end of the output.
    */
   puts(text);
   
   return EXIT_SUCCESS;
}
