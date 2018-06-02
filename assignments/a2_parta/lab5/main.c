#include "main.h"

int main(int argc, char* argv[] )
{
    FILE * in, *out;
    /* array of lines to read input into */
    char lines[BUFSIZ][LINELEN + 1];
    /* how many lines have been read ? */
    int num_lines;

    /* check that the correct number of arguments has been read
     */
    if(argc != NUMARGS)
    {
        fprintf(stderr, "Error: invalid arguments passed in.\n");
        print_usage();

        return EXIT_FAILURE;
    }
    /* open the files */
    in = gropen(argv[IN]);
    out = gwopen(argv[OUT]);
    /* read in the input file */
    if(!read_file(in, lines, &num_lines))
    {
        fprintf(stderr, "Error: failed to read in %s\n", argv[1]);

        return EXIT_FAILURE;
    }
    /* remove every second character */
    alternate(lines, num_lines);
    /* save to output file */
    if(!save_file(out, lines, num_lines))
    {
        fprintf(stderr, "Error: failure to save file %s\n", argv[2]);
        return EXIT_FAILURE;
    }
    /* close the files as the program has been successful */

    /* all good :) */
    return EXIT_SUCCESS;
}

/**************************************************************************
 * display instructions on how to correctly use this program
 *************************************************************************/
void print_usage(void)
{
    printf("You may call this program as follows: \n");
    printf("\t./alternate infile outfile\n");
    printf("Where infile is an input file to process and "
        "outfile is the output file.\n");
    printf("The content of the output file on a successful "
        "run of this program will be \nevery second character ");
    printf("contained in the input file.\n\n");
}
