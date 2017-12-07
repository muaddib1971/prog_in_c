#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LEN 80
#define EXTRA_SPACES 2

/* 1,3,5,7,8,3,7,5,3,2,7,1,2,3,7,6,0,77,99 */
int main(void)
{
    char line[LINE_LEN + EXTRA_SPACES];
    int day, month,year;

    /* get user input */
    printf("Please enter your date of birth: ");
    fgets(line, LINE_LEN+EXTRA_SPACES, stdin);
    /* check for buffer overflow */
    if(line[strlen(line)-1]!='\n')
    {
        printf("Error: buffer overflow\n\n");
        return EXIT_FAILURE;
    }
    /* remove newline */
    line[strlen(line)-1]=0;
    /* perform input validation */
    /* retrieve number */
    sscanf(line, "%d/%d/%d", &day, &month, &year);
    printf("The day is %d, month is %d, year is %d\n", 
        day, month, year);
    return EXIT_SUCCESS;
}
