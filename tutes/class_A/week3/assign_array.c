#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int array[] = {1, 3, 5, 7, 9};
    int* iter = array;
    array = iter;
}
