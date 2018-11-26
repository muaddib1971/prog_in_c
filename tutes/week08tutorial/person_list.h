#include "person.h"
#include <stdio.h>
#ifndef PERSON_LIST_H
#define PERSON_LIST_H

struct list_node
{
        struct person* data;
        struct list_node* next;
        struct list_node* prev;
};

struct list
{
        struct list_node* head;
        struct list_node* tail;
        int num_persons;
};

void list_init(struct list*);
BOOLEAN list_add(struct list*, struct person*);
BOOLEAN list_delete(struct list*, const char[], const char[]);
void list_print(struct list*);
void list_free(struct list*);
#endif /* PERSON_LIST_H */
