#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
        int count;
        for(count = 0; count < argc; ++count)
        {
                printf("%s\n", argv[count]);
        }
        return EXIT_SUCCESS;
}
