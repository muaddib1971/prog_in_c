#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void)
{
        srand(time(NULL));
        printf("%ld\n", time(NULL));
        return EXIT_SUCCESS;
}
