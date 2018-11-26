#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#ifndef PERSON_H
#define PERSON_H
#define NAMELEN 40

struct person
{
        char fname[NAMELEN + 1];
        char lname[NAMELEN + 1];
        int age;
};

typedef enum
{
        FALSE,
        TRUE
} BOOLEAN;

struct person* make_person(const char[], const char[], int);
#endif /* PERSON_H */
