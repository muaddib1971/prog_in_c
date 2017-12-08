#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"
#include "list.h"

void read_rest_of_line(void);
#define LINELEN 80
#define EXTRACHARS 2

int main(void)
{
    char line[LINELEN + EXTRACHARS];
    char fname[NAMELEN + EXTRACHARS];
    char lname[NAMELEN + EXTRACHARS];
    int age;
    struct person * newp;
    struct list list;
    BOOLEAN quit;

    list_init(&list);

    while(!quit){
        /* fgets code here */
        newp = make_person(fname, lname, age);
        if(!newp)
        {
            return EXIT_FAILURE;
        }
        if(!list_add(&list, newp)){
            return EXIT_FAILURE;
        }
    }
#if 0
    list_print(&list);
#endif
    list_free(&list);
    return EXIT_SUCCESS;
}
