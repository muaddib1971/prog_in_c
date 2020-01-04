#include "person_list.h"
#include "person.h"
#include <stdio.h>

int main(void)
{
        struct person people[] = { { "fred", "flinstone", 32 },
                                   { "barney", "rubble", 44 },
                                   { "wilma", "flintsone", 33 } };
        struct list thelist;
        int count;
        list_init(&thelist, person_cmp, del_cmp, person_free);
        for (count = 0; count < 3; ++count)
        {
                struct person* newp =
                    make_person(people[count].fname, people[count].lname,
                                people[count].age);
                if (!newp)
                {
                        return EXIT_FAILURE;
                }
                if (!list_add(&thelist, newp))
                {
                        return EXIT_FAILURE;
                }
        }
        list_print(&thelist, person_print);
        list_free(&thelist);
        return EXIT_SUCCESS;
}
