#include "list.h"
BOOLEAN list_init(struct list* list)
{
        list->array =
            (struct account**)malloc(sizeof(struct account*) * MIN_LIST_SIZE);
        if (list->array == NULL)
        {
                perror("failed to allocate");
                fprintf(stderr, "failed to allocate: %s\n", strerror(errno));
                return FALSE;
        }
        list->num_accounts = 0;
        list->max_accounts = MIN_LIST_SIZE;
        return TRUE;
}

BOOLEAN list_add(struct list* list, const struct account* account)
{
        struct account* new;
        if (list->num_accounts == list->max_accounts)
        {
                struct account** temp;
                temp = realloc(list->array, DOUBLE(list->max_accounts));
                if (temp != NULL)
                {
                        list->array = temp;
                        list->max_accounts = DOUBLE(list->max_accounts);
                }
                else
                {
                        perror("realloc failed");
                        return FALSE;
                }
        }
        new = (struct account*)malloc(sizeof(struct account));
        if (!new)
        {
                perror("allocation failed for account");
                return FALSE;
        }
        *new = *account;
        list->array[list->num_accounts++] = new;
        return TRUE;
}

BOOLEAN list_del(struct list* list, char accno[])
{
        int count;
        for (count = 0; count < list->num_accounts; ++count)
        {
                if (strcmp(list->array[count]->accno, accno) == 0)
                {
                        struct account* del = list->array[count];
                        for (; count < list->num_accounts - 1; ++count)
                        {
                                list->array[count] = list->array[count + 1];
                        }
                        free(del);
                        --list->num_accounts;
                        return TRUE;
                }
        }
        return FALSE;
}

void list_free(struct list* list)
{
        int count;
        for (count = 0; count < list->num_accounts; ++count)
        {
                free(list->array[count]);
        }
        free(list->array);
        free(list);
}
