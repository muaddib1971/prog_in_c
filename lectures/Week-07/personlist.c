#include "list.h"
#include <stdio.h>
#include <stdio.h>
#include <string.h>

#define LINELEN 80
#define EXTRACHARS 2
struct person* make_person(char *, char *, unsigned);
void print_list(struct list * list);
int main(void)
{
    char line[LINELEN + EXTRACHARS];
    char fname[NAMELEN+EXTRACHARS];
    char lname[NAMELEN+EXTRACHARS];
    unsigned age;
    char * end;
    BOOLEAN quit=FALSE;
    struct person * myperson;
    struct list list;
    list_init(&list);

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
        if(!list_add(&list, myperson))
        {
            fprintf(stderr, "Error in adding a person.\n\n");
            break;
        }
    }
    print_list(&list);
    list_free(&list);
    return EXIT_SUCCESS;
}


void print_list(struct list * list)
{
    struct list_node * current;
    assert (list);
    current = list->head;
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
