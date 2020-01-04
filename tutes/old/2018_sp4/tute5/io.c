#include "io.h"
#include <errno.h>

BOOLEAN load_file(const char fname[], char line[]) {
    FILE* reader;
    reader = fopen(fname, "r");
    if (!reader) {
        fprintf(stderr, "i/o error: %s\n", strerror(errno));
        perror("i/o error");
        return FALSE;
    }
    if (!fgets(line, BUFSIZ + EXTRACHARS, reader)) {
        fprintf(stderr, "Error: no data was read.\n");
        return FALSE;
    }
    /* *line == line[0] */
    if (*line == '\n' || line[strlen(line) - 1] != '\n') {
        fprintf(stderr,
                "Error: file is not in the correct format.\n There should be "
                "one line of comma-delimited integers in the file.\n");
    }
    line[strlen(line) - 1] = 0;
    return TRUE;
}

static char* strdup(const char orig[]) {
    char* copy = malloc(strlen(orig) + 1);
    if (!copy) {
        perror("malloc");
        return NULL;
    }
    strcpy(copy, orig);
    return copy;
}
#define DELIMS ","
#define DECIMAL 10
BOOLEAN extract_nums(const char line[], struct num_list* nums) {
    char* copy = strdup(line);
    char* tok;
    int tokcount = 0;

    tok = strtok(copy, DELIMS);
    while (tok) {
        char* end;
        /* process token */
        long lconvnum = strtol(tok, &end, DECIMAL);
        if (*end) {
            fprintf(stderr, "Error: the file has non-numeric data.\n");
            return FALSE;
        }
        if (lconvnum < INT_MIN || lconvnum > INT_MAX) {
            fprintf(
                stderr,
                "Error: the file has numbers outside the range of an int.\n");
            return FALSE;
        }
        nums->nums[tokcount++] = lconvnum;
        nums->count = tokcount;
        /* get next token */
        tok = strtok(NULL, DELIMS);
    }
    free(copy);
    return FALSE;
}

int sum_nums(struct num_list* list) {
    /* sum up the numbers in the array - use similar code to last week */
    return 0;
}

/* writing out - use fprintf */

BOOLEAN write_nums(const char fname[], struct num_list* nums, int sum) {
    return FALSE;
}
