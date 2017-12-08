#include "person.h"

/**************************************************************************
 * function that creates a new person based on the data passed in - think
 * of this like a constructor in object oriented languages.
 *************************************************************************/
struct person* make_person(char * fname, char * lname, unsigned age)
{
    struct person* new;
    /* fname and age must be valid pointers */
    assert(fname);
    assert(lname);

    /* make space for the person */
    new = safemalloc(sizeof(struct person));
    /* copy in the data */
    strcpy(new->fname, fname);
    strcpy(new->lname, lname);
    new->age = age;
    return new;
}

/**************************************************************************
 * a comparison function that compares to person structs. 
 * a comparison function returns a negative number if the first number
 * is lower in the sort order, a positive number if the first number is 
 * greater in the sort order and 0 if they are equal.
 *************************************************************************/
int person_cmp(const void * first, const void * second)
{
    int cmp;
    /* compare for last name to begin with and if they are different 
     * return the result
     */
    const struct person * pfirst = first;
    const struct person * psecond = second;
    cmp = strcmp(pfirst->lname, psecond->lname);
    if(cmp != 0)
        return cmp;
    /* otherwise compare on their first name. But what if their first and 
     * last names are the same? */
    cmp = strcmp(pfirst->fname, psecond->fname);
    if(cmp != 0)
        return cmp;
    /* we could also compare their ages */
    return pfirst->age - psecond->age;
}


void person_free(void * p)
{
        free(p);
}
