#include <stdio.h>
#include <stdlib.h>
#define MAXCOLOR 6
#define RESET 6

int main(void)
{
        const char* color_strings[7] = {
                /* red */ "\x1b[31m",    /* green */ "\x1b[32m",
                /* yellow */ "\x1b[33m",
                /* blue */ "\x1b[34m",   /* magenta */ "\x1b[35m",
                /* cyan */ "\x1b[36m",   /* reset */ "\x1b[0m",
        };
        int count;
        for (count = 0; count < MAXCOLOR; ++count)
        {
                printf("%s%s%s\n", color_strings[count], "Paul",
                       color_strings[RESET]);
        }
        return EXIT_SUCCESS;
}
