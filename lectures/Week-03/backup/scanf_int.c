#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int anint;
    while(scanf("%d", &anint)!=1)
    {
        printf("%d\n", anint);
    }
    return EXIT_SUCCESS;
}
