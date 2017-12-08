#include <string.h>
#ifndef PERSON_H
#define PERSON_H
#define NAMELEN 20
struct person
{
        char fname[NAMELEN + 1];
        char lname[NAMELEN + 1];
        int age;
};

struct person * create_person(char fname[], char lname[], int age);
void person_free(struct person * p);
int person_cmp(const struct person *, const struct person *);
#endif /* PERSON_H */
