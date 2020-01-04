#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum success
{
        FAILURE,
        SUCCESS,
        ENDOFFILE
};

void read_rest_of_line()
{
        int ch;
        while (ch = getchar(), ch != EOF && ch != '\n')
                ;
        clearerr(stdin);
}

enum success getname(char outstr[], int outlen)
{
        if (fgets(outstr, outlen, stdin) == NULL)
        {
                return ENDOFFILE;
        }
        if (outstr[strlen(outstr) - 1] != '\n')
        {
                return FAILURE;
        }
        return SUCCESS;
}

int main(void)
{
        char name[21];
        enum success outcome;
        outcome = getname(name, 21);
        switch (outcome)
        {
                case FAILURE:
                {
                        printf("input was too long.\n");
                }
                break;
                case ENDOFFILE:
                {
                        printf("ctrl-d was pressed.\n");
                }
                break;
                default:
                        puts(name);
        }
        return EXIT_SUCCESS;
}
