#include "walk.h"
void array_walk(void * array, size_t elt_size, size_t num_elts, 
    void (*action)(void*))
{
    void * current = array;
    long cur_ind;
    for( cur_ind = 0; cur_ind < num_elts; ++cur_ind ){
        action(current);
        current = ((char*)current) + elt_size;
    }
}

/* int array[10];
 * array[0] -> array[1] == sizeof(int)
 *
 * int * arrptr = array; 
 * ++array;
 */
