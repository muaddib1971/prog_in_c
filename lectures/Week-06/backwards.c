#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "fsupport.h"

#define MAXSTRING 100
#define EXTRACHARS 2
#define HERE 0
#define BACKWARDS -2

int main(void)
{
    /* allow strings of up to 100 chars plus newline and null */
	char fname[MAXSTRING+EXTRACHARS];
    /* why is c an int? */
	int c;
	FILE *ifp;

    /* read a filename from the user - could have used command line 
     * arguments instead here. Rewrite this program to use command line
     * arguments
     */
	printf( "\nInput a filename: ");
    /* validate thate the user entered data (not a ctrl-d as first 
     * character
     */
	if(!fgets(fname, MAXSTRING+EXTRACHARS, stdin))
    {
        fprintf(stderr, "Error: no data was entered.\n\n");
        return EXIT_FAILURE;
    }
    /* validate that there is a newline at the enter of the entered string.
     * If there is not then the user has entered too much data 
     */
    if(fname[strlen(fname)-1] != '\n')
    {
        fprintf(stderr, "Error: too much data was entered.\n\n");
        return EXIT_FAILURE;
    }

    /* now we have validated that there was no buffer overflow, we can 
     * remove the newline as it has served its purpose
     */
    fname[strlen(fname)-1]=0;
    /* open the file using our custom function */
    ifp = gropen(fname);	
    /* seek to the end of the file */
    fseek(ifp, HERE , SEEK_END);	
    /* move backwards one character to the last character in the file */
	fseek(ifp, BACKWARDS+1, SEEK_CUR);	
    while (ftell(ifp) > 0)
	{
        /* get each character from the file */
		c = getc(ifp);	
        /* output it to the console */
		putchar(c);
        /* move back by two characters - why are we moving back by *two* 
         * characters? 
         */
		fseek(ifp, BACKWARDS, SEEK_CUR);	
	}
    /* close the file - whatever we open we must close */
	fclose(ifp);

	return EXIT_SUCCESS;
}
