#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include "account.h"
#include "bool.h"
#ifndef LIST_H
struct list
{
        struct account **array;
        size_t num_accounts;
        size_t max_accounts;
};
#define LIST_H
#define MIN_LIST_SIZE 10
#define DOUBLE(X) ((X) * (X))

/* what operations do we need to be able to do with a list? */
/* initialize  and create */

BOOLEAN list_init(struct list *);
/* add */
BOOLEAN list_add(struct list *, const struct account *);
/* remove */
BOOLEAN list_remove(struct list *, const char[]);
/* find an element */

/* delete or free */
void list_free(struct list *);

#endif
