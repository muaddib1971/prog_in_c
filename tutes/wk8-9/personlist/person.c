#include "person.h"
int person_cmp(const struct person * pa, const struct person* pb){
    return strcmp(pa->lname, pb->lname);
}

struct person * make_person(char fname[], char lname[], int age){
    struct person * new = (struct person *)malloc(sizeof (struct person));
    if(!new){
        perror("malloc failed");
        return NULL;
    }
    strcpy(new->fname, fname);
    strcpy(new->lname, lname);
    new->age = age;

    return new;
}
