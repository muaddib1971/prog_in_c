#include <stdio.h>
#include <stdlib.h>

int main(void)
{
        char date[] = "12/10/2019";
        int day, month, year;

        sscanf("%d/%d/%d", date, &day, &month, &year);
        printf("it is the %d day of the %d month in the year %d\n", day, month,
               year);
        return EXIT_SUCCESS;
}
