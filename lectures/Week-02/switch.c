#include <stdio.h>
#include <stdlib.h>

/**
 * This program uses a switch statement in combination with an enumeration
 * to show how leaving out an enumeration value will result in a 
 * compiler warning. In other words the use of enumerations can help you 
 * ensure that you have covered all the options you need to. 
 * We can avoid the compiler warning by ensuring we use all the options
 * listed in the enumeration.
 */
typedef enum options
{
    FIRST,SECOND,THIRD,FOURTH, FIFTH
} options;

int main(void)
{
    options opt=3;
    printf("%d\n", opt + 1);
    switch(opt)
    {
        case FIRST:
            printf("%d\n", opt+1);
            break;
        case SECOND:
            printf("%d\n", opt+1);
            break;
        case THIRD:
            printf("%d\n", opt+1);
        case FOURTH:
            printf("%d\n", opt+1);
    }
    return EXIT_SUCCESS;
}
