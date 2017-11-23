/** Demonstrates the use of fwrite() and fread().
 *  Please read fwrite_1.c and fread_1.c before you read this code.
 **/

#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 10
#define MAX_NAME 30

int main() {
   FILE *fp;
   char fname[MAX_NAME] = "test1.txt"; 
   int arr[MAX_NUM] = {2,4,6,8,10,12,14,16,18,20};
   int tempArr[MAX_NUM];
   int i, num= 0;

   /** open a file  in 'write' mode-- read fopen_1.c for more details 
    * */
   if( (fp =fopen(fname, "w")) == NULL) {
      printf("\n fopen failed - could not open file : %s\n", fname);
      exit(EXIT_SUCCESS);
   }

   /** fwrite() writes MAX_NUM * sizeof(int) number of bytes starting from arr
    *  to the file pointed by 'fp'. In other words it writes MAX_NUM of integers
    *  from pointed by the array 'arr' to the file pointed by the pointer 'fp'.
    **/
   num= fwrite(arr, sizeof(int), MAX_NUM, fp);
   printf("\n The number of elements written to the file = %d\n", num);

   fclose(fp);


   /** The code segment below now opens the file in read mode and using the 
    *  fread() function read the bytes written in teh code segment above 
    **/
   if ( (fp =fopen(fname, "r")) == NULL) {
      printf("\n fopen failed - could not open file : %s\n", fname);
      exit(EXIT_SUCCESS);
   } 

   /** reads the complete block of array in one go. Please note you can control
    *  the number of elements to be read by changing the value of 3rd parameter
    **/
   num= fread(tempArr, sizeof(int), MAX_NUM, fp);
   printf("\n The number of elements read from the file = %d\n", num);

   for(i=0; i < num; i++) {
      printf("\n %d# = %d", i+1, tempArr[i]);
   }

   fclose(fp);

   return(EXIT_SUCCESS);
}

