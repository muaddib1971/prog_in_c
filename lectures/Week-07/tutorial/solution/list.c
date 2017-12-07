#include "list.h"
BOOLEAN list_init(struct list * list)
{
    list->array = (struct account*) 
        malloc(sizeof(struct account) * MIN_LIST_SIZE);
#if 0
        calloc(MIN_LIST_SIZE, sizeof(struct account))
#endif
    if(!list->array){
        perror("failed to allocate memory");
        return FALSE;
    }
    list->size = 0;
    list->capacity = MIN_LIST_SIZE;
    return TRUE;
}

BOOLEAN list_add(struct list * list, struct account account)
{
    int count;
    if(list->size == list->capacity){
        void * test = (struct account*)
            realloc(list->array, DOUBLE(list->size) 
                * sizeof(struct account));
        if(!test){
            perror("failed to reallocate");
            return FALSE;
        }
        list->array = test;
        list->capacity = DOUBLE(list->capacity);
    }
    for(count = 0; count < list->size; ++count){
       if(money_cmp(list->array[count].balance,  account.balance) < 0){
           int back_count;
           for(back_count = list->size; back_count > count; --back_count){
               list->array[back_count] = list->array[back_count - 1];
           }
           list->array[count] = account;
           ++list->size;
           return TRUE;
       }
    }
    /* when do we get here ? */
    list->array[list->size++] = account;
    return TRUE;
}

BOOLEAN list_del(struct list * list, char accno[])
{
    int count;
    if(list->size == 0){
        return FALSE;
    }
    for(count = 0; count < list->size; ++count){
        if(is_owner(&list->array[count], accno)){
            int del_count;
            for(del_count = count; del_count < list->size; ++del_count){
                list->array[del_count] = list->array[del_count + 1];
            }
            --list->size;
            return TRUE;
        }
    }
    return FALSE;
}

void list_free(struct list * list)
{
    /* assert.h */
    realloc(list->array, 0);
    assert(list);
    int i;
    int * pi = &i;
    free(list->array);
}

struct account * list_find(struct list* list, const char accno[])
{
}
