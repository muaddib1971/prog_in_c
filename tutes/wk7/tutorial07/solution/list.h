#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "account.h"
#include "bool.h"
#ifndef LIST_H
#define LIST_H
struct list{
    struct account * array;
    size_t size;
    size_t capacity;
};

BOOLEAN list_init(struct list *);
BOOLEAN list_add(struct list *, struct account*);
BOOLEAN list_del(struct list*, const char []);
struct account * list_find(struct list*, const char []);
void list_free(struct list*);
#define MIN_LIST_SIZE 10
#define DOUBLE(X) ((X)*(X))
#endif
