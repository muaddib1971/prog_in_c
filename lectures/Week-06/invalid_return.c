#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* bad_return(void) {
    int array[] = {1, 3, 5, 7, 9, 11};
    return &array[5];
    ;
}

int main(void) {

    int* p = bad_return();
    printf("%d\n", *p);
    return EXIT_SUCCESS;
}
