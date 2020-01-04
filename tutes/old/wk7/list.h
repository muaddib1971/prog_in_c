#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "account.h"
#include "bool.h"
#ifndef LIST_H /* include guard */
#define LIST_H 
struct list
{
        struct account * accounts;
        int total_accounts;
        int accounts_allocated;
};

#define MIN_LIST_SIZE 10
#define DOUBLE(X) (2 * (X))
#endif
