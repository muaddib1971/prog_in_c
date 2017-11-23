/** Demonstrates the use of atoi **/

#include <stdlib.h>
#include <stdio.h>

int main() {
   int numI;
   char *numS = "777";

   /** atoi receives the string parameter (representing an integer), and 
    *  converts it to an 'int' value. The function returns that 'int' value.
    *  Returns zero if conversion fails.
    **/
   if ( (numI = atoi(numS)) == 0) 
      printf("\n atoi() returned 0 -- conversion failed!");
   else 
      printf("\n The string \"%s\" is converted to integer %d\n", numS, numI);

   return(EXIT_SUCCESS);
}

