#include "person.h"

struct person* make_person(const char fname[], const char lname[], int age)
{
        struct person* newp;
        newp = (struct person*)malloc(sizeof(struct person));
        if (newp == NULL)
        {
                perror("malloc error");
                return NULL;
        }
        strcpy(newp->fname, fname);
        strcpy(newp->lname, lname);
        newp->age = age;
        return newp;
}

int person_cmp(const void* a, const struct void* b)
{
        struct person* p_a = a;
        struct person* p_b = b;
        int cmp = strcmp(p_a->lname, p_b->lname);
        if (cmp == 0)
        {
                cmp = strcmp(p_a->fname, p_a->fname);
        }
        return cmp;
}
