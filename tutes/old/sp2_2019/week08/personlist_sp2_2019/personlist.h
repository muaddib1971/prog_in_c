#include "person.h"
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
typedef enum
{
        FALSE,
        TRUE
} BOOLEAN;

struct list_node
{
        struct list_node* next;
        struct person* data;
};

struct person_list
{
        struct list_node* head;
        size_t size;
};

void list_init(struct person_list*);
struct person_list* list_make(void);
/* assuption that the person passed in is allocated on the heap */
BOOLEAN list_add(struct person_list*, struct person*);
BOOLEAN list_del(struct person_list*, const char[], const char[]);
void list_free(struct person_list*);
