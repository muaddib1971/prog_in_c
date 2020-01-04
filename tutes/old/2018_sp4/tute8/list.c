#include "list.h"
struct list* list_make(void)
{
        struct list* new = (struct list*)malloc(sizeof(struct list));
        /* calloc(sizeof(struct list), 1);  */
        if (!new)
        {
                perror("malloc failed");
                return NULL;
        }
        list_init(new);
        return new;
}
void list_init(struct list* alist)
{
        alist->list_size = 0;
        alist->head = NULL;
        memset(alist, 0, sizeof(struct list));
}

BOOLEAN list_add(struct list* alist, struct person* newperson)
{
        struct list_node* curr, *prev = NULL;
        struct list_node* newnode =
            (struct list_node*)malloc(sizeof(struct list_node));
        if (!newnode)
        {
                perror("malloc failed");
                return FALSE;
        }
        newnode->next = NULL;
        newnode->data = newperson;
        assert(alist);
        assert(newperson);
        if (!alist->head)
        {
                alist->head = newnode;
                ++alist->list_size;
                return TRUE;
        }
        /* find the insertion point */
        curr = alist->head;
        while (curr != NULL && person_cmp(curr->data, newnode->data) < 0)
        {
                prev = curr;
                curr = curr->next;
        }
        if (!prev)
        {
                newnode->next = alist->head;
                alist->head = newnode;
        }
        else
        {
                newnode->next = curr;
                prev->next = newnode;
        }
        ++alist->list_size;
        return TRUE;
}

static void node_free(struct list_node* anode)
{
        person_free(anode->data);
        free(anode);
}

BOOLEAN list_remove(struct list* thelist, const char lname[])
{
        struct list_node* curr, *prev = NULL;
        /* is the list empty ? */
        if (thelist->list_size == 0)
        {
                fprintf(stderr, "Error: list is empty - can't delete.\n");
                return FALSE;
        }

        /* find the item */
        for (curr = thelist->head; curr && person_delcmp(curr->data, lname) < 0;
             prev = curr, curr = curr->next)
                ; /* do nothing */
        if (!curr || person_delcmp(curr->data, lname))
        {
                fprintf(stderr,
                        "Error: the element to delete has not been found.\n");
                return FALSE;
        }
        if (prev == NULL)
        {
                thelist->head = thelist->head->next;
        }
        else
        {
                prev->next = curr->next;
        }
        node_free(curr);
        --thelist->list_size;
        return TRUE;
}

void list_print(const struct list* thelist, void (*print)(const struct person*))
{
        struct list_node* iter;
        for (iter = thelist->head; iter; iter = iter->next)
        {
                print(iter->data);
        }
}

void list_free(struct list* alist)
{
        struct list_node* curr;
        curr = alist->head;
        while (curr)
        {
                struct list_node* next = curr->next;
                free(curr->data);
                free(curr);
                curr = next;
        }
}
