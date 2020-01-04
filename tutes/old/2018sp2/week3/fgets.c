#include <stdio.h>
#include <stdlib.h>

int main(void)
{
        char line[80 + 2];

        fgets(line, 80 + 2, stdin);
        /* line = "....\n\0" */
        printf("%s\n", line);
        return EXIT_SUCCESS;
}
