#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 25
/* updated December 2015 by Paul Miller */
int main(void) 
{
   FILE *fpRead;
   char *fname = "test.txt"; 
   int input=0;

   /** open a file  -- read fopen_1.c for more details 
    * */
   if( (fpRead =fopen(fname, "r")) == NULL) 
   {
      printf("\n fopen failed - could not open file : %s\n", fname);
      exit(EXIT_SUCCESS);
   }

   /** fgetc() next character from the file associated with 'fpRead' 
    *  (passed as a parameter) and returns the value of the character read.
    *  On reaching the end of file or if an error occurs while reading, 
    *  (-1) EOF is returned.
    *
    *  Below code reads one character at a time from the file and prints 
    *  it on the screen.
    *
    *  Please note that fgetc() with 'stdin' passed as a parameter behaves 
    *  similar to getc(). The difference is that fgetc() is implementented
    *  as a function whereas getc() is implemented as a macro. 
    *
    *  This means that there is an overhead for each call to fgetc() that 
    *  does not exist for getc().
    **/
   while ( input = fgetc(fpRead),input !=EOF) 
   {
      printf("\n%c", input);
   }

   /** fclose() terminates the association of the file pointer with the 
    *  file.
    *  It is a good practise to close all the files that are opened
    *  If you do not call fclose, there will be memory that is not freed.
    **/
   fclose(fpRead);

   return(EXIT_SUCCESS);
}

