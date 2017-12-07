#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
/* This program runs a task a number of times and returns the 
 * number of seconds that it takes to execute
 */
int main(void)
{
    time_t begin;
    time_t end;
    unsigned count;

    /* get the current time */
    begin=time(NULL);

    for(count = 0; count < INT32_MAX; ++count)
    {
        printf("hi fred\n");
    }
    /* get the time after we have done the work */
    end = time(NULL);
    /* output the difference which is how long the task took */
    printf("there are %f seconds between begin and end\n", 
        difftime(end, begin));
    return EXIT_SUCCESS;
}
