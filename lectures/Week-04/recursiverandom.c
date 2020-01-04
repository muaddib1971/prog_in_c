#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MYMAXRAND 10

unsigned int genrandom(unsigned int);

int main(void)
{
        /* signed - highest bit indicates sign */
        /* unsigned get back that bit which means we have twic as many
         * positive values
         */
        unsigned num = 0;
        /* seed the genrandom number generator */
        srand(time(NULL));
        num = genrandom(MYMAXRAND);
        printf("the genrandom number is %d\n", num);
        return EXIT_SUCCESS;
}

unsigned int genrandom(unsigned int max)
{
        unsigned num = RAND_MAX;
        num = rand();
        if (num < MYMAXRAND)
                return num;
        printf("genrandom guess: %d\n", num);
        return genrandom(max);
}
