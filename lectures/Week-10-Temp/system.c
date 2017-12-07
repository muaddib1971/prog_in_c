#include <stdio.h>
#include <stdlib.h>

#define LINELEN 80
#define EXTRACHARS 2

int main(void)
{
    char line[LINELEN + EXTRACHARS];
    printf("Enter a command to run: ");
    fgets(line, LINELEN+EXTRACHARS, stdin);
    system(line);
    return EXIT_SUCCESS;
}
