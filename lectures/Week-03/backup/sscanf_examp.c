#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LEN 80
#define EXTRA_SPACES 2
int main(void)
{
    char line[LINE_LEN + EXTRA_SPACES];
    int day, month,year;

    /* get user input */
    printf("Please enter your age: ");
    fgets(line, LINE_LEN+EXTRA_SPACES, stdin);
    /* check for buffer overflow */
    if(line[strlen(line)-1]!='\n')
    {
        printf("Error: buffer overflow\n\n");
        return EXIT_FAILURE;
    }
    /* remove newline */
    line[strlen(line)-1]=0;

    /* retrieve number */
    sscanf(line, "%d/%d/%d", &day, &month, &year);
    printf("The day is %d, month is %d, year is %d\n", 
        day, month, year);
    return EXIT_SUCCESS;
}
