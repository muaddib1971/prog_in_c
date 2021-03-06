#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum
{
        FALSE,
        TRUE
} BOOLEAN;

enum input_result
{
        IR_FAILURE,
        IR_SUCCESS,
        IR_EOF
};

#define EXTRA_CHARS 2
#define INPUT_LEN 50
#define MAX_NUMBERS 10
#define DECIMAL 10

void clear_buffer(void)
{
        int ch;
        while (ch = getc(stdin), ch != EOF && ch != '\n')
                ;
        clearerr(stdin);
}

/* NULL is a pointer!! (void*)0 */

enum input_result read_string(const char prompt[], char output[], int outlen)
{
        BOOLEAN success = FALSE;
        do
        {
                printf("%s", prompt);
                if (fgets(output, outlen + EXTRA_CHARS, stdin) == NULL)
                {
                        return IR_EOF;
                }
                if (output[strlen(output) - 1] != '\n')
                {
                        clear_buffer();
                        fprintf(stderr,
                                "Error: too much input. Please try again. \n");
                }
                else
                {
                        output[strlen(output) - 1] = 0;
                        success = TRUE;
                }
        } while (!success);
        return IR_SUCCESS;
}

/**
 * tokenize the string, retrieve each number from the string.
 **/
int get_numbers(char input[], int input_numbers[])
{
        int numconversions = 0;
        char* tok;
        /* begin string tokenization */
        tok = strtok(input, ";");
        while (tok)
        {
                char* end;
                long lnum;
                /**
                 * extract the number from the token
                 **/
                lnum = strtol(tok, &end, DECIMAL);
                /**
                 * skip over any trailing whitespace
                 **/
                while (isspace(*end))
                {
                        ++end;
                }
                /**
                 * if we have not reached nul terminator there is trailing
                 * characters and thus this is not a valid number
                 **/
                if (*end != '\0')
                {
                        fprintf(stderr, "Error: number is not numeric.\n");
                        return EOF;
                }
                /**
                 * double check that the number is within the range of an int.
                 * On a 64 bit system, a long is 8 bytes but an int is only
                 * 4 bytes so there is a lot of scope for overflow
                 **/
                if (lnum < INT_MIN || lnum > INT_MAX)
                {
                        fprintf(stderr, "Error: number is not within the range "
                                        "of an int.\n");
                        return EOF;
                }
                /* all good so store the number and retrieve the next
                 * token
                 */
                input_numbers[numconversions++] = (int)lnum;
                tok = strtok(NULL, ";");
        }
        return numconversions;
}

/**
 * sum up the numbers in the array
 **/
int sum_array(int numbers[], int numcount)
{
        int count;
        int result = 0;
        /* iterate over the array, summing up all the numbers */
        for (count = 0; count < numcount; ++count)
        {
                result += numbers[count];
        }
        return result;
}

int main(void)
{
        char input[INPUT_LEN + EXTRA_CHARS];
        int input_numbers[MAX_NUMBERS];
        int num_conversions;

        /**
         * read the string from the keyboard
         **/
        if (read_string("Please enter a semicolon-separated list of numbers "
                        "(up to ten): ",
                        input, INPUT_LEN) == IR_EOF)
        {
                return EXIT_FAILURE;
        }
        /**
         * get the numbers contained in the string
         **/
        if ((num_conversions = get_numbers(input, input_numbers)) <= 0)
        {
                fprintf(stderr, "Error in your input.\n");
                return EXIT_FAILURE;
        }
        /**
         * sum up the array values and print the output
         **/
        printf("The total of the numbers entered is: %d\n",
               sum_array(input_numbers, num_conversions));
        return EXIT_SUCCESS;
}
