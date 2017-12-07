#include <stdio.h>
#include <stdlib.h>
/* The point of this program is to show how data types may vary in 
 * size on different computer systems. Try compiling and running this 
 * program on different systems. Do you get different output? 
 */
int main(void)
{
    printf("%lu\n", sizeof(char));
    printf("%lu\n", sizeof(int));
    printf("%lu\n", sizeof(long));
    printf("%lu\n", sizeof(size_t));
    printf("%lu\n", sizeof(float));
    printf("%lu\n", sizeof(double));

    return EXIT_SUCCESS;
}
