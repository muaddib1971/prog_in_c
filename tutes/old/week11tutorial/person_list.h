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
        int (*insert_cmp)(void*, void*);
        void (*element_free)(void*);
        void (*element_print)(void*);
        int num_elements;
};

void list_init(struct list*, int (*cmp)(void*, void*), void (*eltfree)(void*),
               void (*)(void*));
BOOLEAN list_add(struct list*, void*);
#if 0
BOOLEAN list_delete(struct list*, const char[], const char[]);
#endif
void list_print(struct list*);
void list_free(struct list*);
#endif /* PERSON_LIST_H */
