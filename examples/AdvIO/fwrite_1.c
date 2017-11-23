/** Demonstrates the use of fwrite() **/

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 256
#define MAX_NAME 30

int main() {
   FILE *fpWrite;
   char *fname = "test1.bin"; 
   int data =10;
   size_t numbytes= 0;

   /** open a file  in 'write' mode-- read fopen_1.c for more details 
    * */
   if( (fpWrite =fopen(fname, "w")) == NULL) 
   {
       perror("failed to open test1.bin for writing");
       return EXIT_FAILURE;
   }

   /** fwrite() writes a specified number of bytes (2nd parameter multiplied
    *  by 3rd parameter) from a memory location (first parameter) to file 
    *  (pointed by the last parameter).
    *  Please note that since the byte blocks are wrtitten to the file, the
    *  content may not be in human readable format. To read the content of 
    *  the file one should use fread() --  refer to fread_1.c
    *
    *  Also note that the byte order for numeric types will be according
    *  to the 'endianness' of the architecture the program is running on
    *  so while this will result in a smaller file, the file will be
    *  less portable. Do a web search for 'endianness' for more information
    *  about this.
    **/  
   numbytes = fwrite(&data, sizeof(int), 1, fpWrite);
   printf("\n Total number of bytes written to the file = %lu\n", numbytes);

   fclose(fpWrite);

   return(EXIT_SUCCESS);
}

