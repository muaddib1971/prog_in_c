#include "person_list.h"
#include <stdio.h>

int main(void)
{
        struct person people[] = { { "fred", "flinstone", 32 },
                                   { "barney", "rubble", 44 },
                                   { "wilma", "flintsone", 33 } };
        struct list thelist;
        int count;
        list_init(&thelist, person_cmp, free_person, person_print);
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
        list_print(&thelist);
        list_free(&thelist);
        return EXIT_SUCCESS;
}
