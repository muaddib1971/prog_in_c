#include "main.h"

int main(int argc, char* argv[])
{
    FILE * in, *out;
    char lines[BUFSIZ][LINELEN+1];
    int num_lines;

    /* validate command line arguments */
    if(argc != NUMARGS)
    {
        fprintf(stderr, "Error: incorrect arguments passed into %s\n",
            *argv);
        print_usage();
        return EXIT_FAILURE;
    }

    /* open the files */
    in = gropen(argv[IN]);
    out = gwopen(argv[OUT]);
    /* read in data from the input file */
    if(read_file(in, lines, &num_lines))
    {
        fprintf(stderr, "Error: failure to read from the input file.\n");
        close_files(in,out);
        return EXIT_FAILURE;
    }
    /* shuffle each line of the input so it is nice and jumbled */
    shuffle(lines, num_lines);
    /* save the file */
    if( !save_file(out, lines, num_lines) )
    {
        fprintf(stderr, "Error: failure to write to output file.\n");
        close_files(in,out);
        return EXIT_FAILURE;
    }
    /* close the files */
    close_files(in,out);
    return EXIT_SUCCESS;
}

/***********************************************************************
 * output instructions on how to correctly use this program
 **********************************************************************/
void print_usage(void)
{
    printf("This program is designed to shuffle each line of a file "
        "and output it to \nanother file.\n");
    printf("\n You call this program in the following fashion:\n\n");
    printf("\t./shuffle infile outfile\n\n");
    printf("Where infile is the input file and outfile is the output "
        "file with the \ncontents shuffled.\n");
}
