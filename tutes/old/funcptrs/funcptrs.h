#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
type (*name)(typea , typeb);

//int (*cmp)(struct person*, struct person*);

typedef int (*comparer)(struct person*, struct person*);


comparer cmp;
*/
#define TXTLEN 50
struct menu_item
{
        char text[TXTLEN + 1];
        void (*messenger)(void);
};

void hello(void);
void goodbye(void);
void go_away(void);
void quit(void);
