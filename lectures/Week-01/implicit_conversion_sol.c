#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    float x;
    int y = 5, z = 10;
    int a;

    /* we need to cast either y or z to float as the arguments to an
     * operation (the operands) will both be promoted to the largest
     * type available. Otherwise we will lose data
     */
    x=y/(float)z;
    printf("%d/%d=%f\n", y,z,x);
    a=(int)x;/* explicit cast provides a hint to other programmers */
    printf("%f\n", (float)a);
    return EXIT_SUCCESS;
}

