#ifndef PERSON_H
#define PERSON_H
#define NAMELEN 20
struct person{
    char fname[NAMELEN + 1];
    char lname[NAMELEN + 1];
    int age;
};

int person_cmp(const void*, const void*);
struct person * make_person(char fname[], char lname[], int age);
#endif
