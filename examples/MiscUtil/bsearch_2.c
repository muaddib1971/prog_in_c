
#include <stdio.h>
#include <stdlib.h>

int keyCompare(const void*, const void*);

typedef struct
{
  char *processor;
  unsigned clockRateMHz;
} ComputerRecord;

int main(void)
{
   ComputerRecord machines[] = { { "Alpha 21164PC", 500},
			         { "Pentium III", 800 },
		                 { "AMD Duron", 850 },
                                 { "AMD Athlon", 1000} };

   unsigned Nmachines = sizeof(machines)/sizeof(ComputerRecord);

   ComputerRecord target;
   ComputerRecord *pCR;

   printf("Please enter search target (eg. 500, 800, 850, 1000): ");
   if (scanf("%u", &target.clockRateMHz)==1)
   {
      if ((pCR = bsearch(&target, &machines[0], Nmachines, 
               sizeof(ComputerRecord), keyCompare)))
      {
         printf("%s %u\n", pCR->processor, pCR->clockRateMHz);
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

int keyCompare(const void* p1, const void* p2)
{
   const unsigned key1 =  ((const ComputerRecord*)p1)->clockRateMHz;
   const unsigned key2 =  ((const ComputerRecord*)p2)->clockRateMHz;

   return (key1==key2) ? 0 : ( (key1<key2) ? -1 : +1 );
}
