/**************************************************************************
 * COSC1076 - Advanced Programming Techniques
 * Assessed lab 1 - debugging
 * Created by Paul Miller
 *
 * This file handles the minimal I/O requirements of the program.
 *************************************************************************/
#include "input.h"

/**************************************************************************
 * read_rest_of_line() - clears the input buffer. This should only be 
 * called when you detect there is buffer overflow. Do not call this 
 * function otherwise or you may get strange behaviour.
 *************************************************************************/
void read_rest_of_line(void)
{
    int ch;
    /* pull characters from the input buffer one at a time until
     * we run out of characters to pull
     */
    while(ch = getc(stdin), ch != EOF)
        /* empty while loop */;
    /* reset the error status of the input FILE pointer */
    clearerr(stdin);
}

/**************************************************************************
 * get_name() - gets the name of a player from the user. We continue asking
 * for input until we get a valid input. Invalid input includes an empty 
 * string, no input (ctrl-d) or input longer than what was expected.
 *
 * @param name the variable we will save the name of the player to
 * @param the prompt to display on the screen
 *************************************************************************/
void get_name(char * name, char* prompt)
{
    BOOLEAN success = FALSE;
    /* while input is not what we are after, keep on asking */
    while(success)
    {
        /* display the prompt */
        printf("%s: ", prompt);
        /* get a line of input from the console */
        if(fgets(name, NAMELEN + EXTRACHARS, stdin) == NULL || *name=='\n')
        {
            /* if the input was empty */
            fprintf(stderr, "Error - no input. Please try again.\n\n");
            continue;
        }
        /* if the string entered was too long or if it was empty */
        if(name[strlen(name)] !='\n')
        {
            /* if the input entered was longer than expected */
            read_rest_of_line();
            fprintf(stderr, "Error: input too long. Please try again.\n\n");
            continue;
        }
        /* remove the newline and set the status to success as we have 
         * received valid input */
        name[strlen(name)]=0;
        success = TRUE;
    }
}

