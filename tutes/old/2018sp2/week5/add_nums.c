#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
/* in .h */
#define MAXARRAY 10
#define NUMARGS 2
#define LINELEN 80
#define EXTRACHARS 2
#define FILEARG 1

void display_usage(void);
/* in .c */
typedef enum
{
        FALSE,
        TRUE
} BOOLEAN;

BOOLEAN readline(char* fname, char* output, int len)
{
        /* only one line */
        FILE* fpreader = fopen(fname, "r");
        if (!fpreader)
        {
                /*
                perror("fopen failed");
                */
                fprintf(stderr, "fopen failed: %s\n", strerror(errno));
                fclose(fpreader);
                return FALSE;
        }
        /* #define NULL (void*)0 */
        if (fgets(output, len + EXTRACHARS, fpreader))
        {
                /* process the line */
                if (output[strlen(output) - 1] != '\n')
                {
                        fprintf(stderr, "Error: line too long.\n");
                        fclose(fpreader);
                        return FALSE;
                }
                output[strlen(output) - 1] = 0;
                fclose(fpreader);
                return TRUE;
        }
        fprintf(stderr, "Error no data read.\n");
        fclose(fpreader);
        return FALSE;
}

BOOLEAN split_line(char* line, char* tokens[], int* numtoks)
{
        return FALSE;
}

BOOLEAN get_nums(char* const tokens[], int numtokens, int array[])
{
        return FALSE;
}

int sum_nums(int nums[], int numtokens)
{
        return EOF;
}

BOOLEAN save_nums(char fname[], int nums[], int numtokens, int sum)
{
        FILE* fpwriter;
        int count;

        fpwriter = fopen(fname, "w");
        for (count = 0; count < numtokens; ++count)
        {
                if (fprintf(fpwriter, "%d,", nums[count]) <= 0)
                {
                        fprintf(stderr, "failed to write data\n");
                }
        }
        if (fprintf(fpwriter, "%d\n", sum) <= 0)
        {
                fprintf(stderr, "Error: failed to write the total.\n");
        }
        fclose(fpwriter);
        return TRUE;
}

int main(int argc, char* argv[])
{
        int nums[MAXARRAY];
        char* tokens[MAXARRAY];
        char line[LINELEN + EXTRACHARS];
        int numtokens;
        int sum;

        if (NUMARGS != argc)
        {
                display_usage();
                return EXIT_FAILURE;
        }

        if (!readline(argv[FILEARG], line, LINELEN))
        {
                return EXIT_FAILURE;
        }

        if (!split_line(line, tokens, &numtokens))
        {
                return EXIT_FAILURE;
        }

        if (!get_nums(tokens, numtokens, nums))
        {
                return EXIT_FAILURE;
        }

        sum = sum_nums(nums, numtokens);

        if (!save_nums(argv[FILEARG], nums, numtokens, sum))
        {
                return EXIT_FAILURE;
        }
        return EXIT_SUCCESS;
}

void display_usage(void)
{
        puts("Please only enter one argument - the file you wish to open!");
}
