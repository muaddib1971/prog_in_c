/** Demonstrates the use of strtol() **/
#include <stdio.h>
#include <stdlib.h>

int main() {
   long numL;
   char * str = "77 is an eventful number";
   char *ptr;

   /** strtol converts string (passed as 1st parameter) to long (returned by
    *  the function) and the second parameter points to the string component
    *  of the convereted sub-string. The 3rd parameter represents the base
    *  (Octal - base 8; Decimal - 10 etc) value that is to be used for 
    *  convertion of the string. The base value can be between 2-36.
    *  If the conversion fails, strtol() returns zero.
    **/
   if ( (numL = strtol(str, &ptr, 0)) == 0) 
      printf("\n strtol() returned 0 -- conversion failed!");
   else {
      printf("\n The original string \"%s\" is broken down into :", str);
      printf("\n The long component of %ld", numL);
      printf("\n The string component of \"%s\"\n", ptr);
   }
   return(EXIT_SUCCESS);
}
