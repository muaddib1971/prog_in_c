#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

typedef enum
{
        FALSE,
        TRUE
} BOOLEAN;

#define DECIMAL 10

/* 1\03,5,7,9 */ /*"1" */
BOOLEAN split(char orig_str[], char* parts[], int parts_len, char delims[])
{
        char* tok;
        int curtok = 0;

        tok = strtok(orig_str, delims);
        while (tok != NULL)
        {
                if (curtok == parts_len)
                {
                        return FALSE;
                }

                parts[curtok] = tok;
                tok =
                    strtok(NULL /* use the string you already have */, delims);
                ++curtok;
        }
        return TRUE;
}
/* "                                            12                    "*/
/* strtod */
BOOLEAN
strtoint(const char snum[], int* output)
{
        long loutput;
        char* end;
        loutput = strtol(snum, &end, DECIMAL);
        /* skip whitespace */
        while (isspace(*end))
        {
                ++end;
        }
        if (*end != '\0')
        {
                printf("error: string is not numeric\n");
                return FALSE;
        }
        if (loutput < INT_MIN || loutput > INT_MAX)
        {
                /* error message about range */
                return FALSE;
        }
        *output = loutput;
        return TRUE;
}

int main(void)
{
        int outcount;
        int sum = 0;
        char nums[] = "1,3,5,7,9";
        char* parts[5];
        if (!split(nums, parts, 5, ","))
        {
                printf("Error: could not tokenize\n");
                return EXIT_FAILURE;
        }
        printf("%p\n", nums);
        for (outcount = 0; outcount < 5; ++outcount)
        {
                int num;
                if (strtoint(parts[outcount], &num))
                {
                        sum += num;
                        if (sum < 0)
                        {
                        }
                }
                printf("%s\t", parts[outcount]);
        }
        putchar('\n');
        for (outcount = 0; outcount < 5; ++outcount)
        {
                printf("%p\n", (void*)parts[outcount]);
        }
        putchar('\n');

        printf("the sume is %d\n", sum);
        return EXIT_SUCCESS;
}
