#include "list.h"
void list_init(struct list * list, compare_func cmp)
{
    list->cursize = 0;
    list->compare = cmp;
}

BOOLEAN list_add(struct list * list, void * data)
{
    int index;
    if(list->cursize == NUMELEMENTS){
        fprintf(stderr, "Error: list is full.\n");
        return FALSE;
    }
    if(list->cursize == 0){
        list->array[0] = data;
        ++ list->cursize;
        return TRUE;
    }
    for(index = 0; index < list->cursize; ++index){
        if(list->compare(list->array[index], data) > 0){
            int backcount;
            for(backcount = list->cursize; backcount > index; 
                --backcount){
                list->array[backcount] = list->array[backcount-1];
            }
            list->array[index] = data;
            ++ list->cursize;
            return TRUE;
        }
    }
    list->array[list->cursize ++] = data;
    return TRUE;
}

