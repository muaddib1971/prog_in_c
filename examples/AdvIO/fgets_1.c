/* This program accepts the data from the standard input using fgets() */ 
/* experiment with running this program and entering 28, 29 or 30 
 * characters. What number is output?
 * updated by Paul Miller December 2015
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_TEXT 30
#define EXTRACHARS 2

int main(void) 
{
   char text[MAX_TEXT+EXTRACHARS];
   int len;

   /* fgets() accepts a maximum of MAX_TEXT-1 characters from the 
    * standard input (stdin) and stores it into the character array (text).
    * On encountering either a newline character or end-of-file (EOF - 
    * represented on the command line by the user pressing ctrl-d), the 
    * input process is terminated a nul character is appended onto the 
    * array after the last input character. The address of the first 
    * character block of the array (text) is returned at the end of the 
    * input process if any data was read. 
    *
    * Please also read 'man fgets'
    **/
   printf("\n Enter a text of Maximum %d characters : ", MAX_TEXT-1);

    /* Always check the return value of fgets - fgets will return NULL
     * when no data has been transferred such as when the user has
     * pressed ctrl-d
     */
   if (fgets(text, MAX_TEXT, stdin) == NULL) 
   {
      fprintf(stderr, "\n no data was encountered.\n");
      return(EXIT_SUCCESS);
   }
      

    /* Read strlen_1.c for explanation on strlen() */
   len = strlen(text); 

   /* Read fgets_pitfalls.txt for the unexpected output */
   printf("\nThe length of the text (%s) entered is %d", text, len); 

   return(EXIT_SUCCESS);
}

