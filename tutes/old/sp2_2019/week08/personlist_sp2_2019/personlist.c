#include "personlist.h"
void list_init(struct person_list* thelist)
{
        thelist->head = NULL;
        thelist->size = 0;

        memset(thelist, 0, sizeof(struct person_list));
}

struct person_list* list_make(void)
{
        struct person_list* thelist =
            (struct person_list*)malloc(sizeof(struct person_list));
        if (thelist == NULL)
        {
                perror("malloc");
                /* or */
                fprintf(stderr, "Error: %s\n", strerror(errno));
                return NULL;
        }
        list_init(thelist);
        return thelist;
}
/* assuption that the person passed in is allocated on the heap */
static struct list_node* create_list_node(struct person* new_person)
{
        struct list_node* new =
            (struct list_node*)malloc(sizeof(struct list_node));
        if (!new)
        {
                perror("malloc");
                return NULL;
        }
        new->next = NULL;
        new->data = new_person;
        return new;
}

BOOLEAN list_add(struct person_list* thelist, struct person* new_person)
{
        struct list_node* new_list_node, *next, *prev = NULL;
        new_list_node = create_list_node(new_person);
        if (!new_list_node)
        {
                return FALSE;
        }
        if (thelist->size == 0)
        {
                thelist->head = new_list_node;
                ++thelist->size;
                return TRUE;
        }
        next = thelist->head;
        while (next && person_cmp(next->data, new_person) < 0)
        {
                prev = next;
                next = next->next;
        }
        if (prev == NULL)
        {
                new_list_node->next = thelist->head;
                thelist->head = new_list_node;
        }
        else
        {
                prev->next = new_list_node;
                new_list_node->next = next;
        }
        ++thelist->size;
        return TRUE;
}

BOOLEAN list_del(struct person_list* thelist, const char fname[],
                 const char lname[])
{
        struct list_node* next, *prev = NULL;
        if (thelist->size == 0)
        {
                /* error message */
                return FALSE;
        }
        for (next = thelist->head;
             next != NULL && !person_del_cmp(next->data, fname, lname);
             prev = next, next = next->next)
        {
        }
        next = thelist->head;
        while (next != NULL && person_del_cmp(next->data, fname, lname) == 0)
        {
                prev = next;
                next = next->next;
        }
        /* what is possible? */
        if (next == NULL)
        {
                return FALSE;
        }
        if (prev == NULL)
        {
                thelist->head = thelist->head->next;
        }
        else
        {
                /* next holds our data */
                prev->next = next->next;
        }
        free(next->data);
        free(next);
        return TRUE;
}

void list_free(struct person_list* thelist)
{
        struct list_node* curr;
        curr = thelist->head;
        while (curr)
        {
                struct list_node* next = curr->next;
                free(curr);
                curr = next;
        }
}
