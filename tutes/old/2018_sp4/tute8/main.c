#include "main.h"
#define EXTRACHARS 2
int main(void)
{
        struct list alist;
        BOOLEAN quit = FALSE;
        /* struct list * alist = list_make();*/
        list_init(&alist);
        do
        {
                char fname[NAMELEN + EXTRACHARS];
                char lname[NAMELEN + EXTRACHARS];
                char agestr[NAMELEN + EXTRACHARS];
                unsigned age;
                struct person* newperson;
                /* fgets for fname */
                printf("Eenter a first name: ");
                fgets(fname, NAMELEN + EXTRACHARS, stdin);
                if (fname[0] == '\n')
                {
                        break;
                }

                /* fgets for lname */
                printf("Eenter a last name: ");
                fgets(lname, NAMELEN + EXTRACHARS, stdin);

                /* get int for age */
                printf("Enter an age: ");

                fgets(agestr, NAMELEN + EXTRACHARS, stdin);
                age = strtol(agestr, NULL, 10);
                newperson = person_make(fname, lname, age);
                list_add(&alist, newperson);
        } while (!quit);
        /* all passing of values into functions is pass by value in c*/
        list_print(&alist, person_print);
        list_free(&alist);
        return EXIT_SUCCESS;
}
