#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i;
    for (i=0; i<5; ++i)
    {
        int i=3;
        if(i==4)
            printf("%d\n", i);
    }
    return EXIT_SUCCESS;
}
