/** Demonstrates the use of free() -- please read calloc_1.c or malloc_1.c 
 *  before reading this code.
 **/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        int size;
        char line[LINELEN+EXTRACHARS];
        BOOLEAN success=FALSE;
        char * end;


        /* while data is not within the expected range, keep on asking */
        while(!success)
        {
                /* we can split a string literal accross two lines like 
                 * this */
                printf("\n Enter the number of even numbers that"
                                " you want to store > ");
                /* if the user presses ctrl-d (fgets will return NULL) we 
                 * will exit
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
                /* remove the newline as it was just a placeholder to tell
                 * us that all data has been read from the input buffer */
                line[strlen(line)-1]=0;
                /* convert the string to an integer */
                size = (int) strtol(line, &end, 0);
                /* if end points to data other than the nul terminator it 
                 * means that there was some non-numeric data in the 
                 * string */
                if(*end)
                {
                        fprintf(stderr, "Error: data entered was not "
                                        "numeric. \n"
                                        "Please try again.\n\n");
                        continue;
                }
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

        /* casting is for readability - it is not required by the type 
         * checker
         */
        arr = (int *)calloc(size, sizeof(int));

        if(arr == NULL) {
                /* provide a system generated error as this is a system 
                 * function
                 */
                perror("calloc failed");
                return(EXIT_FAILURE);
        }

        AssignEven(arr, size);
        PrintArray(arr, size);
        /** A common misunderstanding is that dynamically allocated memory 
         * does not get freed and returned to the operating system 
         * automatically on exit - that would be absurd; it would mean that
         * memory would be allocated forever to something that does not 
         * exist. While that is not the case, there is a danger that you 
         * may have runaway memory leaks - you aren't freeing the previous 
         * memory your program uses and then you allocate more. If you keep
         * going along this path, you will run out of memory sooner or 
         * later. 
         *
         * It is also impolite to leave your own junk behind. 
         *
         * The programmer needs to explicitly free the requested additional 
         * memory space before quiting the program.
         **/
        free(arr);
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
