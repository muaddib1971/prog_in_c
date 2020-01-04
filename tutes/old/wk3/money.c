#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MONEYLEN 6
#define EXTRACHARS 2

struct money
{
        int dollars, cents;
};

#define DELIMS "."
#define DECIMAL 10
enum currency_type
{
        DOLLARS,
        CENTS
};

int main(void)
{
        char money_input[MONEYLEN + EXTRACHARS];
        char* tok;
        enum currency_type type = DOLLARS;
        struct money dollarz;
        fgets(money_input, MONEYLEN + EXTRACHARS, stdin);
        money_input[strlen(money_input) - 1] = 0;
        /* assumption / desired input: DDD.DD */

        tok = strtok(money_input, DELIMS);
        while (tok != NULL) /* strtok returns NULL when the string has been
                               completely tokenized */
        {
                char* end;
                long lresult;
                lresult = strtol(tok, &end, DECIMAL);
                if (*end != 0)
                {
                        printf("Error: non-numeric data entered.\n");
                        return EXIT_FAILURE;
                }
                if (lresult < 0 || lresult > INT_MAX)
                {
                        printf("Error: number entered outside the allowed "
                               "range.\n");
                        return EXIT_FAILURE;
                }
                if (type == DOLLARS)
                {
                        dollarz.dollars = (int)lresult;
                        ++type;
                }
                else
                {
                        dollarz.cents = (int)lresult;
                }

                /* do numeric conversion and store the number */
                tok = strtok(NULL, DELIMS);
        }
        printf("%d.%02d\n", dollarz.dollars, dollarz.cents);
        return EXIT_SUCCESS;
}

/* "3\n" */
/* "a3\n" */
/* "3a.5" */
