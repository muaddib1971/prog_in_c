#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
        /* ./args 1 2 3 4 */
        int count;
        for (count = 0; count < argc; ++count)
        {
                printf("%s\n", argv[count]);
        }
        return EXIT_SUCCESS;
}
