#include <stdlib.h>

void array_walk(void * array, size_t elt_size, size_t num_elts, 
    void (*action)(void*));
