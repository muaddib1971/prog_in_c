#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "account.h"
#include "bool.h"
#ifndef LIST_H
#define LIST_H
#define MIN_LIST_SIZE 10
struct list
{
        struct account* accounts;
        int num_accounts;
        int total_accounts;
};
#define DOUBLE(X) ((X) + (X))
#endif
