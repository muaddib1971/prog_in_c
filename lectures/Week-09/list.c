#include "list.h"
#include <string.h>
/**************************************************************************
 * initialise the list to a known safe state.
 *************************************************************************/
void list_init(struct list * list)
{
    assert(list);
    list->head=NULL;
    list->count=0;
}

/**************************************************************************
 * add a person to the list, sorted according to the order established in
 * person_cmp().
 *************************************************************************/
BOOLEAN list_add(struct list * list, struct person * data)
{
    struct list_node * current, *prev=NULL;
    struct list_node * new;
    assert(list);

    /* allocate space for the new node and initialise it */
    new = safemalloc(sizeof(struct list_node));
    new->next=NULL;
    new->data=data;

    /* if the list is empty, add to the head */
    if(list->head == NULL)
    {
        list->head = new;
        ++list->count;
        return TRUE;
    }
    /* iterate over the list, searching for the insertion point, or 
     * the end of the list (current == NULL)
     */
    current = list->head;
    while(current != NULL && person_cmp(current->data, data) < 0)
    {
        prev=current;
        current=current->next;
    }
    /* insertion at the head */
    if(prev == NULL)
    {
        new->next=list->head;
        list->head=new;
    }
    else
    {
        /* insertion elsewhere in the list */
        prev->next=new;
        new->next=current;
    }
    /* success! so increment the count of elements */
    ++list->count;
    return TRUE;
}

/**************************************************************************
 * free all elements in this list
 *************************************************************************/
void list_free(struct list * list)
{
    /* iterate over the list */
    struct list_node * current = list->head;
    while(current != NULL)
    {
        /* next is a pointer to the data to be freed - stored as 
         * we need to have a way to increment to get to the rest 
         * of the list
         **/
        struct list_node * next;
        next = current;
        current = current->next;
        /* free the data then the node itself */
        free(next->data);
        free(next);
    }
}

/**************************************************************************
 * provides a natural comparison over a list of persons
 *************************************************************************/
int person_cmp(const struct person* first, const struct person* second)
{
    /* our comparison */
    int cmp;
    /* compare on last name */
    cmp = strcmp(first->lname, second->lname);
    /* if the last names are the same, return the result */
    if(cmp != 0)
        return cmp;
    /* compare on firstnames */
    cmp = strcmp(first->fname, second->fname);
    return cmp;
}
