#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINELEN 80
#define EXTRACHARS 2
int main(void) {
    char line[LINELEN + EXTRACHARS];
    int linecount;

    while (fgets(line, LINELEN + EXTRACHARS, stdin) != NULL && strcmp("\n", line)) {
        ++linecount;
        printf("line number %d: ", linecount);
        puts(line);
    }
    return EXIT_SUCCESS;
}

