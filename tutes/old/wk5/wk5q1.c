#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <assert.h>

typedef enum { FALSE, TRUE } BOOLEAN;

#define MAX_NUMS 10
#define MAX_ARGS 2
#define FILE_ARG 1
#define LINE_LEN 80
#define EXTRA_CHARS 2
#define EOL '\n'
#define DECIMAL 10

static BOOLEAN int_from_string(const char input[], int * output)
{
        char * end;
        long result;

        result = strtol(input, &end, DECIMAL);
        if(*end)
        {
                fprintf(stderr, "Error: %s is not a valid number.\n", 
                                input);
                return FALSE;
        }
        if(result < INT_MIN || result > INT_MAX) 
        {
                fprintf(stderr, "Error: %ld is not in the range of an "
                                "int.\n", result);
                return FALSE;
        }
        *output = result;
        return TRUE;
}

static BOOLEAN line_to_array(char inputline[], int array[], 
                int * num_entered)
{
        char * tok;
        int cur_ind = 0, cur_num = 0;
        tok = strtok(inputline, ",");
        while(tok && cur_ind < MAX_NUMS)
        {
                if(int_from_string(tok, &cur_num))
                {
                        array[cur_ind++] = cur_num;
                }
                else
                {
                        return FALSE;
                }
                tok = strtok(NULL, ",");
        }
        *num_entered = cur_ind;
        return TRUE;
}

static int array_sum(int array[], int length)
{
        int sum = 0;
        int count = 0;

        assert(length > 0);

        for(count = 0; count < length; ++count)
        {
                sum += array[count];
        }
        return sum;
}

static BOOLEAN write_nums(int array[], int array_count, int total, 
                const char * fname)
{
        int count;
        FILE * fp_writer = fopen(fname, "w");
        if(!fp_writer)
        {
                perror("failed to open file for writing");
                return FALSE;
        }
        for(count = 0; count < array_count; ++count)
        {
                if(fprintf(fp_writer, "%d,", array[count]) <= 0)
                {
                        perror("failed to save data");
                        return FALSE;
                }
        }
        fprintf(fp_writer, "%d\n", total);
        fclose(fp_writer);
        return TRUE;
}

int main(int argc, char * argv[])
{
        int nums[MAX_NUMS];
        int num_entered=0;
        FILE * fp_reader;
        char line[LINE_LEN + EXTRA_CHARS];
        int sum;

        if(MAX_ARGS != argc)
        {
                fprintf(stderr, "Error: invalid arguments.\n");
                return EXIT_FAILURE;
        }

        fp_reader = fopen(argv[FILE_ARG], "r");
        if(!fp_reader)
        {
                perror("failed to open file");
                return EXIT_FAILURE;
        }
        if(fgets(line, LINE_LEN + EXTRA_CHARS, fp_reader))
        {
                if(line[strlen(line)-1] != EOL)
                {
                        fprintf(stderr, "Error: line was too long.\n");
                        return EXIT_FAILURE;
                }

                line[strlen(line)-1]=0;
                if(!line_to_array(line, nums, &num_entered))
                {
                        return EXIT_FAILURE;
                }
                sum = array_sum(nums, num_entered);
                fclose(fp_reader);
        }
        else
        {
                fprintf(stderr, "Error: no data was read.\n");
                return EXIT_FAILURE;
        }
        write_nums(nums, num_entered, sum, argv[FILE_ARG]);
        return EXIT_SUCCESS;
}
