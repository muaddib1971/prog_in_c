#include <stdio.h>
#include <stdlib.h>
/* Here we have a program where we demonstrate the use of while loops 
 * with both pre-increments/decrements (++i/--i) where the value tested is 
 * after the increment/decrement and post-increment/decrement(i++/i--) 
 * where the value tested is the values prior to the increment/decrement.
 * Please note that if for your code it doesn't matter whether you do 
 * pre or post increments, use the preincrement as it uses less computer 
 * resources
 */
int main(void)
{
    int j=-50, i=50;
    while(j++)
    {
        printf("%d\n", j);
    }
    while(--i)
    {
        printf("%d\n", i);
    }
    return EXIT_SUCCESS;
}
