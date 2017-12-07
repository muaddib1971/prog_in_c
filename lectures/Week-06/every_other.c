#include "fsupport.h"

#define READER 1
#define WRITER 2

BOOLEAN every_other(FILE*, FILE*);
int main(int argc, char** argv)
{
    FILE * fpRead, *fpWrite;

    /* check the number of arguments */
    if(argc != NUMARGS)
    {
        print_usage();
        return EXIT_FAILURE;
    }
    /* gracefully open the files */
    fpRead = gropen(argv[READER]);
    fpWrite= gwopen(argv[WRITER]);
    /* print every second character to the output file */
    if(!every_other(fpRead, fpWrite))
    {
        fprintf(stderr, "Error: failure to copy and insert spaces.\n\n");
        return EXIT_FAILURE;
    }
    /* cleanup - close files */
    fclose(fpRead);
    fclose(fpWrite);
    return EXIT_SUCCESS;
}

/*****************************************************************************
* print every second character from the input file to the output file.
*****************************************************************************/
BOOLEAN every_other(FILE* fpRead, FILE* fpWrite)
{
    unsigned count=0;
    int ch;

    assert(fpRead);
    assert(fpWrite);

    /* get every second character from the file */
    while(ch = getc(fpRead), ch != EOF)
    {
        /* keep a count of the number of characters */
        ++count;
        /* if this is an even count */
        if(count % 2 == 0)
        {
            /* try to write to the file - test for EOF as that will
             * indicate a failure to write 
             */
            if(putc(ch, fpWrite) == EOF)
            {
                perror("failed to write to file");
                return FALSE;
            }
        }
    }
    /* all good! */
    return TRUE;
}


void print_usage(void)
{
    printf("incorrect command line arguments.\n\n");
    printf("please run this program as ./add_spaces <infile> <outfile>\n");
    printf("where <infile> is the name of the input file and \n");
    printf("<outfile> is the name of the output file to be created where \n");
    printf("the input file will be copied and additional spaces will be \n");
    printf("added.\n\n");
}
