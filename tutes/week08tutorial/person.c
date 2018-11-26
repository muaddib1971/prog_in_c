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
