
/*
 * a Simple, non-exhaustive, test driver for a IntCollection module
 *
 */

#include <stdio.h>
#include <stdlib.h>

#ifndef INTCOLL_HEADER 
#error INTCOLL_HEADER must be defined with the name of a suitable header file
#else
#include INTCOLL_HEADER
#endif

#define ENDLIST -1

int main(void)
{
   IntCollection numbers;

   int nums[] = { 1138, 42, 2001, 50, 21, 1500, 5000, ENDLIST };

   int i;

   printf("Current Implementation based on: %s\n", INTCOLL_HEADER);

   if (MakeCollection(&numbers) == FAILURE)
   {
      fprintf(stderr, "Unable to initialise IntCollection\n");
      return EXIT_FAILURE;
   }
 
   i=0;
   while (nums[i] != ENDLIST)
   {
      if (AddCollection(&numbers, nums[i]) == FAILURE)
      {
         fprintf(stderr, "AddCollection failed\n");
      }
      i++;
   }

   printf("Collection contains %d numbers\n", SizeCollection(&numbers);

   printf("The following numbers are in the Collection:\n");
  
   DisplayCollection(&numbers);

   printf("\nSearching for 42: ");

   printf("%s\n", SearchCollection(&numbers, 42) ? "FOUND" : "NOT FOUND");

   FreeCollection(&numbers);

   return EXIT_SUCCESS;
  
} 

