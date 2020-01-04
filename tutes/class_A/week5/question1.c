#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REQUIRED_ARGS 2
#define FILE_ARG 1
#define MAXLEN 80
#define MAXNUMS 10
#define ssize_t long

typedef enum { FALSE, TRUE } BOOLEAN;

void read_rest_of_line(void) {}

BOOLEAN read_line(FILE* reader, char line[], size_t line_len) {
    if (!fgets(line, line_len, reader)) {
        /* read nothing at all */
        fprintf(stderr, "Error:  no data to read.\n");
        return FALSE;
    }
    /* read too much */
    if (line[strlen(line) - 1] != '\n') {
        fprintf(stderr, "Error: Buffer overflow.\n");
        read_rest_of_line();
        return FALSE;
    }
    /* successful read */
    line[strlen(line) - 1] = 0;
    return TRUE;
}

BOOLEAN strtoint(const char str[], int* output) {
    char* end;

    long lresult;

    lresult = strtol(str, &end, 10);
    if (lresult == LONG_MAX) {
        perror("strtol");
        return FALSE;
    }

    /*
                valid: "3"

                not valid: "3e"


                valid: "3                                        "

                valid: "                            345                     "
                not valid:"      3                             6"
                */

    while (isspace(*end)) {
        ++end;
    }
    if (*end != '\0') {
        fprintf(stderr, "Error: %s is not numeric.\n", str);
        return FALSE;
    }
    if (lresult < INT_MIN || lresult > INT_MAX) {
        fprintf(stderr, "Error: %s is outside the range for an int.\n", str);
        return FALSE;
    }

    *output = lresult;

    return TRUE;
}

ssize_t get_nums(char line[], int array[]) {
    char delims[] = ",";
    char* tok;
    int nums_converted = 0;
    tok = strtok(line, delims);
    while (tok) {
        /* try to extract a number */
        int curnum;
        if (strtoint(tok, &curnum)) {
            array[nums_converted] = curnum;
        } else {
            fprintf(stderr, "Error: could not convert number.\n");
            return LONG_MAX;
        }
        tok = strtok(NULL, delims);
        if (++nums_converted > MAXNUMS) {
            fprintf(stderr, "too many numbers in file.\n");
            return LONG_MAX;
        }
    }
    return nums_converted;
}

int array_sum(int array[], size_t array_size) {
    int sum = 0;
    int count;

    for (count = 0; count < array_size; ++count) {
        sum += array[count];
    }
    return sum;
}

BOOLEAN save_data(int read_nums[], size_t readcount, int sum,
                  const char filename[]) {
    int nums_written;
    FILE* writer = fopen(filename, "w");
    if (!writer) {
        perror("fopen in save_data");
        return FALSE;
    }
    for (nums_written = 0; nums_written < readcount; ++nums_written) {
        if (fprintf(writer, "%d,", read_nums[nums_written]) < 0) {
            perror("fprintf");
            return FALSE;
        }
    }
    if (fprintf(writer, "%d\n", sum) < 0) {
        perror("fprintf");
        return FALSE;
    }
    return TRUE;
}

/*
 * argv = {progname, datafilename, NULL};
 */
int main(int argc, char* argv[]) {
    FILE* reader;
    char line[80];
    int nums_read[10];
    int sum;
    size_t readcount;
    if (argc != REQUIRED_ARGS) {
        fprintf(stderr,
                "Error: invalid args. You need to provide a filename of a file "
                "to open.\n");
        return EXIT_FAILURE;
    }
    if (reader = fopen(argv[FILE_ARG], "r"), reader == NULL) {
        perror("fopen opening file in main");
        return EXIT_FAILURE;
    }
    if (!read_line(reader, line, MAXLEN)) {
        return EXIT_FAILURE;
    }

    readcount = get_nums(line, nums_read);
    if (readcount == LONG_MAX) {
        return EXIT_FAILURE;
    }
    sum = array_sum(nums_read, readcount);
    if (!save_data(nums_read, readcount, sum, argv[FILE_ARG])) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
