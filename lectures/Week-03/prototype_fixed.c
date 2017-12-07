#include <stdio.h>
#include <stdlib.h>
/* we fixed the problem by adding a function prototype 
 * (function declaration) before the first call to the function. 
 * The problem is that when the C compiler sees a function that has 
 * not been declared it assumes it returns an int and takes no 
 * arguments. However when it came to the function implementation 
 * (the function definition) it found a function that returned 
 * void. This is not the type that was presumed and so there is a 
 * compiler error
 */
void doit(void);
void doit2(int);

int main(void)
{
    doit();
    return EXIT_SUCCESS;
}

void doit(void)
{
   printf("done!\n");
}

void doit2(int i)
{
        printf("%d\n", i);
}
