/** Demonstrates the use of malloc() **/

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
                long lsize;

                /* we can split a string literal accross two lines like 
                 * this */
                printf("\n Enter the number of even numbers that"
                                " you want to store > ");
                /* if the user presses ctrl-d (fgets will return NULL) 
                 * we will exit
                 */
                if(!fgets(line, LINELEN+EXTRACHARS, stdin))
                {
                        return EXIT_SUCCESS;
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
                 * tell us that all data has been read from the input 
                 * buffer */
                line[strlen(line)-1]=0;
                /* convert the string to an integer */
                lsize =  strtol(line, &end, 0);
                /* if end points to data other than the nul terminator it 
                 * means that there was some non-numeric data in 
                 * the string */
                if(*end)
                {
                        fprintf(stderr, "Error: data entered was "
                                        "not numeric. \n"
                                        "Please try again.\n\n");
                        continue;
                }
                /* check that the number entered is in the range of an 
                 * unsigned int
                 */
                if(lsize < 0 || lsize > UINT_MAX)
                {
                        fprintf(stderr, "Error data entered was "
                                        "outside the allowed range.\n"
                                        "Please try again.\n\n");
                }
                size = lsize;
                success = TRUE;
        }

        /**Allocate space such that 'size' number of integers can be stored.
         * malloc() takes one parameter: size of the memory to be allocated,
         * in bytes. You cannot assume that the memory returned is 
         * initialised in any way. 
         **/

        /* casting is for readability - it is not required by the type 
         * checker. The reason for this is that malloc returns a void
         * pointer. That is a pointer that may hold any kind of data.
         */
        arr = (int *)malloc(size * sizeof(int));

        /* note: all system functions that return a pointer return NULL on 
         * failure */
        if(arr == NULL) {
                /* provide a system generated error as this is a system 
                 * function
                 */
                perror("malloc failed");
                return(EXIT_FAILURE);
        }

        AssignEven(arr, size);
        PrintArray(arr, size);

        /** What happens to the dynamic memory that was allocated by the 
         * call to calloc() at the end of the program ?? -- read free_1.c
         **/

        return(EXIT_SUCCESS);
}

void AssignEven(int *arr, int size) 
{
        int i, num;

        /** Assigning first 'size' number of even numbers in 'arr' **/ 
        for( i =0, num=EVEN_BASE; i < size; i++) {
                arr[i] = num;
                num+=EVEN_BASE;
        }  
}

void PrintArray(int *arr, int size) 
{
        int i;

        for( i =0; i < size; i++) {
                printf("\n %d", arr[i]);
        }
        printf("\n");
}


void read_rest_of_line(void)
{
        int ch;
        while(ch = getc(stdin) , ch!=EOF && ch!='\n')
                ;
        clearerr(stdin);
}
