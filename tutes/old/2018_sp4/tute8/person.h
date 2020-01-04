#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#ifndef PERSON_H
#define PERSON_H
#define NAMELEN 20
struct person
{
        char fname[NAMELEN + 1];
        char lname[NAMELEN + 1];
        unsigned age;
};

typedef enum
{
        FALSE,
        TRUE
} BOOLEAN;

struct person* person_make(const char[], const char[], long);
void person_free(struct person*);
int person_cmp(const struct person*, const struct person*);
int person_delcmp(const struct person*, const char[]);
void person_print(const struct person*);
#endif
