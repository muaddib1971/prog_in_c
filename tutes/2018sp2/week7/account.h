#include <string.h>
#include <stdio.h>
#include "bool.h"
#include "helpers.h"
#include <limits.h>
#ifndef ACCOUNT_H
#define ACCOUNT_H
#define NAMELEN 20
#define ACCNOLEN 10
#define MAXCENTS 99
#define DOLLCENTS 100
struct money
{
        int dollars;
        int cents;
};

struct account
{
        char custname[NAMELEN + 1];
        char accno[ACCNOLEN + 1];
        struct money balance;
};

int bal_cmp(const struct account *, const struct account *);

BOOLEAN read_account(struct account *);
#endif
