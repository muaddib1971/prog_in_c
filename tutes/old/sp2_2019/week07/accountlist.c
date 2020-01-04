#include "accountlist.h"

struct account_list* accountlist_new(void)
{
        struct account_list* new =
            (struct account_list*)malloc(sizeof(struct account_list));
        if (!new)
        {
                return NULL;
        }
        accountlist_init(new);
        new->newed = TRUE;
        return new;
}

void accountlist_init(struct account_list* thelist)
{
        memset(thelist, 0, sizeof(struct account_list));
        /* although you don't have to use memset and this is an alternative
         * although it's more work */
        thelist->theaccounts = NULL;
        thelist->accounts_used = 0;
        thelist->accounts_allocated = 0;
        thelist->newed = FALSE;
}

BOOLEAN accountlist_add(struct account_list* thelist,
                        struct account* newaccount)
{
        if (thelist->accounts_allocated == 0)
        {
                thelist->theaccounts =
                    (struct account*)malloc(sizeof(struct account) * MINSPOTS);
                if (!thelist->theaccounts)
                {
                        return FALSE;
                }
                thelist->accounts_allocated = MINSPOTS;
        }
        if (thelist->accounts_used == thelist->accounts_allocated)
        {
                int desired_accounts;
                void* test;
                if (((long)thelist->accounts_allocated) * MULTIPLIER > INT_MAX)
                {
                        return FALSE;
                }
                desired_accounts = thelist->accounts_allocated * MULTIPLIER;
                test = realloc(thelist->theaccounts, desired_accounts);
                if (!test)
                {
                        return FALSE;
                }
                thelist->theaccounts = (struct account*)test;
                thelist->accounts_allocated = desired_accounts;
        }
        thelist->theaccounts[thelist->accounts_used++] = *newaccount;
        return TRUE;
}

/**
 * convenience function to compare the account number of an account to an
 * account number passed in - just calls strcmp to do the comparison.
 **/
static int acc_cmp(struct account* curaccount, const char accno[])
{
        return strcmp(curaccount->accno, accno);
}

BOOLEAN accountlist_remove(struct account_list* acclist, const char accno[])
{
        int acc_count;
        /* if the list is empty there is nothing to delete */
        if (acclist->accounts_used == 0)
        {
                return FALSE;
        }
        /* search for the account we want to delete */
        for (acc_count = 0; acc_count < acclist->accounts_used; ++acc_count)
        {
                if (acc_cmp(&acclist->theaccounts[acc_count], accno) == 0)
                {
                        break;
                }
        }
        /* if we have checked all the accounts and not found a match, we
         * have failed in our search
         */
        if (acc_count == acclist->accounts_used)
        {
                return FALSE;
        }
        /* we need to move all accounts after this one up by one */
        for (; acc_count < acclist->accounts_used - 1; ++acc_count)
        {
                acclist->theaccounts[acc_count] =
                    acclist->theaccounts[acc_count + 1];
        }
        --acclist->accounts_used;
        /* deletion is successful */
        return TRUE;
}

struct account* accountlist_get(struct account_list* thelist,
                                const char accno[])
{
        int acc_count;
        /* if the list is empty there is nothing to delete */
        if (thelist->accounts_used == 0)
        {
                return NULL;
        }
        /* search for the account we want to delete */
        for (acc_count = 0; acc_count < thelist->accounts_used; ++acc_count)
        {
                if (acc_cmp(&thelist->theaccounts[acc_count], accno) == 0)
                {
                        break;
                }
        }
        /* test if we got to the end of the list */
        if (acc_count == thelist->accounts_used)
        {
                return NULL;
        }
        /* remember that returning an address here is fine as it's an address
         * that is inside the data passed in as a parameter. Also, as it's part
         * of a block of memory allocated with malloc, it's on the heap and not
         * on the stack
         */
        return &thelist->theaccounts[acc_count];
}

void accountlist_destroy(struct account_list* thelist)
{
        free(thelist->theaccounts);
        if (thelist->newed)
        {
                free(thelist);
        }
}

void accountlist_print(const struct account_list* thelist)
{
        int count;
        for (count = 0; count < thelist->accounts_used; ++count)
        {
                const struct account* current = &thelist->theaccounts[count];
                printf("Name: %s, Account Number: %s, Balance: %d.%d\n",
                       current->custname, current->accno,
                       current->balance.dollars, current->balance.cents);
        }
}

#define NUM_ACCOUNTS 4

/* allocating the list on the heap */
#if !0
int main(void)
{
        struct account dummy_accounts[] = { { "Fred", "1001", { 100, 54 } },
                                            { "Wilma", "1002", { 200, 77 } },
                                            { "Barney", "1003", { 300, 44 } },
                                            { "Betty", "1004", { 400, 55 } } };
        int acc_count;
        struct account_list* thelist = accountlist_new();
        for (acc_count = 0; acc_count < NUM_ACCOUNTS; ++acc_count)
        {
                accountlist_add(thelist, &dummy_accounts[acc_count]);
        }
        accountlist_print(thelist);
        printf("changing Wilma's balance\n");
        {
                struct account* wilma = accountlist_get(thelist, "1002");
                wilma->balance.dollars = 300;
                accountlist_print(thelist);
        }
        printf("Deleting Barney\n");
        accountlist_remove(thelist, "1003");
        accountlist_print(thelist);
        accountlist_destroy(thelist);
        return EXIT_SUCCESS;
}
#endif
#if 0
int main(void)
{
        struct account dummy_accounts[] = { { "Fred", "1001", { 100, 54 } },
                                            { "Wilma", "1002", { 200, 77 } },
                                            { "Barney", "1003", { 300, 44 } },
                                            { "Betty", "1004", { 400, 55 } } };
        int acc_count;
        struct account_list thelist;
        accountlist_init(&thelist);
        for (acc_count = 0; acc_count < NUM_ACCOUNTS; ++acc_count)
        {
                accountlist_add(&thelist, &dummy_accounts[acc_count]);
        }
        accountlist_print(&thelist);
        printf("changing Wilma's balance\n");
        {
                struct account* wilma = accountlist_get(&thelist, "1002");
                wilma->balance.dollars = 300;
                accountlist_print(&thelist);
        }
        printf("Deleting Barney\n");
        accountlist_remove(&thelist, "1003");
        accountlist_print(&thelist);
        accountlist_destroy(&thelist);
        return EXIT_SUCCESS;
}
#endif
