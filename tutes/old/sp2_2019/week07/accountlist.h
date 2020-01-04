#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define NAMELEN 40
#define ACCNOLEN 10
#define MINSPOTS 16
#define MULTIPLIER 2

typedef enum
{
        FALSE,
        TRUE
} BOOLEAN;

struct money
{
        int dollars;
        char cents;
};

struct account
{
        char custname[NAMELEN + 1];
        char accno[ACCNOLEN + 1];
        struct money balance;
};

struct account_list
{
        struct account* theaccounts;
        int accounts_allocated;
        int accounts_used;
        BOOLEAN newed;
};

struct account_list* accountlist_new(void);
void accountlist_init(struct account_list*);
/* account is a pointer to an account allocated elsewhere on the stack */
BOOLEAN accountlist_add(struct account_list*, struct account*);
BOOLEAN accountlist_remove(struct account_list*, const char[]);
struct account* accountlist_get(struct account_list*, const char[]);
void accountlist_destroy(struct account_list*);
