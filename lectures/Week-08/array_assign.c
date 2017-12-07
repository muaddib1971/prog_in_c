#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main(void)
{
    int array[50];
    int * parray;
    const int * pconst;
    int const * data;
    int * const cdata;

    parray = array;
    pconst = array;
    array = parray;
    array=pconst;
    data = pconst;
    array=data;
    cdata=array;
    array=cdata;
    return EXIT_SUCCESS;

}
