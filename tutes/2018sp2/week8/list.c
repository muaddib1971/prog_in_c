#include "list.h"

/* with gcc : -DNDEBUG */
void list_init(struct list *list) {
    assert(list != NULL);
    list->head = NULL;
    list->size = 0;

    /*
    memset(list, sizeof(struct list), 0);
    memset(list, sizeof(*list), 0);
    */
}

static struct node *new_node(Person *data) {
    struct node *new = (struct node *)malloc(sizeof(struct node));
    if (!new) {
        perror("malloc");
        return NULL;
    }
    new->data = data;
    new->next = NULL;
    return new;
}

#define EMPTY(LIST) (LIST)->head == NULL

/* assumption - data is malloced separately */
BOOLEAN list_add(struct list *list, Person *data) {
    struct node *current, *prev = NULL;
    struct node *new = new_node(data);
    assert(list != NULL);
    assert(data != NULL);

    if (!new) {
        return FALSE;
    }
    if (EMPTY(list)) {
        list->head = new;
        list->size++;
        return TRUE;
    }
    current = list->head;
    while (current && person_cmp(current->data, data) < 0) {
        prev = current;
        current = current->next;
    }
    if (!prev) {
        new->next = list->head;
        list->head = new;
    } else {
        new->next = current;
        prev->next = new;
    }
    list->size++;
    return TRUE;
}

BOOLEAN list_del(struct list *, const char[], const char[]);

list_free(struct list *thelist) {
    struct node *current, *next;
    current = thelist->head;
    while (current) {
        next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
}
