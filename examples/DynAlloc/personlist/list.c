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
    /* or even better, given we are resetting all values to 0 : */
    memset(list, 0, sizeof(struct list));
}

/**************************************************************************
 * list_add() - implements the algorithm to insert into a list in sorted 
 * order. If you think back to the sorting algorithms covered earlier in 
 * this course this is an insertion sort.
 *************************************************************************/
BOOLEAN list_add(struct list * list, struct person * data)
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
    while(current != NULL && person_cmp(current->data, data) < 0)
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
        free(next->data);
        /* free the list node */
        free(next);
    }
}

/**************************************************************************
 * a comparison function that compares to person structs. 
 * a comparison function returns a negative number if the first number
 * is lower in the sort order, a positive number if the first number is 
 * greater in the sort order and 0 if they are equal.
 *************************************************************************/
int person_cmp(const struct person* first, const struct person* second)
{
    int cmp;
    /* compare for last name to begin with and if they are different 
     * return the result
     */
    cmp = strcmp(first->lname, second->lname);
    if(cmp != 0)
        return cmp;
    /* otherwise compare on their first name. But what if their first and 
     * last names are the same? */
    cmp = strcmp(first->fname, second->fname);
    if(cmp != 0)
        return cmp;
    /* we could also compare their ages */
    return first->age - second->age;
}

