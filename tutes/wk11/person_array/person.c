#include "person.h"
#include <string.h>

int person_cmp(const void* person_a, const void* person_b)
{
    const struct person * p_a = person_a;
    const struct person * p_b = person_b;

    int cmp;

    cmp = strcmp(p_a->lname, p_b->lname);
    if(cmp != 0){
        cmp = strcmp(p_a->fname, p_b->fname);
    }
    return cmp;
}
