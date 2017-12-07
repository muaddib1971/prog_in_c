#include <stdio.h>
#include <stdlib.h>
/* our union defines the different types of things that can be stored.
 * the space made available is the size of the largest component, in this
 * case, a double
 */
union value
{
    int i;
    float f;
    double d;
};

/* this enumeration defines what the current value type held in the 
 * union is 
 */
enum valuetype
{
    INTEGER, FLOAT, DOUBLE
};

/* we place the union and the enumeration into a struct so that
 * we can say for each value what its type is 
 */
struct type
{
    union value v;
    enum valuetype vt;
};

int main(void)
{
    /* we have two "struct type" variables, i and d */
    struct type i, d; 
    /* initialise i to be an integer with value 5 */
    i.v.i=5;
    i.vt=INTEGER;
    /* inialise d to be a double with the value 50.0 */
    d.v.d=50.0;
    d.vt=DOUBLE;

    /* test if i is an integer or a double and display accordingly */
    if(i.vt==INTEGER)
    {
        printf("i's value is %d\n", i.v.i);
    }
    else if(i.vt==DOUBLE)
    {
        printf("i's value is %f\n", i.v.d);
    }
    /* test if d is an integer or a double and display accordingly */
    if(d.vt==INTEGER)
    {
        printf("d's value is %d\n", d.v.i);
    }
    else if(d.vt==DOUBLE)
    {
        printf("d's value is %f\n", d.v.d);
    }
    /* display the integer part of d - this is not valid and whatever we 
     * get could be rubbish but note that it is not illegal.
     */
    printf("%d\n", d.v.i);
    return EXIT_SUCCESS;
}
