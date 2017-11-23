#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 256
#define EXTRACHARS 2
/* updated december 2015 by Paul Miller */

int main() {
    FILE *fpRead;
    char * fname = "test.txt" ;
    char line[MAX_LINE + EXTRACHARS];

    /** fopen() opens a file (filename passed as first parameter) in a 
     *  specific mode (passed as the second parameter). The file can be 
     *  opened in a "r", "w" or "a" mode for reading, writing and appending.
     *  Please note that as fopen returns a pointer, it is actually doing
     *  memory allocation. If you don't call fclose() at the end of your
     *  program you will have a memory leak.
     **/
    fpRead =fopen(fname, "r");

    /** fopen() returns a pointer to the FILE that is associated with the 
     *  file fname. If the fname file cannot be accessed a NULL pointer is 
     *  returned.  If the fname file does not exist, an attempt to open the
     *  file in "r" mode would return a NULL, whereas in case of "w" and 
     * "a" modes, it would create a new file with that name.
     **/
    if (!fpRead) 
    {
        printf("\n fopen failed - could not open file : %s\n", fname);
        exit(EXIT_SUCCESS);
    }

    /** fgets() reads the line from the the current position pointed by 
     *  the FILE pointer 'fpRead' and stores it in the variable 'line'. 
     *  A maximum of MAX_LINE + 1 characters is copied and a nul character
     *  is appended. For more details on fgets() read fgets_1.c and 
     *  fgets_2.c
     **/
    while ( fgets(line, MAX_LINE+EXTRACHARS, fpRead) != NULL ) {
        printf("\n%s", line);
    }

    /** fclose() terminates the association of the file pointer with the file.
     *  It is a good practise to close all the files that are opened
     *  It is your job to cleanup anything you create but it also if you 
     *  don't call fclose, there will be some memory that has not been
     *  freed.
     **/
    fclose(fpRead);

    return(EXIT_SUCCESS);
}

