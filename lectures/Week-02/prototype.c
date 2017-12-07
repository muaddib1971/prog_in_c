#include <stdio.h>
#include <stdlib.h>

void doit(void);
void doit2(int);
/* there is a problem with this program. If you try to compile it you 
 * will get the following compiler warnings: 
 *
 * prototype.c: In function ‘main’:
 * prototype.c:5: warning: implicit declaration of function ‘doit’
 * prototype.c: At top level:
 * prototype.c:9: warning: conflicting types for ‘doit’
 * prototype.c:5: note: previous implicit declaration of ‘doit’ was here
 *
 * think about the problem for a moment and think how you might fix it.
 *
 * if you run out of ideas, have a look at prototype_fixed.c in the 
 * same directory
 */

int main(void)
{
    int i;
    doit();
    doit2(i);
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
