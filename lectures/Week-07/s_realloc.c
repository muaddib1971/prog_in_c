#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "safemalloc.h"

#define FIRSTALLOCATED 10
#define LINELEN 80
#define EXTRA_CHARS 2

int main(void)
{
    BOOLEAN quit=FALSE;
    unsigned count ; /* counter for printing out the numbers */
    int * nums;
    /* we need to keep track of the number of elements allocated versus the 
     * number currently in use 
     */
    unsigned curallocated=FIRSTALLOCATED;
    unsigned curfilled=0;
    /* allocate an initial array of 10 items */
    nums = safecalloc(FIRSTALLOCATED, sizeof(int));
    /* we'll keep asking for more numbers until the user quits or we run out of
     * memory
     */
    while(!quit)
    {
        char line[LINELEN + EXTRA_CHARS];
        char * end; 
        char * inputresult;
        int insertnum;

        /* grab the next number from the user */
        printf("Please enter a number to store: ");
        inputresult=fgets(line, LINELEN + EXTRA_CHARS, stdin);
        /* when will this happen? */
        if(!inputresult)
            break;
            /* if we have filled up the slots, allocate more memory */
        if(curfilled == curallocated)
        {
            /* double the memory we allocate each time to minimise the 
             * allocations */
            void * memresult = saferealloc(nums, 2*curallocated*sizeof(int));
            if(memresult)
            {
                nums = memresult;
                curallocated *= 2;
            }
            else
            {
                /* memory allocation failed */
                fprintf(stderr, "Error: we ran out of memory and so "
                    "cannot process further input.\n");
                break;
            }
        }
        /* check for buffer overflow */
        if(line[strlen(line)-1] != '\n')
        {
            fprintf(stderr, "Error: there was too much input."
                " Please try again.\n");
            continue;
        }
        line[strlen(line)-1]=0;
        /* extract the number */
        insertnum=(int)strtol(line, &end, 0);
        if(*end)
        {
            fprintf(stderr, "Error: your input was not valid."
                " Please try again.\n");
            continue;
        }

        /* add the number to the array */
        nums[curfilled++]=insertnum;
    }
    for(count = 0; count < curfilled; ++count)
    {
        printf("%d\n", nums[count]);
    }
    free(nums);
    return EXIT_SUCCESS;
}
