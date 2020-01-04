#include "account_list.h"

int main(void)
{
        struct account account;
        struct list list;
        list_init(&list);
        while(read_account(&account))
        {
                list_add(&list, account);
        }
        return EXIT_SUCCESS;
}
