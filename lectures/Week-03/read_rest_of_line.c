#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * This function clears the buffer by reading one character at a 
 * time from the buffer until there is no leftover input. You 
 * should only call this function when there is leftover input.
 **/
void read_rest_of_line(void)
{
        /* character to read from the buffer */
        int ch;
        /* keep reading the buffer until we run out of 
         * leftover input 
         */
        while(ch=getchar(), ch!=EOF&&ch!='\n');
        /* clear out the error status of the file pointer */
        clearerr(stdin);
}

typedef enum {FALSE, TRUE} BOOLEAN;
#define LINELEN 80
#define EXTRACHARS 2
int main(void)
{
        char line[LINELEN + EXTRACHARS];
        BOOLEAN success = FALSE;
        while(!success)
        {
                printf("please enter your name: ");
                /* read in the line */
                fgets(line, LINELEN + EXTRACHARS, stdin);
                /* test if the newline character was stored - if 
                 * it was 
                 * not then we have buffer overflow and therefore
                 * must clear the buffer 
                 */
                if(line[strlen(line) - 1] != '\n')
                {
                        printf("buffer overflow!\n");
                        read_rest_of_line();
                        continue;
                }
                /* if we get here then we have successfully 
                 * gotten input
                 * of a valid length so we set success to TRUE
                 */
                success = TRUE;
        }
        /* remove the newline character as it is no longer
         * needed */
        line[strlen(line)-1] = 0;
        printf("%s\n", line);

        return EXIT_SUCCESS;
}
