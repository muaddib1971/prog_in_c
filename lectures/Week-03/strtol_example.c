#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LEN 80
#define EXTRA_SPACES 2
int main(void)
{
    char line[LINE_LEN + EXTRA_SPACES];
    char * end;
    int input_num;

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

    /* ascii '0' != 0 */
    /* retrieve number */
    input_num = strtol(line, &end, 10);
    if(*end != '\0')
    {
        printf("Error: data entered was not numeric.\n\n");
        return EXIT_FAILURE;
    }
    printf("you are %d years old.\n\n", input_num);
    return EXIT_SUCCESS;
}
