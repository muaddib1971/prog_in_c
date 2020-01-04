#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef PERSON_H
#define PERSON_H

#define NAMELEN 20
struct person
{
        char fname[NAMELEN + 1];
        char lname[NAMELEN + 1];
        int age;
};

struct person* person_make(const char[], const char[], int);
void person_free(struct person*);
int person_cmp(const struct person*, const struct person*);
int person_del_cmp(const struct person*, const char[], const char[]);
#endif
