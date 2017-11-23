
/*
 *  This example program demonstrates the use of printf
 *  from the standard C library (stdio)
 *  updated December 2015 by Paul Miller
 */

#include <stdlib.h>
#include <stdio.h>

#define STR_SIZE 8

int main(void) 
{
   int numI =10;
   float numF =12.10f; /* f to represent it is a float not a double */
   char ch = 'A';
   /* note that as this is declared as an array, the string on the 
    * right hand side is copied int arr, rather than assigned.
    */
   char arr[STR_SIZE] = "Hello";

   /** printf() is used to display content to the standard output.
    *  In the statement below the message within the 'control string' is
    *  printed as it is. Please note that there is no 
    *  'conversion specification' in the first printf() statement.
    **/
    printf("\n A simple program to demonstrate use of printf\n");
 
    /** In the statements below the 'control string' contains the 
     *  'conversion specification'. Conversion specifications begin with 
     *  a % symbol followed by a conversion character. The conversion 
     *  character corresponds to the data type of the variable whose 
     *  values is to be printed.
     **/
    
   printf("\n %%d for int    %d", numI);
   printf("\n %%f for float  %f", numF);
   printf("\n %%c for a character   %c", ch);
   printf("\n %%s for a string (a nul terminated array of char) %s\n", arr);

   return EXIT_SUCCESS;
}

