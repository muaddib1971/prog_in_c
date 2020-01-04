#include "list.h"
BOOLEAN list_init(struct list *list)
{
        list->accounts =
            (struct account *)malloc(sizeof(struct account) * MIN_LIST_SIZE);
        if (!list->accounts)
        {
                perror("malloc failed");
                return FALSE;
        }
        list->num_accounts = 0;
        list->total_accounts = MIN_LIST_SIZE;
        return TRUE;
}

BOOLEAN list_add(struct list *list, struct account account)
{
        int count;
        int backcount;
        if (list->num_accounts == list->total_accounts)
        {
                struct account *temp =
                    realloc(list->accounts, DOUBLE(list->total_accounts) *
                                                sizeof(struct account));
                if (temp)
                {
                        list->accounts = temp;
                        list->total_accounts = DOUBLE(list->total_accounts);
                }
                else
                {
                        perror("realloc failed");
                        return FALSE;
                }
        }
        /* list->accounts[list->num_accounts++] = account; */
        for (count = 0; count < list->num_accounts &&
                            bal_cmp(&list->accounts[count], &account) < 0;
             ++count)
        {
        }
        for (backcount = list->num_accounts; backcount > count; --backcount)
        {
                list->accounts[backcount] = list->accounts[backcount - 1];
        }
        list->accounts[count] = account;
        list->num_accounts++;
        return TRUE;
}

BOOLEAN list_del(struct list *list, char accno[])
{
        return FALSE;
}

void list_free(struct list *list)
{
        free(list->accounts);
}
