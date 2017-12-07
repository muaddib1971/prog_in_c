#include "list.h"
/**************************************************************************
 * list_init() - initialise the list to a known safe state and initialise 
 * any function pointers.
 **************************************************************************/
BOOLEAN list_init(struct list * list, int(*cmp)(const void*,const void*), 
    void(*myfree)(void*))
{
    /* initialise data */
    list->head = NULL;
    list->size=0;

    /* initalise function pointers */
    list->cmp=cmp;
    list->data_free = myfree; 

    /* all good */
    return TRUE;
}

/**************************************************************************
 * list_add() insert the data in the appropriate place according to the 
 * cmp() funciton we initialised earlier 
 *************************************************************************/
BOOLEAN list_add(struct list * list, void * data)
{
    /* pointers required for iteration */
    struct node * current, * prev=NULL;
    /* our new data */
    struct node * new = (struct node *)malloc(sizeof(struct node));
    /* assign the next pointer to NULL to minimise the work if this gets
     * added to the tail of the list 
     */
    new->next = NULL;
    new->data=data;
    current = list->head;
    /* if the list is empty, simply assign the new node to the head and 
     * job done
     */
    if(!list->head)
    {
        list->head = new;
        ++list->size;
        return TRUE;
    }
    /* search for the insertion point */
    while(current != NULL && list->cmp(current->data, data) < 0)
    {
        prev = current;
        current = current->next;
    }
    /* insertion at the head */
    if(!prev)
    {
        new->next = list->head;
        list->head=new;
    }
    else
        /* insertion elsewhere in the list */
    {
        new->next = current;
        prev->next = new;
    }
    ++list->size;
    return TRUE;
}

/**************************************************************************
 * generic list printing function where we pass in a function pointer as a 
 * parameter. 
 *************************************************************************/
void list_print(struct list * list, void (*print)(const void*))
{
    struct node * current;
    current = list->head;
    /* iterate over the list */
    while(current)
    {
        /* use our custom print function pointer to decide how to print the 
         * data
         */
        print(current->data);
        current = current->next;
    }
}

/**************************************************************************
 * our function to free memory. 
 *
 * the big difference here is that we use a function pointer in the list 
 * header to perform the freeing of the data 
 *************************************************************************/
void list_free(struct list * list)
{
    struct node * next, *current = list->head;
    while(current)
    {
        next = current->next;
        /* call the data_free function which is a pointer to the actuall 
         * function. 
         */
        list->data_free(current->data);
        free(current);
        current = next;
    }
}
