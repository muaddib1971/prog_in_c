#ifndef PERSON_H
#define PERSON_H
#define NAMELEN 20
struct person
{
        char fname[NAMELEN + 1];
        char lname[NAMELEN + 1];
        int age;
};

BOOLEAN init_person(struct person*);
#endif
