
#include <stdio.h>
#include <stdlib.h>

int intCompare(const void*, const void*);

#define ASIZE 10

int main(void)
{
   int a[ASIZE] = { 3, 7, 9, 12, 16, 24, 33, 42, 1138, 2001 };
   int target;
   int *pi;

   printf("a[] = { 3, 7, 9, 12, 16, 24, 33, 42, 1138, 2001 }\n");
   printf("Please enter search target (ie. an integer between 0 - 2500):");
   if (scanf("%d", &target)==1)
   {
      if ((pi = bsearch(&target, a, ASIZE, sizeof(int), intCompare)))
      {
         printf("Found %d\n", *pi);
	 printf("index %d\n", pi - a);
      }
      else
      {
         printf("No match found\n");
      }
   }
   else
   {
      fprintf(stderr,"Failed to fetch search target from user\n");
   }

   return EXIT_SUCCESS;
}

int intCompare(const void* p1, const void* p2)
{
   const int key1 =  *(int*)p1;
   const int key2 =  *(int*)p2;

   return (key1>key2) - (key1<key2);
}
