#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned int random(unsigned int);

int main(void)
{
        /* signed - highest bit indicates sign */
        /* unsigned get back that bit which means we have twic as many
         * positive values 
         */
        unsigned num=0;
        /* seed the random number generator */
        srand(time(NULL));
        num = random(10);
        printf("the random number is %d\n", num);
        return EXIT_SUCCESS;
}

unsigned int random(unsigned int max)
{
        unsigned num=RAND_MAX;
        num = rand();
        if(num < 10)
                return num;
        printf("random guess: %d\n", num);
        return random(max);
}
