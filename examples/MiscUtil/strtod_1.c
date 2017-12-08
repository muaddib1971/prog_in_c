/** Demonstrates the use of strtod() **/
#include <stdio.h>
#include <stdlib.h>

int main() {
   double numD;
   char * str = "77.77/100 is a disntiction score";
   char *ptr;

   /** strtod converts string (passed as 1st parameter) to double (returned by
    *  the function) and the second parameter points to the string component
    *  of the convereted sub-string.
    *  If the second parameter is replaced with NULL, strtod behaves like 
    *  atof().
    *  On conversion failure, of strtod returns zero and if second parameter is
    *  not NULL, it would point to the string passed as the first parameter.
    **/
   if ( (numD = strtod(str, &ptr)) ==0) 
      printf("\n strtod() returned 0 -- conversion failed!");
   else {
      printf("\n The original string \"%s\" is broken down into :", str);
      printf("\n \tdouble component of %f", numD);
      printf("\n \tstring component of \"%s\"\n", ptr);
   }

   return(EXIT_SUCCESS);
}
