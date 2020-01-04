#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINELEN 80
#define EXTRACHARS 2
int main(void) {
    /* note that the line is not initialised */
    char line[LINELEN + EXTRACHARS];
    char stuff[3] = "hello";
    char moo[] = "hello";
    char* pline = "hello";
    /* comparison of unitialised value !!! */
    if (strcmp(line, "hello") == 0) {
        printf("the greeting has been set correctly.\n\n");
    } else
        printf("omg, no greeting\n");
    return EXIT_SUCCESS;
}
