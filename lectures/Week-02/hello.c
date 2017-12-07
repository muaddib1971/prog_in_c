#include <stdio.h>
#include <stdlib.h>
#define MESSAGE "Hello World\n"

#if 0
void _start()
{
        /* does some initialization of the system */
        int result = main();
        exit (result);
}
#endif 

int main(void)
{
    /* outputs the message defined at the top of this program */
    printf(MESSAGE);
    return EXIT_SUCCESS;
    /* 
        exit(EXIT_SUCCESS);
    */
}

/* vms defined EXIT_FAILURE to be 0 */
