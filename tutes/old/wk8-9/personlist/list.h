#include "bool.h"
#include "person.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#ifndef LIST_H
#define LIST_H
struct node{
    struct person * data;
    struct node * next;
};

struct list{
    struct node * head;
    int num_nodes;
};

int get_next_id(void);
BOOLEAN list_init(struct list *);
BOOLEAN list_add( struct list *, struct person *);
BOOLEAN list_remove( struct list *, int);
void list_free( struct list*); 
#endif
