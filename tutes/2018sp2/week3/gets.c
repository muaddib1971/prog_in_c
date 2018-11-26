#include <stdio.h>
#include <stdlib.h>

/**
 * This is a demonstration of the gets() function. The gets function allows
 * the user of your program to write unlimited bytes to a limited space and
 * thus is dangerous. This function has been used in the past to break the
 * security of a computer system.
 **/
int main()
{
        char s[5];
        gets(s);
        return EXIT_SUCCESS;
}
