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

int person_cmp(void* a, void* b)
{
        struct person* p_a = a, *p_b = b;
        int cmp = strcmp(p_a->lname, p_b->lname);
        if (cmp == 0)
        {
                cmp = strcmp(p_a->fname, p_a->fname);
        }
        return cmp;
}

int del_cmp(void* data, void* fields)
{
        struct person* pers = data, *compar = fields;

        int cmp;
        cmp = strcmp(pers->lname, compar->lname);
        if (cmp)
        {
                return cmp;
        }
        return strcmp(pers->fname, compar->fname);
}

void person_free(void* pers)
{
        free(pers);
}

void person_print(void* p)
{
        struct person* pers = 0;
        printf("%s %s %d\n", pers->fname, pers->lname, pers->age);
}
