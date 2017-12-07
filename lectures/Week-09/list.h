#include <assert.h>
#include <stdlib.h>
#include "safemalloc.h"
#define NAMELEN 20
struct person 
{
    char fname[NAMELEN+1];
    char lname[NAMELEN+1];
    unsigned age;
};

struct list_node
{
    struct person * data;
    struct list_node * next;
};

struct list
{
    struct list_node * head;
    unsigned count;
};

void list_init(struct list * list);
BOOLEAN list_add(struct list * list, struct person * data);
void list_free(struct list * list);
int person_cmp(const struct person*, const struct person*);
