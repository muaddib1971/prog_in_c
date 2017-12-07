#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    float x;
    int y = 5, z = 10;
    int a;

    x=((float)y)/z;
    printf("%d/%d=%f\n", y,z,x);
    a=x; /* !!!!! */
    printf("%f\n", (float)a);
    
    return EXIT_SUCCESS;
}

