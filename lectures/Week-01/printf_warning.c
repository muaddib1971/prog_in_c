#include <stdio.h>
#include <stdlib.h>

int main(void)
{
        int i = 5;
        /* char * format = "%d\n"; */
        /* what is the cause of the compiler warning here ?
         * how do we fix it?
         *
         * is it reasonable to presume that just because this is a warning that
         * it is not a big issue?
         */
        /* int printf(const char *, ...); */
        printf(i);
        return EXIT_SUCCESS;
}
