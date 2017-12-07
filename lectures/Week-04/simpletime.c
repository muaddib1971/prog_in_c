#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MINUTES 60
#define SECONDS 60
#define HOURS 24

#define TO_DAYS(num) (num)/(SECONDS * MINUTES * HOURS)

int main(void)
{
    time_t curtime;
    /* could also be curtime=time(NULL); */
    time(&curtime);
    printf("\nDays since the beginning of the unix epoc: %ld\n\n", 
        TO_DAYS(curtime));
    return EXIT_SUCCESS;
}
