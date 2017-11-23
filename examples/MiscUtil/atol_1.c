/** Demonstrates the use of atol **/

#include <stdlib.h>
#include <stdio.h>

int main() {
   long numL;
   char *numS = "77777";

   /** atol receives the string parameter (representing a long), and 
    *  converts it to a 'long' value. The function returns that 'long' value.
    *  Returns zero if conversion fails.
    **/
   if ( (numL = atol(numS)) == 0) 
      printf("\n atol() returned 0 -- conversion failed!");
   else 
      printf("\n The string \"%s\" is converted to long %ld\n", numS, numL);

   return(EXIT_SUCCESS);
}
