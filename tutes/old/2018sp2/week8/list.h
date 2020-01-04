#include <assert.h>
#include "person.h"

struct node {
    Person *data;
    struct node *next;
};

struct list {
    struct node *head;
    int size;
};

void list_init(struct list *);

/* assumption - data is malloced separately */
BOOLEAN list_add(struct list *, Person *data);

BOOLEAN list_del(struct list *, const char[], const char[]);

list_free(struct list *)
