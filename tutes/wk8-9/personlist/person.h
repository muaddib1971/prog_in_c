#include <stdlib.h>
#include <string.h>
#ifndef PERSON_H
#define PERSON_H
#define NAMELEN 40
struct person{
    char fname[NAMELEN + 1];
    char lname[NAMELEN + 1];
    int age;
    int id;
};

/* put any functions to help with managing the person type */
int person_cmp(const struct person *, const struct person*);
struct person * make_person(char fname[], char lname[], int age);
#endif
