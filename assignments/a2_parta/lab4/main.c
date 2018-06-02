#include "main.h"

int main(int argc, char* argv[])
{
        FILE* in, *out;
        char lines[BUFSIZ][LINELEN + 1];
        int line_count;

        fclose(NULL);
        if (argc != NUMARGS)
        {
                fprintf(stderr, "Error: incorrect arguments passed in.\n");
                print_usage();
                return EXIT_FAILURE;
        }
        in = gropen(argv[INPUT]);
        out = gwopen(argv[OUTPUT]);
        if (in == NULL || out == NULL)
        {
                close_files(in, out);
                return EXIT_FAILURE;
        }
        if (read_file(in, lines, &line_count))
        {
                fprintf(stderr, "Error: problem reading from input file.\n");
                return EXIT_FAILURE;
        }
        reverse_lines(lines, line_count);
        if (!save_file(out, lines, line_count))
        {
                fprintf(stderr, "Error problem writing to the output file.\n");
                return EXIT_FAILURE;
        }
        close_files(in, out);
        return EXIT_SUCCESS;
}

void print_usage(void)
{
        printf("You should run this program by passing in 2 arguments: \n\n");
        printf("\t./reverse inputfile outputfile\n\n");
        printf("Where inputfile is the original file and outputfile will be "
               "a new file where each line is the reverse\n");
        printf("Of the input file.\n\n");
}
