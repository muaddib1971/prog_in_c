#include "counterlib.h"

void counter(unsigned * val)
{
    static unsigned count=0;
    /* notice that we don't do anything with the value stored 
     * in val - it may be uninitialised and so garbage
     */
    *val= ++count;
    /* no return statement required */
}
