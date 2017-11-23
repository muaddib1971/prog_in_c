#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME 25

int main(void) 
{
    FILE *fpRead;
    /* note that as we are initialising an array, this copies the value 
     * (text.txt) rather than assigning it. 
     * The location of all string literals is read only as they are actually
     * in the program code which is loaded.
     * If we had instead:
     * char * fname = "test.txt", this would be a pointer to readonly
     * memory (the executable loaded into memory) and if you tried to 
     * modify it you might get a segmentation fault.
     */
    char fname[MAX_NAME] = "test.txt"; 

    /** fopen() opens a file (filename passed as first parameter) in a 
     *  specific mode (passed as the second parameter). The file can be 
     *  opened in a "r", "w" or "a" mode for reading, writing and appending.
     **/
    fpRead =fopen(fname, "r");

    /** fopen() returns a pointer to the FILE that is associated with the 
     *  file `fname`. If the fname file cannot be accessed a NULL pointer 
     * is returned. You should always check for a NULL on all functions that
     * return a pointer as it is common practice to return a NULL on 
     * failure.
     * 
     * If the fname file does not exist, an attempt to open the file in 
     * "r" mode would return a NULL, whereas in case of "w" and "a" modes, 
     * it would create a new file with that name.
     *
     * Also note that passing "w" when there is already a file with that 
     * name will result in wiping out the data contained in the file
     * previously.
     **/
    if (fpRead == NULL) {
        printf("\n fopen failed - could not open file : %s\n", fname);
        exit(EXIT_SUCCESS);
    }
    else {
        printf("\n fopen successfully opened the file %s", fname);
    }

    /** fclose() terminates the association of the file pointer with the 
     *  file.
     *  It is a good practise to close all the files that are opened.
     *  Note that if you don't call fclose() there will be some memory which
     *  is not freed.
     **/
    fclose(fpRead);
    printf("\n file %s closed", fname);

    return(EXIT_SUCCESS);
}

