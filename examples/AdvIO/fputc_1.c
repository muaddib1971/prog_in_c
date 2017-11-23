#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* updated by Paul Miller, december 2015 */

int main(void) 
{
    FILE *fpRead;
    char *fname = "out.txt"; 
    int input =0;

    /** open a file in 'append' mode; ie. any new input that is written into
     *  the file associated with this ('fpRead') pointer will be added 
     *  after the last line.
     * */
    if( (fpRead =fopen(fname, "a")) == NULL) {
        perror("failed to open out.txt");
        return EXIT_FAILURE;
    }

    /** fgetc() reads a character from the file referred to by the FILE 
     *  pointer and returns the value of the character. Remember that there
     *  are three FILE pointers available at start: stdin, stdout and 
     *  stderr. 
     *
     *  If an error occurs while reading or when end of file is 
     *  encountered while reading EOF is returned.      
     *  The code below reads from the stdin unless EOF is encountered. To 
     *  simulate EOF under UNIX systems one can press <enter> follwed 
     *  by CTRL+D
     **/
    while((input =fgetc(stdin)) != EOF) {
        /** fputc writes the value of a character 'input' to the file 
         *  associated with the pointer 'fpRead'.
         *  In the code below, if an error occurs while writing to the 
         *  file EOF is returned and error message is printed to the 
         *  standard output; 
         *  after which the code breaks out of the 'while' loop construct.
         *
         *  If the character is successfully written then the character
         *  cast to an int ir returned from fputc.
         *
         *  The difference between fputc and putc is that putc is a macro
         *  whereas fputc is a function. So fputc has a time and memory 
         *  overhead that putc does not.
         **/
        if( fputc(input, fpRead) == EOF) {
            printf("\n fputc failed -- cannot write to the file %s", fname);
            break;
        }
    }

    /** fclose() terminates the association of the file pointer with the 
     *  file. If you do not call fclose on a FILE pointer you will have
     *  unfreed memory at the end of your program as fclose() frees the 
     *  memory allocated to the FILE * by fopen().
     **/
    fclose(fpRead);

    return(EXIT_SUCCESS);
}

