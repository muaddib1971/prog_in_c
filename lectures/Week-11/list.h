#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct node
{
    void * data;
    struct node * next;
};

struct list
{
    struct node * head;
    unsigned size;
    int (*cmp)(const void*,const void*);
    void (*data_free)(void*);
};
typedef enum
{
    FALSE, TRUE
} BOOLEAN;
BOOLEAN list_init(struct list * list, int(*cmp)(const void*,const void*), 
    void(*myfree)(void*));
BOOLEAN list_add(struct list * list, void * data);
void list_print(struct list * list, void (*print)(const void*));
void list_free(struct list * list);

