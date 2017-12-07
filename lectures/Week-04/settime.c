#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define ERROR -1
int stime(time_t*);
int main(void)
{
    /* add 5 seconds onto the current time */
    time_t curtime=time(NULL);
    curtime+=5*60;
    if(stime(&curtime)==ERROR)
    {
        printf("Error: failed to change the time.\n\n");
        return EXIT_FAILURE;
    }
    printf("time updated successfully.\n\n");
    return EXIT_SUCCESS;
}
