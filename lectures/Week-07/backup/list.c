#include "list.h"
#include <string.h>

/**************************************************************************
 * initialise the list to a safe state where all values start from known
 * values. 
 *************************************************************************/
void list_init(struct list * list)
{
    assert(list);
    list->head=NULL;
    list->count=0;
}

/**************************************************************************
 * list_add() - implements the algorithm to insert into a list in sorted 
 * order. If you think back to the sorting algorithms covered earlier in 
 * this course this is an insertion sort.
 *************************************************************************/
BOOLEAN list_add(struct list * list, struct person * data)
{
    struct list_node * current, *prev;
    struct list_node * new;
    assert(list);
    current = list->head;
    new = safemalloc(sizeof(struct list_node));
    new->next=NULL;
    new->data=data;
    if(list->head == NULL)
    {
        list->head = new;
        ++list->count;
        return TRUE;
    }
    while(current != NULL && person_cmp(current->data, data) < 0)
    {
        prev=current;
        current=current->next;
    }
    if(prev == NULL)
    {
        new->next=list->head;
        list->head=new;
    }
    else
    {
        prev->next=new;
        new->next=current;
    }
    ++list->count;
    return TRUE;
}

void list_free(struct list * list)
{
    struct list_node * current = list->head;
    while(current != NULL)
    {
        struct list_node * next;
        next = current;
        current = current->next;
        free(next);
    }
}

int person_cmp(const struct person* first, const struct person* second)
{
    int cmp;
    cmp = strcmp(first->lname, second->lname);
    if(cmp != 0)
        return cmp;
    cmp = strcmp(first->fname, second->fname);
    return cmp;
}
