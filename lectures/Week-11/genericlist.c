#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct person * create_person(const char*, const char *, unsigned);
int person_cmp(const void* first, const void* second);
void person_free(void*);
void print_person(const void*);

#define NAMELEN 20

struct person
{
    unsigned age;
    char fname[NAMELEN+1];
    char lname[NAMELEN+1];
};

int main(void)
{
    /* declare our persons */
    struct person * fred;
    struct person * barney;
    struct person * wilma;
    struct person * betty;
    struct list list;
    BOOLEAN success=TRUE;

    /* initialise our persons using the equivalent of a constructor */
    fred = create_person("fred", "flinstone", 42);
    if(!fred)
    {
            perror("failed to allocate memory");
            return EXIT_FAILURE;
    }
    barney = create_person("barney", "rubble", 40);
    if(!barney)
    {
            perror("failed to allocate memory");
            return EXIT_FAILURE;
    }
    wilma = create_person("wilma", "flintstone", 35);
    if(!wilma)
    {
            perror("failed to allocate memory");
            return EXIT_FAILURE;
    }
    betty = create_person("betty", "rubble", 30);
    
    if(!betty)
    {
            perror("failed to allocate memory");
            return EXIT_FAILURE;
    }
    
    /* try to initialise the list passing in the function pointers */
    if(!list_init(&list, person_cmp, person_free))
    {
        return EXIT_FAILURE;
    }

    /* add the persons we created to the list */
    success = list_add(&list, fred);
    if(success)
        success = list_add(&list, barney);
    if(success)
        success = list_add(&list, wilma);
    if(success)
        success = list_add(&list, betty);
    /* print the list of persons - they will be sorted according to 
     * personcmp() 
     */
    list_print(&list, print_person);
    /* free the list */
    list_free(&list);
    return EXIT_SUCCESS;
}

/**************************************************************************
 * create_person() : essentially performs the function of a constructor - 
 * allocate space for the struct, and initialise the struct. Return a
 * pointer to the memory allocated.
 *************************************************************************/
struct person * create_person(const char* fname, const char *lname, 
    unsigned age)
{
    struct person * new;
    new = malloc(sizeof(struct person));
    if(!new)
        return NULL;
    strcpy(new->fname, fname);
    strcpy(new->lname, lname);
    new->age = age;
    return new;
}

/**************************************************************************
 * a comparison function for the struct person - comparison functions
 * enforce a natural order onto the type in question so they can be 
 * sorted.
 *************************************************************************/
int person_cmp(const void * first, const void * second)
{
    int cmp;
    const struct person* pfirst = first;
    const struct person* psecond = second;
    /* document our assumption that first and second must be valid pointers 
     **/
    assert(first);
    assert(second);

    /* compare their last names */
    cmp = strcmp(pfirst->lname, psecond->lname);
    /* if their last names are the same, compare their first names */
    if(cmp == 0)
    {
        cmp=strcmp(pfirst->fname, psecond->fname);
    }
    if(cmp == 0)
    {
            cmp = pfirst->age - psecond->age;
    }
    return cmp;
}

/**************************************************************************
 * defines how to print a person 
 *************************************************************************/
void print_person(const void* data)
{
    const struct person * p = data;
    printf("%s\t%s\t%u\n", p->fname, p->lname, p->age);
}

/**************************************************************************
 * defines how to free a person - we have this as a separate function as 
 * some types will have pointers taht also need to be freed.
 *************************************************************************/
void person_free(void * p)
{
    free(p);
}
