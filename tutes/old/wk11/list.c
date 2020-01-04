#include "list.h"
#include <string.h>

/**************************************************************************
 * initialise the list to a safe state where all values start from known
 * values. 
 *************************************************************************/
void list_init(struct list * list, comparator cmp, freer myfree)
{
    assert(list);
    list->head=NULL;
    list->count=0;
    /* or even better, given we are resetting all values to 0 : */
    memset(list, 0, sizeof(struct list));
    list->cmp = cmp;
    list->data_free = myfree;
}

/**************************************************************************
 * list_add() - implements the algorithm to insert into a list in sorted 
 * order. If you think back to the sorting algorithms covered earlier in 
 * this course this is an insertion sort.
 *************************************************************************/
BOOLEAN list_add(struct list * list, void * data)
{
    /* make sure to initialise your prev pointer to NULL */
    struct list_node * current, *prev=NULL;
    struct list_node * new;

    /* ensure our incoming pointers are valid */
    assert(list);
    assert(data);

    /* allocate space for the node */
    new = safemalloc(sizeof(struct list_node));
    /* initialise the next and data pointers to the appropriate values */
    /* setting next to NULL handles when we add to the end of the list */
    new->next=NULL;
    new->data=data;

    /* if we are at the begging of the list just assign the new node 
     * to the head of the list */
    if(list->head == NULL)
    {
        list->head = new;
        /* increment the count of items in the list */ 
        ++list->count;
        /* job done */
        return TRUE;
    }
    /* grab the beginning of the list and find the insertion point 
     * for our data. Remember that cmp functions work essentially
     * like subtraction - is current data less than data in our 
     * sort order?
     **/ 
    current = list->head;
    while(current != NULL && list->cmp(current->data, data) < 0)
    {
        /* grab the current pointer and assign it to previous so we can 
         * insert data between two nodes
         */
        prev=current;
        current=current->next;
    }
    /* insertion at the beginning of the list */
    if(prev == NULL)
    {
        new->next=list->head;
        list->head=new;
    }
    /* insertion at the end - redundant if statement because of the 
     * else statement further on
     **/
    else if(!current)
    {
        new->next=NULL;
        prev->next=new;
    }
    else
    {
        prev->next=new;
        new->next=current;
    }
    /* increment the count of items in the list */
    ++list->count;
    /* job done */
    return TRUE;
}

/**************************************************************************
 * free all the items in the list
 *************************************************************************/
void list_free(struct list * list)
{
    /* grab the beginning of the list */
    struct list_node * current = list->head;
    /* iterate over all the list elements */
    while(current != NULL)
    {
        struct list_node * next;
        /* grab the current element so we can free it */
        next = current;
        /* move on to the next element */
        current = current->next;
        /* free the data */
        list->data_free(next->data);
        /* free the list node */
        free(next);
    }
}


/**************************************************************************
 * prints the contents of the data elements of each link in the list 
 **************************************************************************/
void print_list(struct list * list, void (*print)(void*))
{
    struct list_node * current;
    assert (list);
    /* grab the beginning of the list */
    current = list->head;
    /* while there are still more elements in the list */
    while(current)
    {
        /* grab the data*/
        void * data = current->data;
        /* print the data */
        print(data);
        /* move onto the next node in the list */
        current = current->next;
    }
}
