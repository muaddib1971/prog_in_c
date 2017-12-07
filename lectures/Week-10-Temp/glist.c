#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include "safemalloc.h"

#define NAMELEN 40
#define LINELEN 80
#define EXTRACHARS 2
struct person
{
    char fname[NAMELEN+1];
    char lname[NAMELEN+1];
    unsigned age;
};

struct person* make_person(char *, char *, unsigned);
void print_list(GList* list);
gint person_cmp(gconstpointer,gconstpointer);
int main(void)
{
    char line[LINELEN + EXTRACHARS];
    char fname[NAMELEN+EXTRACHARS];
    char lname[NAMELEN+EXTRACHARS];
    unsigned age;
    char * end;
    BOOLEAN quit=FALSE;
    struct person * myperson;

    GList * list=NULL;
    while(!quit)
    {
        printf("Enter the person's first name: ");
        if(fgets(fname, NAMELEN+EXTRACHARS, stdin) == NULL
	   || *fname=='\n')
        {
            quit=TRUE;
            break;
        }
        fname[strlen(fname)-1]=0;
        printf("Enter the person's last name: ");
        if(fgets(lname, NAMELEN+EXTRACHARS, stdin) == NULL
	   || *lname == '\n')
        {
            quit=TRUE;
            break;
        }
        lname[strlen(lname)-1]=0;
        printf("Enter their age: ");
        if(fgets(line, LINELEN+EXTRACHARS, stdin) == NULL || 
	   *line == '\n')
        {
            quit=TRUE;
            break;
        }

        line[strlen(line)-1]=0;
        age = (unsigned)strtol(line, &end, 0);
        if(*end)
        {
            break;
        }
        myperson = make_person(fname, lname, age);
        if(!(list=g_list_insert_sorted(list, myperson, person_cmp)))
#if 0
        if(!(list=g_list_append(list,myperson)))
#endif
        {
            fprintf(stderr, "Error in adding a person.\n\n");
            break;
        }
    }
    print_list(list);
#if 0
    g_list_foreach(list, g_free, NULL);
    g_list_free(list);
#endif 
    g_list_free_full(list, g_free);
    return EXIT_SUCCESS;
}

static void print_person(gpointer data, gpointer user_data)
{
    struct person * pdata = (struct person *)data;
    (void)user_data;
    printf("%s\t%s\t%u\n", pdata->fname, pdata->lname, pdata->age);
}

void print_list(GList * list)
{
    assert (list);
    GList * current = list;
#if 0
    g_list_foreach(list, print_person, NULL);
#endif
    while(current)
    {
        struct person * data = current->data;
        printf("%s\t%s\t%u\n", data->fname, data->lname, data->age);
        current = current->next;
    }
}

struct person* make_person(char * fname, char * lname, unsigned age)
{
    struct person* new;
    assert(fname);
    assert(lname);

    new = safemalloc(sizeof(struct person));
    strcpy(new->fname, fname);
    strcpy(new->lname, lname);
    new->age = age;
    return new;
}

gint person_cmp(gconstpointer a,gconstpointer b)
{
    const struct person * p_a = a, *p_b = b;
    gint cmp;
    cmp = strcmp(p_a ->lname, p_b->lname);
    if(cmp)
        return cmp;
    return strcmp(p_a->fname, p_b->fname);
}
