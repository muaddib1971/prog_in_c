/* This program demonstartes the use of strcpy() function */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT 20

int main(void) 
{
   char text1[MAX_TEXT] = "Hello";
   char text2[MAX_TEXT] = "World";

   printf("\n Original Text1 = (%s) \n Original Text2 = (%s)\n", text1, text2);

   /** The strcpy() function below copies the COMPLETE string pointed by
    * text2 into string text1. It overwrites anything currently contained
    * in text1 although with judicious use of pointers, you could get 
    * similar functionality to strcat. Can you think of how?
    **/
   strcpy(text1, text2); 

   printf("\n Text1 after strcpy() =(%s)", text1);
   printf("\n Text2 after strcpy() =(%s)\n",text2);
   printf("\n");

   return EXIT_SUCCESS;
}
