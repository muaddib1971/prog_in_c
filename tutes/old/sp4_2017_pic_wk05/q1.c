#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAXNUMS 10
#define EXPECTED_ARGS 2
#define INT_LEN 32
#define LINE_LEN INT_LEN* MAXNUMS
#define EXTRACHARS 2

typedef enum
{
        FALSE,
        TRUE
} BOOLEAN;

#define FILE_ARG 1
#define DELIM ","
#define DECIMAL 10

BOOLEAN strtoints(char line[], int array[], int* intcount)
{
        char* tok;
        int num_ints = 0;
        tok = strtok(line, DELIM);
        while (tok)
        {
                char* end;
                long lnum;
                /* "52" "76e" */
                lnum = strtol(tok, &end, DECIMAL);
                if (*end != '\0')
                {
                        fprintf(stderr,
                                "Error: non numeric data encountered.\n");
                        return FALSE;
                }
                if (lnum < INT_MIN || lnum > INT_MAX)
                {
                        fprintf(stderr,
                                "Error: number outside the range of an int!\n");
                        return FALSE;
                }
                array[num_ints++] = lnum;
                if (num_ints == MAXNUMS - 1)
                {
                        fprintf(stderr, "array capacity reached.\n");
                        *intcount = num_ints;
                        return TRUE;
                }
                tok = strtok(NULL, DELIM);
        }
        *intcount = num_ints;

        return TRUE;
}

int array_sum(int array[], int intcount)
{
        int sum = 0, count = 0;
        for (; count < intcount; ++count)
        {
                sum += array[count];
        }
        return sum;
}

BOOLEAN array_save(int array[], int sum, int count, char fname[])
{
        int savecount;
        FILE* writer;
        writer = fopen(fname, "w");
        if (!writer)
        {
                perror("fopen for writing");
                return FALSE;
        }
        for (savecount = 0; savecount < count; ++savecount)
        {
                if (fprintf(writer, "%d,", array[savecount]) <= 0)
                {
                        fprintf(stderr, "Error writing to file.\n");
                        return FALSE;
                }
        }
        fprintf(writer, "%d\n", sum);
        fclose(writer);
        return TRUE;
}

BOOLEAN load_array(char fname[], int numarray[], int* numcount)
{
        char line[LINE_LEN + EXTRACHARS];
        FILE* reader = fopen(fname, "r");
        if (!reader)
        {
                perror("fopen");
                return FALSE;
        }
        if (fgets(line, LINE_LEN + EXTRACHARS, reader) == NULL)
        {
                fprintf(stderr, "Error: there was no data to read!\n");
                fclose(reader);
                return FALSE;
        }
        if (line[strlen(line) - 1] != '\n')
        {
                fprintf(stderr,
                        "Error: line longer than the allowed buffer!\n");
                fclose(reader);
                return FALSE;
        }
        line[strlen(line) - 1] = 0;
        strtoints(line, numarray, numcount);
        return TRUE;
}

/* ./foo bar baz  - the program name is the first argument to the program */
int main(int argc, char* argv[])
{
        int array[MAXNUMS];
        int arrcount;
        int sum;

        if (argc != EXPECTED_ARGS)
        {
                fprintf(stderr, "Error: invalid number of arguments.\n");
                return EXIT_FAILURE;
        }
        if (!load_array(argv[FILE_ARG], array, &arrcount))
        {
                return EXIT_FAILURE;
        }
        sum = array_sum(array, arrcount);
        if (!array_save(array, sum, arrcount, argv[FILE_ARG]))
        {
                return EXIT_FAILURE;
        }

        return EXIT_SUCCESS;
}
