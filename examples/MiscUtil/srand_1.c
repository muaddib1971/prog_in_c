/** Demonstrates the use of srand() function defined in stdlib.h **/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMS 10

/** The program prompts for a seed value and generates the series of random 
 *  number based on it.
 *  A similar seed value will always produce the same number.
 **/
int main() {
   int i, seed;

   printf("\n Enter the value for the seed for random generation > ");

   /** If a valid integer value is not entered the program will take the 
    *  seed value based on time() function of time.h header file, that returns
    *  the system time in seconds -- refer to time_1.c for more details.
    **/
   if (scanf("%d", &seed) != 1) {
      printf("\n Invalid Integer format");
      printf("\n Default seed %d taken", (seed=time(NULL)));
   }

   /** srand() seeds the random-generator, causing the sequence generated
    *  by the rand() to start in a different place each time. That is change in 
    *  the value of seed, will guarantee a diferent starting point.
    **/
   srand(seed);
   printf("\nThe random numbers generated using srand() seed of %d\n", seed);
   for (i=0; i < MAX_NUMS; i++)
      printf("%d\t", rand());

   putchar('\n');
   return(EXIT_SUCCESS);
}
