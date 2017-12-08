
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM 	10
#define NEWLINE	'\n'

int main(void)
{
   int i;
   time_t now;

   now = time(NULL);

   srand((int)now);

   for(i=0; i<NUM; i++)
   {
      printf("%d ", rand());
   }
   putchar(NEWLINE);

   return EXIT_SUCCESS;
}
