#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * This program illustrates how you can use the ctype library to process 
 * characters 
 **/
#define LINELEN 80
#define EXTRACHARS 2

/**
 * The different types of characters we want to keep track of - we have put
 * them into a struct as it is easier to keep track of them
 **/
struct counts
{
        unsigned tabs;
        unsigned spaces;
        unsigned punct;
        unsigned lower;
        unsigned upper;
        unsigned digits;
};

/**
 * definition of the boolean type for this program
 **/
typedef enum { FALSE, TRUE } BOOLEAN;

int main(void)
{
        /* the input string */
        char line[LINELEN + EXTRACHARS];
        BOOLEAN success = FALSE;
        /* stores the counts of each type of character */
        struct counts counts;
        unsigned /* iteration variable */char_count, 
        /* the length of the input string we have read */ length;
        /* zero initialize all the counts */
        memset(&counts, 0, sizeof(counts));
        /* validation loop for user input */
        while(!success)
        {
                /* prompt the user to enter a string */
                printf("Please enter a line for me to process: ");
                /* read in the string */
                fgets(line, LINELEN + EXTRACHARS, stdin);
                /* check if ther was buffer overflow */
                if(line[strlen(line)-1] != '\n')
                {
                        /* if there was, display an error message and 
                         * try again!
                         */
                        printf("Error: line is too long. "
                                "Please try again.\n");
                        continue;
                }
                /* we successfully read input from the console so we 
                 * can get rid of the newline character as it is just
                 * there to tell us whether we had buffer overflow
                 */
                success = TRUE;
                line[strlen(line)-1]=0;
        }
        length = strlen(line);
        /* iterate over the string read in and count the number of 
         * each type of character
         */
        for(char_count = 0; char_count < strlen(line); ++char_count)
        {
                if(line[char_count] == '\t')
                {
                        ++counts.tabs;
                }
                if(line[char_count] == ' ')
                {
                        ++counts.spaces;
                }
                if(ispunct(line[char_count]))
                {
                        ++counts.punct;
                }
                if(islower(line[char_count]))
                {
                        ++counts.lower;
                }
                if(isupper(line[char_count]))
                {
                        ++counts.upper;
                }
                if(isdigit(line[char_count]))
                {
                        ++counts.digits;
                }
        }
        /* print out the stats from the counts struct */
        printf("there were %u tabs, %u spaces, "
                "%u punctuation marks, %u lower case characters, \n"
                "%u upper case characters and %u digits in the string.\n", 
                counts.tabs, counts.spaces, counts.punct,
                counts.lower, counts.upper, counts.digits);
        return EXIT_SUCCESS;
}


