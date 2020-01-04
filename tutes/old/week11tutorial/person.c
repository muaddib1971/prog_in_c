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

int person_cmp(void* p_a, void* p_b)
{
        struct person* persona = p_a;
        struct person* personb = p_b;
        int cmp = strcmp(persona->lname, personb->lname);
        if (cmp == 0)
        {
                cmp = strcmp(persona->fname, personb->fname);
        }
        return cmp;
}

void person_print(void* vdata)
{
        struct person* data = vdata;
        printf("%s, %s, %d\n", data->fname, data->lname, data->age);
}

void free_person(void* person)
{
        free(person);
}
