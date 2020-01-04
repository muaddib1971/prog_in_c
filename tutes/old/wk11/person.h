#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "safemalloc.h"
#ifndef PERSON_H
#define PERSON_H
#define NAMELEN 20
struct person 
{
    char fname[NAMELEN+1];
    char lname[NAMELEN+1];
    unsigned age;
};

struct person* make_person(char *, char *, unsigned);
int person_cmp(const void *, const void *);
void person_free(void * p);
#endif /* PERSON_H */
