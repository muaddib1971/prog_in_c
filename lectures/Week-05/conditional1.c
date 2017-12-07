#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    /* by default, p is not initialised here and so can create some 
     * rather random errors
     */
    int * p;
    /* remove the #if below to properly initialise p */
    int i=42;
    p=&i;
    /* #if 0 is an effective way to comment out code as we can nest 
     * #ifs whereas we cannot next comments inside each other 
     */
#ifdef DEBUG
    /* we can introduce defined constants into the program using -D from
     * the gcc command line, for example -DDEBUG would define the DEBUG
     * constant.
     */

    /* fprintf - outputs data to a FILE pointer - so we can choose 
     * where output goes
     */
    fprintf(stderr, "the value of p is %p\n", (void*)p);
#endif
    printf("value pointed to by p is %d\n", *p);
    return EXIT_SUCCESS;
}
