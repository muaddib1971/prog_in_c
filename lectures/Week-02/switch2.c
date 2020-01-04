#include <stdio.h>
#include <stdlib.h>
/* unlike in switch.c, we will not get a compiler warning here as we
 * have handled all valid values in the switch statement.
 *
 * also note that now we have a default clause which will handle all
 * other values entered. Note that if we had not added a case statement
 * for FIFTH and added a default clause we would have gotten rid of the
 * previous compiler warning as well
 */
typedef enum options
{
        /* actually numbered 0,1,2,3,4 */
        FIRST,
        SECOND,
        THIRD,
        FOURTH,
        FIFTH
} options;

int main(void)
{
        /* oops, opt is well outside the enum. Don't do this as it makes the
         * enum pointless. In this case, use an int */
        options opt = 88;
        switch (opt)
        {
                /* don't hard-code the output like this */
                /* if you are going to use an enum rely on the automatic
                 * assignment of values by the enum declaration most of
                 * the time
                 */
                case FIRST:
                        printf("%d\n", 1);
                        break;
                case SECOND:
                        printf("%d\n", 2);
                        break;
                case THIRD:
                        printf("%d\n", 3);
                        break;
                case FOURTH:
                case FIFTH:
                        printf("%d\n", 4);
                        break;

                default:
                        printf("invalid value: %d\n", opt);
        }
        return EXIT_SUCCESS;
}
