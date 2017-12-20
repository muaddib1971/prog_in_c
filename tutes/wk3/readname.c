#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAMELEN 20
#define EXTRACHARS 2

int read_rest_of_line(void)
{
        int ch;
        while (ch = getc(stdin), ch != '\n' && ch != EOF)
                ; /* do nothing */
        clearerr(stdin);
}

int main(void)
{
        char name[NAMELEN +
                  EXTRACHARS]; /* pointer that needs to point to some memory */
        char hello[] = { 'h', 'e', 'l', 'l', 'o' };
        printf("%s\n", hello);
        printf("please enter your name: ");
        fgets(name, NAMELEN + EXTRACHARS, stdin);
        if (name[strlen(name) - 1] != '\n')
        {
                printf("buffer overflow!!!!\n");
                return EXIT_FAILURE;
        }
        printf("%s\n", name);
        return EXIT_SUCCESS;
}
