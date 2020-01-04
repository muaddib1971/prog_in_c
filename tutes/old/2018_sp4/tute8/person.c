#include "person.h"
struct person* person_make(const char fname[], const char lname[], long age)
{
        struct person* new;
        new = (struct person*)malloc(sizeof(struct person));
        if (!new)
        {
                perror("malloc failed");
                return NULL;
        }
        strcpy(new->fname, fname);
        strcpy(new->lname, lname);
        new->age = age;
        return new;
}

void person_free(struct person* aperson)
{
        assert(aperson != NULL);
        free(aperson);
}

int person_cmp(const struct person* persona, const struct person* personb)
{
        int cmp;
        cmp = strcmp(persona->lname, personb->lname);
        if (cmp)
        {
                return cmp;
        }
        cmp = strcmp(persona->fname, personb->fname);
        if (cmp)
        {
                return cmp;
        }
        return persona->age - personb->age;
}

int person_delcmp(const struct person* person, const char name[])
{
        return strcmp(person->lname, name);
}

void person_print(const struct person* aperson)
{
        printf("first name: %s, last name: %s, age: %u\n", aperson->fname,
               aperson->lname, aperson->age);
}
