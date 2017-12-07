#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* functions to fill our arrays */
void fill_int_array(int*, size_t);
void fill_double_array(double *, size_t);

/* functions that perform the arithmetic operations on each type */
void add_int(const void*,const void*,void*);
void sub_int(const void*,const void*, void*);
void mult_int(const void*,const void*, void*);
void div_int(const void*,const void*, void*);

void add_double(const void*,const void*,void*);
void sub_double(const void*,const void*,void*);
void mult_double(const void*,const void*,void*);
void div_double(const void*,const void*,void*);

/* for_each function - the powerhouse of the program */
void for_each(void * nums, void * val, size_t elt_count, size_t elt_size,
    void(*)(const void*, const void*, void*));
/* functions that handle printing each item */
void print_int(const void*);
void print_double(const void*);

/* generic printer function */
void print_array(void* nums, size_t , size_t, void(*printfunc)(const void*));
