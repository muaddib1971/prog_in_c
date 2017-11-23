
#include <stdio.h>
#include <stdlib.h> /* qsort */

#define ASIZE 10

void fetchIntArray(int *a, int size)
{
   int i;

   for(i=0; i<size; i++)
   {
      if (scanf("%d", &a[i]) != 1)
      {
         fprintf(stderr,"scanf() failed\n");
         exit(EXIT_FAILURE);
      }
   }
}

void displayIntArray(int *a, int size)
{
  int i;
  
  for(i=0; i<size; i++)
  {
     printf("%d ", a[i]);
  }
  putchar('\n');
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

   fetchIntArray(a, ASIZE);

   displayIntArray(a, ASIZE);
 
   qsort(a, ASIZE, sizeof(int), intCompare);

   displayIntArray(a, ASIZE);

   return EXIT_SUCCESS;    
}

