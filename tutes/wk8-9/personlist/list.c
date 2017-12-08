#include "list.h"

int get_next_id(void)
{
    static int curid = 0;
    return ++curid;
}

BOOLEAN list_init(struct list * list)
{
    /* one option */
    list->head = NULL;
    list->num_nodes = 0;

    /* another option */
    memset(list, 0, sizeof(struct list));
    return TRUE;
}

BOOLEAN list_add( struct list * list, struct person * person)
{
    struct node * current, * prev = NULL;
    struct node * newnode = (struct node *)malloc(sizeof(struct node));
    int id = get_next_id();
    if(!newnode){
        perror("malloc failed");
        return FALSE;
    }
    person->id = id;
    newnode->next = NULL;
    if(list->num_nodes == 0){
        list->head = newnode;
        ++list->num_nodes;
        return TRUE;
    }
    current = list->head;
    while(current && person_cmp(current->data, person) < 0){
        prev = current;
        current = current->next;
    }
    if(prev == NULL){
        newnode->next = list->head;
        list->head = newnode;
    }
    else{
        prev->next = newnode;
        newnode->next = current;
    }
    ++list->num_nodes;
    return TRUE;
}

/**
 * -search for the item to delete
 * -remove the item
 * -free memory
 *  ALL LISTS INVOLVE THIS
 **/
BOOLEAN list_remove( struct list * list, int id)
{
    struct node * current, * prev = NULL;
    if(list->num_nodes == 0){
        fprintf(stderr, "Error: can't delete from an empty list.\n");
        return FALSE;
    }
    current = list->head;
    while(current != NULL && current->data->id < id){
        prev = current;
        current = current->next;
    }
    if(current == NULL || current->data->id != id){
        fprintf(stderr, "Error: item not found.\n");
        return FALSE;
    }
    if(!prev){

        list->head = list->head->next;
    } else {
        prev->next = current->next;
    }
    free(current->data);
    free(current);
    -- list->num_nodes;
}

void list_free( struct list* list)
{
    struct node *curr, *next;
    curr = list->head;
    while(curr){
        next = curr->next;
        free(curr->data);
        free(curr);
        curr=next;
    }
}
