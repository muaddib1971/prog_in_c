#include "person_list.h"
void list_init(struct list*, int (*data_cmp)(void*, void*),
               int (*del_cmp)(void*, void*), void (*data_free)(void*));
{
        memset(list, 0, sizeof(struct list));
        list->data_cmp = data_cmp;
        list->del_cmp = del_cmp;
        list->data_free = data_free;
}

/**
 * assumption: the person has been malloced
 **/
BOOLEAN list_add(struct list* list, void* data)
{
        struct list_node* curr, *prev = NULL;
        struct list_node* new;
        new = (struct list_node*)malloc(sizeof(struct list_node));
        if (new == NULL)
        {
                /* fprintf(stderr, "malloc failed: %s\n", strerror(errno)); */
                perror("malloc failed");
                return FALSE;
        }

        memset(new, 0, sizeof(struct list_node));
        new->data = data;
        /* test for empty list */
        if (list->head == NULL)
        {
                list->head = new;
                list->tail = new;
                ++list->num_items;
                return TRUE;
        }
        curr = list->head;
        while (curr && list->data_cmp(curr->data, data) < 0)
        {
                prev = curr;
                curr = curr->next;
        }
        if (prev == NULL)
        {
                new->next = list->head;
                new->prev = NULL;
                list->head = new;
        }
        else if (!curr)
        {
                prev->next = new;
                new->prev = prev;
                list->tail = new;
        }
        else
        {
                new->next = curr;
                curr->prev = new;
                prev->next = new;
                new->prev = prev;
        }
        ++list->num_items;
        return TRUE;
}

static int del_cmp(const struct person* pers, const char fname[],
                   const char lname[])
{
        int cmp;
        cmp = strcmp(pers->lname, lname);
        if (cmp)
        {
                return cmp;
        }
        return strcmp(pers->fname, fname);
}

BOOLEAN list_delete(struct list* list, const char fname[], const char lname[])
{
        struct list_node* curr;
        if (list->num_persons == 0)
        {
                fprintf(stderr,
                        "Error: list is empty, can't delete an item.\n");
                return FALSE;
        }
        curr = list->head;
        while (curr && del_cmp(curr->data, fname, lname) != 0)
        {
                curr = curr->next;
        }
        if (curr == NULL)
        {
                fprintf(stderr, "Error: %s %s not found in the list.\n", fname,
                        lname);
                return FALSE;
        }
        if (curr->prev == NULL)
        {
                list->head = list->head->next;
                list->head->prev = NULL;
        }
        else if (curr->next == NULL)
        {
                curr->prev->next = NULL;
                list->tail = curr->prev;
        }
        else
        {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
        }
        --list->num_persons;
        free(curr->data);
        free(curr);
        return TRUE;
}

void list_print(struct list* thelist)
{
        struct list_node* curr;
        curr = thelist->head;
        while (curr)
        {
                struct person* data = curr->data;
                printf("%s, %s, %d\n", data->fname, data->lname, data->age);
                curr = curr->next;
        }
}

void list_free(struct list* thelist)
{
        struct list_node* curr = thelist->head;
        while (curr)
        {
                struct list_node* next = curr->next;
                free(curr->data);
                free(curr);
                curr = next;
        }
}
