/****************************************************************************
* Steven Burrows
* sdb@cs.rmit.edu.au
* Created October 2004
* 
* localtime.c
* This program demonstrates how to extract the system time.
* Disclaimer: This may not necessarily be the best/only way to extract the 
* system time. It is an example only.
*
* Documentation: Please read the following man pages before posting questions
* about this program to the webphorum/newsgroup:
* - man -s2 time
* - man localtime
*
* Acknowledgement: Adapted from code created by Rahul Iyer.
*
* Permission to use this code is provided under the condition that 
* appropriate acknowledgement is made.
****************************************************************************/

# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <sys/types.h>
# include <strings.h>

int main(void)
{
   /* Declaring a variable to store the time since EPOCH - 1 Jan 1970. 
    * See "man localtime" for more information. */ 
	time_t          now;

   /* Variable to point to a structure which will store time components. */
   struct tm*      timeNow;

   /* array of strings for the months of the year */
   char * months[] = { "January", "February", "March", "April", "May", 
        "June", "July", "August", "September", "October", "November", 
        "December"
   };
   
   /* Using time() function to update value of variable 'now'. */
   now = time(NULL);
   printf("\nSYSTEM TIME INFORMATION:\n");
   printf("\nSeconds since EPOCH: %ld\n", now);

   /* Using 'localtime' function, convert clock time and store appropriate 
    * values into a structure pointed to by 'timeNow'. */
   timeNow = localtime(&now);
   printf("Day of Month: %d\n", timeNow->tm_mday);
   printf("Month (0-11): %d\n", timeNow->tm_mon);
   printf("Year (Since 1900): %d\n", timeNow->tm_year);
   printf("Month string: %s\n\n", months[timeNow->tm_mon]);

   return EXIT_SUCCESS;
}
