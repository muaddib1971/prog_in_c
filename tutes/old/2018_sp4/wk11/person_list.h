#include "person.h"
#include <stdio.h>
#ifndef PERSON_LIST_H
#define PERSON_LIST_H

struct list_node
{
        void* data;
        struct list_node* next;
        struct list_node* prev;
};

struct list
{
        struct list_node* head;
        struct list_node* tail;
        int (*cmp)(void*, void*);
        int (*del_cmp)(void*, void*);
        void (*data_free)(void*);
        int num_persons;
};

void list_init(struct list*, int (*)(void*, void*), int (*)(void*, void*),
               void (*)(void*));
BOOLEAN list_add(struct list*, void*);
BOOLEAN list_delete(struct list*, void*);
void list_print(struct list*, void (*)(void*));
void list_free(struct list*);
#endif /* PERSON_LIST_H */
