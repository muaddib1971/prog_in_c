#include <stdio.h>
#include <stdlib.h>

int main(void)
{
        /* make space for what is on the right hand side and copy it in */
        char name[] = "fred";
        /* pointer to a string in the binary loaded in */
        char* aname = "barney";

        name[2] = 0;
        printf("%s\n", name);
        printf("%s\n", aname);
        return EXIT_SUCCESS;
}
