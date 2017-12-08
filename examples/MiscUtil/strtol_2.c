/****************************************************************************
* Steven Burrows
* sdb@cs.rmit.edu.au
* Created March 2005 
* 
* strtol_2.c 
* Examples of the strtol function.
****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   char *ptr, *ptr2, *ptr3, *ptr4, *ptr5, *ptr6, *ptr7;
   char* text1 = "123";
   char* text2 = "asd";
   char* text3 = "123dfg";
   char* text4 = "dfg123";
   char* text5 = "dfg123fgh";
   char* text6 = "09"; 
   char* text7 = "0"; 
   long one, two, three, four, five, six, seven;
 
   one = strtol(text1, &ptr, 10);
   two = strtol(text2, &ptr2, 10);
   three = strtol(text3, &ptr3, 10);
   four = strtol(text4, &ptr4, 10);
   five = strtol(text5, &ptr5, 10);
   six = strtol(text6, &ptr6, 10);
   seven = strtol(text7, &ptr7, 10);
   
   printf("Example 1: '%ld' '%s'\n", one, ptr);
   printf("Example 2: '%ld' '%s'\n", two, ptr2);
   printf("Example 3: '%ld' '%s'\n", three, ptr3);
   printf("Example 4: '%ld' '%s'\n", four, ptr4);
   printf("Example 5: '%ld' '%s'\n", five, ptr5);
   printf("Example 6: '%ld' '%s'\n", six, ptr6);
   printf("Example 7: '%ld' '%s'\n", seven, ptr7);
 
   return EXIT_SUCCESS;
}


/****************

OUTPUTS:

Example 1: '123' ''
Example 2: '0' 'asd'
Example 3: '123' 'dfg'
Example 4: '0' 'dfg123'
Example 5: '0' 'dfg123fgh'
Example 6: '9' ''
Example 7: '0' ''

Examples 1, 6, and 7 are the valid ones.

****************/
