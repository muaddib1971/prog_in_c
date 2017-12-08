/** Demonstrates the use of atof **/

#include <stdlib.h>
#include <stdio.h>

int main() {
   float numF;
   char *numS = "77.77";

   /** atof receives the string parameter (representing an float), and 
    *  converts it to an 'float' value. The function returns that 'float' value.
    *  Returns zero if conversion fails.
    **/
   if ( (numF = atof(numS)) == 0) 
      printf("\n atof() returned 0 -- conversion failed!");
   else 
      printf("\n The string \"%s\" is converted to float %3.2f\n", numS, numF);

   return(EXIT_SUCCESS);
}
