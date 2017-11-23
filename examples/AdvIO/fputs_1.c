#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 50
#define EXTRACHARS 2

/**
 * updated December 2015 by Paul Miller
 **/
int main(void) 
{
        FILE *fpRead;
        char *fname = "out.txt"; 
        char input[MAX_INPUT+1] ="";/* +1 for the nul terminator */

        /** open a file in 'append' mode; ie. any new input that is 
         * written into the file associated with this ('fpRead') 
         * pointer will be added after the last line.
         * */
        if( (fpRead =fopen(fname, "a")) == NULL) 
        {
                perror("failed to open out.txt");
                return EXIT_FAILURE;
        }

        /** fgets() will read one line of input from the stdin 
         * (read fgets_1.c and fgets_2.c for more details).
         **/
        if(fgets(input, MAX_INPUT+EXTRACHARS, stdin) == NULL) {
                fprintf(stderr, "\nctrl-d was pressed\n");
                return EXIT_FAILURE;
        }

        /**
         * test if the entire line being read from the file has been 
         * successfully stored into the input array
         **/
         if(input[strlen(input)-1] != '\n')
         {
                 fprintf(stderr, "Error: there was buffer overflow.\n");
                 return EXIT_FAILURE;
         }

        /**
         * remove the nul terminator as we now know that all input has 
         * been processed
         **/
         input[strlen(input)-1]='\0';

        /** 
         * fputs() is a file output function - it writes the nul
         * terminated string pointed to by 'input' to the file associated 
         * with FILE pointer 'fpRead'.
         * 
         * On successful operation, it return a non-negative number 
         * and otherwise returns an EOF (-1) on an unsuccessful attempt.
         **/   

        printf("\n\n Writing to the file %s ...\n", fname);
        if (fputs(input, fpRead) == EOF) 
                printf("\n Error in writing to the file %s", fname);

        /** 
         * fclose() terminates the association of the file pointer with the 
         * file. If you do not call fclose() you will have a memory leak.
         **/
        fclose(fpRead);

        return(EXIT_SUCCESS);
}

