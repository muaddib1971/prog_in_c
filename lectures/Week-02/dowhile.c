#include <stdio.h>
#include <stdlib.h>
/* This program shows the use of a do-while loop. 
 * Notice that the loop will always run at least once even 
 * if the test can never be true. Test this by setting the test to be
 * 1==0
 */
int main(void)
{
    int a=0;
    do 
            printf ("%d\n", a) ;
    while (++a<50); 
#if 0
    while (1==0);
#endif
    return EXIT_SUCCESS;
}
