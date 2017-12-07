#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Days
{
    Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
};
#define NUMDAYS 7
#define NUMMONTHS 12

int main(void)
{
    struct tm curtm, *curtm_p;
    time_t curtime;
    /* define the names of days and months for custom printout */
    char * days[NUMDAYS] = { "Sunday", "Monday", "Tuesday", "Wednesday", 
        "Thursday", "Friday", "Saturday", };
    char * months[NUMMONTHS]= { "January", "February", "March", "April", 
        "May", "June", "July", "August", "September", "October", 
        "November", "December"};

    /* get the time */
    time(&curtime);
    /* print it out as an int and as a full date */
    printf("\ncurrent time: %ld\n\n", curtime);
    printf("current time text: %s\n", ctime(&curtime));
    /* covert the time_t value to a struct tm */
    curtm_p = localtime(&curtime);
    curtm=*curtm_p;
    /* output the date using the built in format */
    printf("string of converted time: %s\n", asctime(&curtm));
    /* add 5 days onto the date */
    curtm.tm_mday+=14;
    /* normalise the date in case we are on a month border */
    curtime=mktime(&curtm);
    /* print out the altered date in a custom way */
    printf("custom printout of time: %s %s %02d\t%02d:%02d:%02d\t%d\n", 
        days[curtm.tm_wday], months[curtm.tm_mon], curtm.tm_mday, 
        curtm.tm_hour, curtm.tm_min, curtm.tm_sec, curtm.tm_year + 1900);

    /* print out the altered date in a way determined by the system */
    printf("altered date system printout: %s\n\n", ctime(&curtime));
    return EXIT_SUCCESS;
}
