#include "listmanager.h"

int main(void)
{
        BOOLEAN quit = FALSE;

        struct list list;

        char fname[NAMELEN + EXTRA_CHARS],
                lname[NAMELEN + EXTRA_CHARS];
        int age;
        list_init(&list);
        while(!quit)
        {
                struct person new_person;
                if(fgets(fname, NAMELEN + EXTRACHARS, stdin) == NULL)
                {
                        quit = TRUE;
                        continue;
                }

                if(fgets(lname, NAMELEN + EXTRACHARS, stdin) == NULL)
                {
                        quit = TRUE;
                        continue;
                }
                /* also get the age from the keyboard */

                new_person = create_person(fname, lname, age);

                list_add(&list, new_person);
        }
        list_print(&list);
        list_free(&list);
        return EXIT_SUCCESS;
}
