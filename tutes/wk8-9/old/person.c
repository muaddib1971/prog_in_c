#include "person.h"

struct person * create_person(const char fname[], const char lname[],
        int age)
{
        struct person * new = (struct person *)
                malloc(sizeof(struct person));
        if(!new)
        {
                perror("failed to allocate memory");
                return NULL;
        }
        strcpy(new->fname, fname);
        strcpy(new->lname, lname);
        new->age = age;
        return new;
}

int person_cmp(const struct person * p_a, const struct person * p_b)
{
        int cmp;
        cmp = strcmp(p_a->lname, p_b->lname);
        if(!cmp)
        {
                cmp = strcmp(p_a->fname, p_b->fname);
        }
        if(!cmp)
        {
                cmp = p_a->age - p_b->age;
        }
        return cmp;
}


void person_free(struct person * p)
{
        free(p);
}
