#include "list.h"
void list_init(struct list * list)
{
        memset(list, 0, sizeof(struct list));
}

/* assumption: data was malloced */
BOOLEAN list_add(struct list * list , struct person * data)
{
        struct node * new_link;
        struct node * current, *prev = NULL;
        assert(list != NULL);
        assert(data != NULL);

        new_link = (struct node *) malloc(sizeof(struct node));
        if(!new_link)
        {
                perror("failed to allocate memory");
                return FALSE;
        }
        new_link->next = NULL;
        new_link->data = data;

        if(list->num_nodes == 0)
        {
                list->head = new_link;
                ++ list->num_nodes;
                return TRUE;
        }
        current = list->head;
        while(current && personcmp(current->data, data) < 0)
        {
                prev = current;
                current = current->next;
        }
        if(prev == NULL)
        {
                new_link->next = list->head;
                list->head = new_link;
        }
        else
        {
                new_link->next = current;
                prev->next = new_link;
        }
        ++ list->node_count;
        return TRUE;
}

void list_print(struct list * list)
{
        /* exercise for you */
}

BOOLEAN list_delete(struct list* list, const char fname[], 
        const char lname[])
{
        struct person p_needle;
        struct node * current, * prev = NULL;
        strcpy(p_needle.fname, fname);
        strcpy(p_needle.lname, lname);

        if(list->num_nodes == 0)
        {
                /* nothing to delete */
                return FALSE;
        }
        current = list->head;
        while(current && person_cmp(current->data, &p_needle) < 0)
        {
                prev = current;
                current = current -> next;
        }
        if(!current)
        {
                /* item not found */
                return FALSE;
        }
        if(person_cmp(current->data, &p_needle) > 0)
        {
                return FALSE;
        }
        if(!prev)
        {
                list->head = list head->next;
        }
       
        else
        {
                prev->next = current->next;
        }
        free(current->data);
        free(current);
        --list->num_nodes;
        return TRUE;
}

static void rev_node_print(struct node * cur_node)
{
        struct person * data;
        if(!cur_node)
                return;
        rev_node_print(cur_node->next);
        data = cur_node->data;
        printf("%s %s %d\n", data->fname, data->lname, data->age);
}

void reverse_print(struct list * list)
{
        rev_node_print(list->head);
}

void list_free(struct list* list)
{
        struct node * current, *next;
        current = list->head;
        while(current)
        {
                next = current;
                current = current->next;
                person_free(next->data);
                free(next);
        }
}
