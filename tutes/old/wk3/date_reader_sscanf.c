#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINELEN 80
#define EXTRACHARS 2

void read_rest_of_line(void)
{
    int ch;
    while(ch = getc(stdin), ch != '\n' && ch != EOF)
        ;
    clearerr(stdin);
}

int main(void)
{
    char line[LINELEN + EXTRACHARS];
    int day, month, year;

    printf("please enter a date as dd/mm/yy: ");
    fgets(line, LINELEN + EXTRACHARS, stdin);
    if(line[strlen(line)-1] != '\n')
    {
        printf("line was too long\n");
        read_rest_of_line();
        return EXIT_FAILURE;
    }
    /* validate it is a valid date */
    sscanf(line, "%d/%d/%d", &day, &month, &year);
    printf("Day: %d, Month: %d, year %d\n", day, month, year);
    return EXIT_SUCCESS;
}
