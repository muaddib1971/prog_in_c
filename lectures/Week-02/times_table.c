#include <stdio.h>
#include <stdlib.h>
/* change base to change which times table is displayed */
#define BASE 5
#define DASHES 20
int main(void)
{
    unsigned count, current;
    printf("The 5 times table\n");
    /* note that this for loop ends at the first ';' */
    for(count=0; count < DASHES; count++) putchar('-'); 
    putchar('\n');
    /* we are doing two things in the initialisation and step 
     * sections of the for loop - the comman operator allows us to do this.
     * We are calculating the times tables using addition based on the 
     * value of BASE so it is easy to change from one times table to another
     */
    for(count = 1,current=BASE; count <= 12; ++count, current+=BASE)
    {
        printf("%u times %u is %u\n", count, BASE, current);
    }
    return EXIT_SUCCESS;
}
