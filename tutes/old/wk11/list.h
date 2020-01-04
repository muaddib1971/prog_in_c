#include <assert.h>
#include <stdlib.h>
#include "safemalloc.h"

typedef int (*comparator)(const void*,const void*);
typedef void(*freer)(void*);

struct list_node
{
    void * data;
    struct list_node * next;
};

struct list
{
    struct list_node * head;
    unsigned count;
    comparator cmp;
    freer data_free;
};

typedef void (*printfunc)(void*);
void list_init(struct list * list, comparator, freer);
BOOLEAN list_add(struct list * list,  void * data);
void list_free(struct list * list);
void print_list(struct list * list, printfunc);
