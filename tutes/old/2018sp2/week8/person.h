#ifndef PERSON_H
#define PERSON_H
#define NAMELEN 20
typedef struct person {
    char fname[NAMELEN + 1];
    char lname[NAMELEN + 1];
    int age;
} Person;

Person *make_person(const char[], const char[], int);
int person_cmp(const Person *, const Person *);
#endif
