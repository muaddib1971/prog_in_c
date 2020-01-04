#include "person.h"

struct person* person_make(const char fname[], const char lname[], int age)
{
        struct person* new = (struct person*)malloc(sizeof(struct person));
        if (!new)
        {
                perror("malloc");
                return NULL;
        }
        strcpy(new->fname, fname);
        strcpy(new->lname, lname);
        new->age = age;
        return new;
}

int person_cmp(const struct person* first, const struct person* second)
{
        int cmp = first->age - second->age;
        if (cmp != 0)
        {
                return cmp;
        }
        cmp = strcmp(first->lname, second->lname);
        if (cmp != 0)
        {
                return cmp;
        }
        return strcmp(first->fname, second->fname);
}

int person_del_cmp(const struct person* aperson, const char fname[],
                   const char lname[])
{
        int cmp = strcmp(aperson->lname, lname);
        if (cmp == 0)
        {
                return strcmp(aperson->fname, fname);
        }
        return cmp;
}

void person_free(struct person* aperson)
{
        free(aperson);
}
