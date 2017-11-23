/* This program demonstrates the use of strtok() function */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TEXT 100
#define DELIM " \t\r\n"

int main(void) 
{
   char text[MAX_TEXT] = "C sells C shells by the C shore";   
   char *token;
   int i=0;

   /** strtok() breaks down the the string that is passed as the 1st parameter
    * into tokens, based on the delimiter string that is passed as the 2nd
    * parameter. strtok() replaces the delimiting characters within the 
    * string with nul-terminating characters to acheive its end.
    * ie. the original string is modified.
    * The first call to strtok() returns the the address of the first token.
    **/

   token = strtok(text, DELIM);

   while(token != NULL) 
   {
      i++;
      printf("\nToken # %d = %s", i, token);

      /** To extract the remaining tokens, the 1st parameter should be replaced
       *  with NULL. If there are no more tokens, teh call to strtok() would 
       *  return a NULL 
       **/
      token = strtok(NULL, DELIM);
   }
   printf("\n");

   return EXIT_SUCCESS;
}

/* 
 * Notes:
 *
 * 1. DELIM is a symbol representing the quoted string of delimiting
 *    characters that strtok() is to use when locating the end of
 *    each token. In this example, a space, a tab, a carriage return,
 *    and a newline have been included in this delimiting character set.
 *
 * 2. strtok() replaces the delimiting characters within the
 *    string with nul-terminating characters to acheive its end.
 *    ie. the original string is modified.
 * 
 */
