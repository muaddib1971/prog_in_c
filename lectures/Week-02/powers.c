#include <stdio.h>
#include <stdlib.h>

int main(void)
{
        int i = 1, power = 0;
        int count;
        for (count = 0; count < 14; ++count)
        {
                printf("2 to the power of %d is: %d\n",
                        power, i);
                ++power;
                i*=2;
        }
        return EXIT_SUCCESS;
}
