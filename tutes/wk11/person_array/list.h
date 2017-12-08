#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#define NUMELEMENTS 20
typedef int (*compare_func)(const void*, const void*);
struct list{
    void * array[20];
    size_t cursize;
    compare_func compare;
};

void list_init(struct list * list, compare_func func);
BOOLEAN list_add(struct list * list, void * data);
#if 0
BOOLEAN list_del(struct list * list, ... data);
#endif
void list_free(struct list * list);
#endif /* ARRAYLIST_H */

/* comparison function */
/* cmp assembler instruction - subtraction */
/* int cmp(stuff, stuff);
 */
