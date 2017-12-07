#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LEN 80
#define EXTRA_SPACES 2
int main(void)
{
    char line[LINE_LEN + EXTRA_SPACES];
    int input_num;

    /* get user input */
    printf("Please enter your age: ");
    fgets(line, LINE_LEN+EXTRA_SPACES, stdin);
    /* check for buffer overflow */
    if(line[strlen(line)-1]!='\n')
    {
        printf("Error: buffer overflow\n\n");
        /* call read_rest_of_line() */
        return EXIT_FAILURE;
    }
    /* remove newline */
    line[strlen(line)-1]='\0';

    /* retrieve number */
    input_num = atoi(line);
    printf("you are %d years old.\n\n", input_num);
    return EXIT_SUCCESS;
}

