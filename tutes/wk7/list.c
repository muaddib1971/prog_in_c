#include "list.h"
BOOLEAN list_init(struct list * list)
{
        memset(list, 0, sizeof(struct list));
        list->accounts =(struct account*) 
                malloc(sizeof(account) * MIN_LIST_SIZE);
        if(list->accounts == NULL)
        {
                perror("failed to allocate memory");
                return FALSE;
        }
        list->accounts_allocated = MIN_LIST_SIZE;
        return TRUE;
}

int bal_cmp(struct money bal_a, struct money bal_b)
{
        if(bal_a.dollars > bal_b.dollars)
        {
                return bal_a.dollars - bal_b.dollars;
        }
        else
        {
                return bal_a.cents - bal_b.cents;
        }
}

BOOLEAN list_add(struct list * list, struct account account)
{
        int count;
        if(list->total_accounts == 0)
        {
                list->accounts[list->total_accounts++]=account;
                return TRUE;
        }
        if(list->total_accounts == list->accounts_allocated)
        {
                /* resize the array !! */
                struct account * temp = realloc(list->accounts, 
                                DOUBLE(list->accounts_allocated) 
                                * sizeof(account));
                if(!temp)
                {
                        perror("failed to reallocate memory");
                        return FALSE;
                }
                list->accounts = temp;
        }
        for(count = 0; count < list->total_accounts; ++count)
        {
                if(bal_cmp(list->accounts[count].balance, 
                                        account.balance) < 0 ) 
                {
                        break;
                }
        }
        memmove( &list->accounts[count+1], &list->accounts[count], 
                        (list->total_acccounts - count) 
                        * sizeof(struct account));
        list->accounts[count] = account;
        return TRUE;
}

BOOLEAN list_del(struct list * list, char accno[])
{
        int count;
        assert(list);
        assert(accno);
        if(list->total_accounts == 0)
        {
                return FALSE;
        }
        for(count = 0; count < list->total_accounts; ++count)
        {
                if(strcmp(list->accounts[count].accno, accno) == 0)
                {
                        break;
                }
        }
        if(count == list->total_accounts)
        {
                return FALSE;
        }
        memmove(list->accounts[count], list->accounts[count+1], 
                        sizeof(struct account) * (list->total_accounts - 
                                count -1));
        -- list->total_accounts;
        return TRUE;
}

void list_free(struct list * list)
{
        free(list->accounts);
        memset(list, 0 , sizeof(struct list));
}
