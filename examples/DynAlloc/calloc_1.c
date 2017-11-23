/** Demonstrates the use of calloc() **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define EVEN_BASE 2
#define LINELEN 80
#define EXTRACHARS 2
typedef enum { FALSE, TRUE } BOOLEAN;

/* these function prototypes would normally go in a header file */
void AssignEven(int *, int);
void PrintArray(int *, int);
void read_rest_of_line(void);

int main(void) 
{
        int *arr;  /* to be used as an array */
        size_t size;
        char line[LINELEN+EXTRACHARS];
        BOOLEAN success=FALSE;
        char * end;


        /* while data is not within the expected range, keep on asking */
        while(!success)
        {
                /* store the result from strtol before we validate it as
                 * being within the allows range for an unsigned int
                 */
                long lsize;

                /* we can split a string literal across two lines like 
                 * this */
                printf("\n Enter the number of even numbers that"
                                " you want to store > ");
                /* if the user presses ctrl-d (fgets will return NULL) 
                 * we will exit
                 */
                if(!fgets(line, LINELEN+EXTRACHARS, stdin))
                {
                        return EXIT_FAILURE;
                }
                /* check that the line entered was completely read into 
                 * the buffer */
                if(line[strlen(line)-1]!='\n')
                {
                        fprintf(stderr, "Error: the line you entered was"
                                        " too long.\n\n");
                        read_rest_of_line();
                        continue;
                }
                /* remove the newline as it was just a placeholder to 
                 * tell us that all data has been read from the input buffer
                 * */
                line[strlen(line)-1]=0;
                /* convert the string to an long integer */
                lsize = strtol(line, &end, 0);
                /* if end points to data other than the nul 
                 * terminator it means that there was some non-numeric 
                 * data in the string */
                if(*end)
                {
                        fprintf(stderr, "Error: data entered was not "
                                        "numeric. \nPlease try again.\n\n");
                        continue;
                }
                if( lsize < 0 || lsize > UINT_MAX)
                {
                        fprintf(stderr, "Error: data entered was "
                                        "outside the allowed range.\n"
                                        "Please try again.\n\n");
                }
                size = lsize;
                success = TRUE;
        }

        /**Allocate space such that 'size' number of integers can be stored.
         * calloc() takes two parameters, 1st is the the number of elements 
         * (in the case below the number of integers) and the 2nd parameter
         * is the size (number of bytes) of each element. The call to 
         * calloc() would allocate contiguous (next to each other) space in
         * memory for the requested number of elements (not sure why this is
         * normally mentioned as all memory allocation is contiguous) and 
         * initialise each element with zero; it returns the pointer 
         * (base address) to the first element of the sequence. 
         **/

        /* casting is for readability only - it is not required by the type 
         * checker. That is because calloc returns a void pointer - 
         * a pointer that can point to any kind of data.
         */
        arr = (int *)calloc(size, sizeof(int));

        if(arr == NULL) {
                /* provide a system generated error as this is a system 
                 * function
                 */
                perror("calloc failed");
                return(EXIT_FAILURE);
        }

        /* assign the first size even numbers to the array */
        AssignEven(arr, size);
        /* print them out */
        PrintArray(arr, size);

        /** What happens to the dynamic memory that was allocated by the 
         * call to calloc() at the end of the program ?? -- read free_1.c
         **/

        return(EXIT_SUCCESS);
}

/**************************************************************************
 * Fill the array passed in with the first n even numbers from 2 upwards.
 *************************************************************************/
void AssignEven(int *arr, int size) 
{
        int i, num;

        /** Assigning first 'size' number of even numbers in 'arr' **/ 
        for( i =0, num=EVEN_BASE; i < size; i++) {
                arr[i] = num;
                num+=EVEN_BASE;
        }  
}

/*************************************************************************
 * Iterate over the array passed in, printing the first n elements where
 * size holds the number for n
 ************************************************************************/
void PrintArray(int *arr, int size) 
{
        int i;

        for( i =0; i < size; i++) {
                printf("\n %d", arr[i]);
        }
        printf("\n");
}

/*************************************************************************
 * clear the buffer when the user has entered too much data
 ************************************************************************/
void read_rest_of_line(void)
{
        int ch;
        while(ch = getc(stdin), ch!=EOF && ch!='\n')
                ;
        clearerr(stdin);
}
