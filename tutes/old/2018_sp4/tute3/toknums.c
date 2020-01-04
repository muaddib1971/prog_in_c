#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

#define DELIMS ","
#define DECIMAL 10

int main(void)
{
        char numstr[] = "1,3,5,7,9,11";
        /* "1abc" */
        char* tok;
        int total = 0;
        long lnext;

        tok = strtok(numstr, DELIMS);
        while (tok)
        {
                char* end;
                lnext = strtol(tok, &end, DECIMAL);
                while (isspace(*end))
                {
                        end++;
                }
                if (*end)
                {
                        fprintf(stderr, "Error: non numeric data.\n");
                        return EXIT_FAILURE;
                }
                if (lnext < INT_MIN || lnext > INT_MAX)
                {
                        fprintf(
                            stderr,
                            "Error: number outside the range for an int.\n");
                }
                total += (int)lnext;
                tok = strtok(NULL, DELIMS);
        }
        printf(" the total is %d\n", total);
        return EXIT_SUCCESS;
}
