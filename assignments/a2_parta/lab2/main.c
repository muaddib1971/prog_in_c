#include "main.h"

int main(int argc, char * argv[])
{
    /* store command line arguments */
    char * inname = argv[INFILE], 
        * outname = argv[OUTFILE], 
        * stopname = argv[STOPFILE];
    /* the 2d array to store the words to be removed 
     */
    char stoplist[MAXSTOPWORDS][MAXSTOPLEN];
    /* how many stop words are there? */
    long stopcount;

    /* FILE pointers used in the program */
    FILE * infile, *outfile, *stopfile;

    /* test the number of command line arguments */
    if( argc != NUM_ARGS )
    {
        print_usage();
        return EXIT_FAILURE;
    }
    /* open the files */
    infile = gropen(inname);
    outfile = gwopen(outname);
    stopfile = gropen(stopname);

    /* read in the stop list */
    stopcount = get_stop_list(stopfile, stoplist);
    /* test that the stop list reading was successful */
    if(stopcount)
        /* if so, read in the file we will process, and write out the 
         * data to a file after having removed the stop words and delimiters
         */
        stop_me(infile, outfile, stoplist, stopcount);
    else
    {
        /* if there was a problem reading from the stop file, 
         * print an error and exit
         */
        fprintf(stderr, "Error reading stopfile\n");
        /* make sure you close all open files */
        closefiles(infile, outfile, stopfile);
        return EXIT_FAILURE;
    }
    /* success! but we must make sure to close all open files */
    closefiles(infile, outfile, stopfile);
    return EXIT_SUCCESS;
}

/*************************************************************************
 * print out instructions on how to use the program
 ************************************************************************/
void print_usage(void)
{
    printf("Invalid command line arguments entered. "
            "You should enter: \n"
            "./stopper <inputfile> <stopfile> <outputfile>\n"
          );
}
