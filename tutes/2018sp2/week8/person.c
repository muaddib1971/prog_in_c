#include "person.h"
static char* strdup(const char* word) {
    char* new = malloc((strlen(word) + 1) * sizeof(char));
    if (!new) {
        perror("strdup");
        return NULL;
    }
    strcpy(new, word);
    return new;
}

Person* make_person(const char fname[], const char lname[], int age) {
    Person* new;
    new = (Person*)malloc(sizeof(Person));
    if (!new) {
        perror("malloc");
        return NULL;
    }

    strcpy(new->fname, fname);
    strcpy(new->lname, lname);
    new->age = age;
}

int person_cmp(const Person* first, const Person* second) {
    int cmp;
    cmp = strcmp(first->lname, second->lname);
    if (cmp) {
        return cmp;
    }
    cmp = strcmp(first->fname, second->fname);
    if (cmp) {
        return cmp;
    }
    return first->age - second->age;
}
