/** Demonstrates the use of assert() macro defined in assert.h header file**/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_NUMS 10

int main() {
   int x=0, retVal=0, i=0, num=2;

   printf("\nEnter count of Odd numbers to be printed [1-%d] > ", MAX_NUMS);
   retVal = scanf("%d", &x);

   /** assert() macro is a neat was to ensure that the value(s) of the 
    *  variable(s) is what the programmer expects it to be. If the assert()
    *  fails the system will print an error message and abort the program.
    **/
   assert(retVal == 1 && x <= MAX_NUMS);

   for( i=0; i < x; i++) {
      printf(" %d\t", num);
      num+=2;
   }
   putchar('\n');

   return(EXIT_SUCCESS);
}
