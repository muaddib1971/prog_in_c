#include <stdio.h>
#include <stdlib.h>
enum day
{
        MONDAY,
        TUESDAY,
        WEDNESDAY,
        THURSDAY,
        FRIDAY,
        SATURDAY,
        SUNDAY,
        DAY_INVALID = -1
};

int main(void)
{
        enum day day;
        int i = 'a';
        char ch;
        putchar(i);
        for (ch = 'a'; ch <= 'z'; ++ch)
        {
                putchar(ch);
        }
        putchar('\n');
        for (day = MONDAY; day <= SUNDAY; ++day)
        {
                switch (day)
                {
                        case MONDAY:
                                printf("it is the beginning of the week\n");
                        case TUESDAY:
                        case WEDNESDAY:
                        case THURSDAY:
                        case FRIDAY:
                                puts("it is a weekday");
                                if (day != FRIDAY)
                                {
                                        break;
                                }
                                puts("it is the end of the working week");
                                break;
                        default:
                                puts("yay, it's the weekend.");
                }
        }
        return EXIT_SUCCESS;
}
