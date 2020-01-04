#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXTRA_CHARS 2
#define ONE_ARG 2

int main(int argc, char** argv)
{
#ifdef STRING
        char line[BUFSIZ + EXTRA_CHARS];
#else
        int ch;
#endif
        FILE * fp_reader;
        if(argc != ONE_ARG)
        {
                fprintf(stderr, "Error: incorrect number of arguments.\n");
                return EXIT_FAILURE;
        }
        fp_reader = fopen(argv[ONE_ARG -1], "r");
        if(!fp_reader)
        {
                perror("failed to open file");
                return EXIT_FAILURE;
        }
#ifdef STRING
        while(fgets(line, BUFSIZ + EXTRA_CHARS, fp_reader))
        {
                printf(line);
        }
#else
        while(ch = getc(fp_reader), ch != EOF)
        {
                if(!putc(ch, stdout))
                {
                        break;
                }
        }
#endif
        return EXIT_SUCCESS;
}
