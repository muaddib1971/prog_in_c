#include "fsupport.h"

#define READER 1
#define WRITER 2

BOOLEAN insert_spaces(FILE*, FILE*);

int main(int argc, char** argv)
{
    FILE * fpRead, *fpWrite;

    /* check the number of arguments */
    if(argc != NUMARGS)
    {
        print_usage();
        return EXIT_FAILURE;
    }
    /* gracefully open the files for reading and writing */
    fpRead = gropen(argv[READER]);
    fpWrite= gwopen(argv[WRITER]);
    /* insert a new line between each line of text */
    if(!insert_spaces(fpRead, fpWrite))
    {
        fprintf(stderr, "Error: failure to copy and insert spaces.\n\n");
        return EXIT_FAILURE;
    }
    /* cleanup - close open files */
    fclose(fpRead);
    fclose(fpWrite);
    return EXIT_SUCCESS;
}

/*****************************************************************************
* copy each line from the first file to the second file and insert an 
* additional newline into the file after each line copied.
*****************************************************************************/
BOOLEAN insert_spaces(FILE* fpRead, FILE* fpWrite)
{
    char line[MAXWIDTH+EXTRASPACES];
    /* document the fact that we assume pointers passed in are valid */
    assert(fpRead);
    assert(fpWrite);
    /* get each line from the source file */
    while(fgets(line, MAXWIDTH+EXTRASPACES, fpRead))
    {
        /* copy to the destination file */
        fprintf(fpWrite,"%s", line);
        /* insert an extra newline */
        putc('\n', fpWrite);
    }
    return FALSE;
}

/* print out information on how to use the program */
void print_usage(void)
{
    printf("incorrect command line arguments.\n\n");
    printf("please run this program as ./add_spaces <infile> <outfile>\n");
    printf("where <infile> is the name of the input file and \n");
    printf("<outfile> is the name of the output file to be created where \n");
    printf("the input file will be copied and additional spaces will be \n");
    printf("added.\n\n");
}
