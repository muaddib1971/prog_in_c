
#include <stdio.h>
#include <stdlib.h> /* qsort */

#define ASIZE 10

void walkIntArray(int *a, int size, void (*process)(int *))
{
   int i;

   for(i=0; i<size; i++)
   {
      process(&a[i]);
   }
}

void fetchInt(int *pInt)
{
   if (scanf("%d", pInt) != 1)
   {
      fprintf(stderr,"scanf() failed\n");
      exit(EXIT_FAILURE);
   }
}

void displayInt(int *pInt)
{
   printf("%d ", *pInt);
}

int intCompare(const void * aptr, const void *bptr)
{
  const int a = *((int*)aptr);
  const int b = *((int*)bptr);

  if (a < b) return -1; else if (a > b) return +1; else return 0;

  /* return ( (a>b) - (a<b) ); */

}

int main(void)
{
   int a[ASIZE];

   walkIntArray(a, ASIZE, fetchInt);

   walkIntArray(a, ASIZE, displayInt);
   putchar('\n');
 
   qsort(a, ASIZE, sizeof(int), intCompare);

   walkIntArray(a, ASIZE, displayInt);
   putchar('\n');

   return EXIT_SUCCESS;    
}

