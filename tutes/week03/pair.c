#include <stdio.h>
#include <stdlib.h>

struct date
{
        int day, month, year;
};

struct pair
{
        int a, b;
        struct date today;
};

void init_date(struct date* adate, int day, int month, int year)
{
        adate->day = day;
        adate->month = month;
        adate->year = year;
}

void init_pair(struct pair* newpair, int first, int second, int day, int month,
               int year)
{
        newpair->a = first;
        newpair->b = second;
        init_date(&newpair->today, day, month, year);
}

int main(void)
{
        /* ok, works fine */
        struct pair apair = { 1, 3 };
        struct pair somepair;

        int a = 5, b = 7;

        /* won't work as a and b are not known at compile time as they are
         * variables
         */
        struct pair another = { a, b };

        int array[a];:

        /**
         * this is assignment and so the braces are not valid.
         **/
        /* apair = { 4, 5 };*/

        init_pair(&somepair, 7, 6, 23, 5, 2019);
}
