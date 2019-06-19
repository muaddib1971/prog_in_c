#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
        FALSE,
        TRUE
} BOOLEAN;
#define EXTRACHARS 2
#define NAMELEN 40

void clear_buffer()
{
        int ch;
        while (ch = getc(stdin), ch != '\n' && ch != EOF)
                ;
        clearerr(stdin);
}

BOOLEAN getname(char name[], int maxlen)
{
        if (fgets(name, maxlen + EXTRACHARS, stdin) == NULL)
        {
                return FALSE;
        }
        if (name[strlen(name) - 1] != '\n')
        {
                fprintf(stderr, "Error: buffer overflow.\n");
                clear_buffer();
                return getname(name, maxlen);
        }
        name[strlen(name) - 1] = 0;
        return TRUE;
}

int main()
{
        char name[NAMELEN + EXTRACHARS];
        printf("Please enter your name: ");
        if (getname(name, NAMELEN))
        {
                printf("thanks, %s\n", name);
                return EXIT_SUCCESS;
        }
        return EXIT_FAILURE;
}
