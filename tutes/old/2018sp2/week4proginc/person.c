#include "person.h"

BOOLEAN init_person(struct person* person)
{
        char name[NAMELEN + EXTRACHARS];
        get_string("Please enter your name: ", name, NAMELEN + EXTRACHARS);
        strcpy(person->fname, name);
        get_string("Please enter your last name: ", name, NAMELEN + EXTRACHARS);
        strcpy(person->lname, name);
        get_int("Please enter your age: ", &person->age);
        return TRUE;
}

int main(void)
{
        struct person p;
        if (!init_person(&p))
        {
                display_error();
        }
}

#define ADDRESS_OF(X) &(X)

#define VALUE_OF(X) *(X)

p->age == (*p).age
