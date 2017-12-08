#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void doit(int * i)
{
        *i = 3;
}
int main(void)
{
        char line[] = "1,3,5,7,9";
        char * tok;
        tok = strtok(line, ",");
        while (tok != NULL)
        {
                int i;
                /* process the token */

                tok = strtok(",", NULL);
                doit(&i);
        }
        return EXIT_SUCCESS;
}
