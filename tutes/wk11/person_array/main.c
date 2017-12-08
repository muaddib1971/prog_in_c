#include "list.h"
#include "person.h"
int main(void)
{
    struct person * new;
    struct list mylist;
    list_init(&mylist, person_cmp);
    new = make_person("Fred", "Flinstone", 42);
    if(!list_add(&mylist, new))
    {
        /* error */
    }
}
