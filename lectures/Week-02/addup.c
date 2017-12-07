#include <stdio.h>
#include <stdlib.h>

/* prototype for a function - note that we don't need to specify the 
 * variable names. This is what we call the function declaration.
 */
int add(int,int);

int main(void)
{
    /* note the function call to add() - add() will be called and the 
     * return value from add() will replace the call to add - that is 
     * the result of calling add() is passed into the printf function
     */
    printf("%d\n", add(3,4));
    return EXIT_SUCCESS;
}
/* The implementation of the add function. This is also sometimes called
 * the function definition. That is, the prototype is the declaration
 * and the implementation is the definition 
 */
int add(int first, int second)
{
    return first + second;
}
