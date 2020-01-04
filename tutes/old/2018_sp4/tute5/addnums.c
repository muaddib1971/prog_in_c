#include <limits.h> /* for INT_MAX and INT_MIN */
#include <stdio.h>  /* fgets, printf, etc */
#include <stdlib.h> /* EXIT_SUCCESS */
#include <string.h> /* strtok */
#include "io.h"

#define NUMARGS 2
/* lvalues - go on the left hand side of an assignment
 * rvalues - go on the right hand side of an assignment
 */
#define FILEARG 1

/* stdin - by default reads from the keyboard
 * stdout - normal output file by default goes to the screen
 * stderr - error output file by default goes to the screen
 */
int main(int argc, char* argv[]) {
    const char* fname;
    struct num_list nums;
    int sum;
    char line[BUFSIZ + EXTRACHARS];
    if (NUMARGS != argc) {
        fprintf(stderr,
                "Error: incorrect args. You need to provide a file to read "
                "from.\n");
        return EXIT_FAILURE;
    }
    fname = argv[FILEARG];
    if (!load_file(fname, line)) {
        return EXIT_FAILURE;
    }
    if (!extract_nums(line, &nums)) {
        fprintf(stderr, "Error: could not extract numbers from the file.\n");
        return EXIT_FAILURE;
    }
    sum = sum_nums(&nums);
    if (!write_nums(fname, &nums, sum)) {
        fprintf(stderr, "Failed to write numbers to the file.\n");
    }
    return EXIT_SUCCESS;
}
