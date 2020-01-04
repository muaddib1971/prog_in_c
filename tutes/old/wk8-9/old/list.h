#include "person.h"
#include <assert.h>
#ifndef LIST_H
#define LIST_H

typedef enum {FALSE, TRUE} BOOLEAN;

struct node
{
        struct person * data;
        struct node * next;
};

struct list
{
        struct node * head;
        int num_nodes;
};

void list_init(struct list *);
BOOLEAN list_add(struct list *, struct person *);
BOOLEAN list_delete(struct list*, const char[], const char[]);
void list_print(struct list * list);
void list_free(struct list*);

#endif /* LIST_H */
