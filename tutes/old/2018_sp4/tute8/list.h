#include "person.h"
#include <string.h>

#ifndef LIST_H
#define LIST_H
struct list_node
{
        struct person* data;
        struct list_node* next;
};

struct list
{
        struct list_node* head;
        long list_size;
};

struct list* list_make(void);
void list_init(struct list*);
BOOLEAN list_add(struct list*, struct person*);
BOOLEAN list_remove(struct list*, const char lname[]);
void list_print(const struct list*, void (*)(const struct person*));
void list_free(struct list*);
#endif
