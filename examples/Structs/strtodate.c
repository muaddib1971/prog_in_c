#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
/* the delimiter for a date */
#define DELIM "/"
/* decimal is base ten - used with strtol */
#define DECIMAL 10
/* how many parts are there to a date */
#define DATE_TOKENS 3
/* how many arguments including the program name does this program require? */
#define NUMARGS 2
/* which argument to this program is the date argument ? */
#define DATEARG 1

/* definition of the boolean type */
typedef enum
{
        FALSE,
        TRUE
} BOOLEAN;

/* definition of a date as a day, month and year. */
struct date
{
        int day, month, year;
};

/* a validatable date contains a date and a boolean value of whether the date
 * conversion was successful or not */
struct validatable_date
{
        struct date thedate;
        BOOLEAN success;
};

/* token type - used with the tokenization of the dates to specify which token
 * we are up to */
enum tok_type
{
        TT_DAY,
        TT_MONTH,
        TT_YEAR,
        TT_INVALID
};

/* constants used to define the range of dates */
#define MIN_MONTH 1
#define MAX_MONTH 12
#define MAX_YEAR 5000 /* accepting years between 1 and 5000 */

/* enum for months that is one-based rather than zero-based as the user will
 * enter month as a number between 1 and 12 */
enum month
{
        JAN = 1,
        FEB,
        MAR,
        APR,
        MAY,
        JUN,
        JUL,
        AUG,
        SEP,
        OCT,
        NOV,
        DEC
};

/* validation functions - dest that the day month and year are valid */
BOOLEAN valid_month(int month)
{
        return month >= MIN_MONTH && month <= MAX_MONTH;
}

BOOLEAN valid_year(int year)
{
        return year > 0 && year <= MAX_YEAR;
}

/* in order to know whether the day is valid, we need to know the month as each
 * month has a different number of days */
BOOLEAN valid_day(int day, int month)
{
        int daysinmonth;
        switch (month)
        {
                case JAN:
                case MAR:
                case MAY:
                case JUL:
                case AUG:
                case OCT:
                case DEC:
                        daysinmonth = 31;
                        break;
                case APR:
                case JUN:
                case SEP:
                case NOV:
                        daysinmonth = 30;
                        break;
                case FEB:
                        daysinmonth = 29;
                        break;
        }
        return (day < 1 || day > daysinmonth) ? FALSE : TRUE;
}

/**
 * convenience function to easily copy a string. This function exists in the c99
 * standard but not in c89. It uses malloc so we much free this memory later
 **/
char* strdup(const char* str)
{
        /* allocate memory for the string */
        char* copy = malloc(strlen(str) + 1);
        if (!copy)
        {
                perror("malloc failed");
                return NULL;
        }
        /* copy the data */
        strcpy(copy, str);
        return copy;
}

/**
 * extracts an integer from a string. Validates that the number extracted is
 *within the rang of a string
 **/
BOOLEAN int_from_string(const char* input, int* output)
{
        char* end;
        /* extract the number */
        long lresult = strtol(input, &end, DECIMAL);
        /* remember that the end pointer points to the next char after what has
         * been successfully parsed by strtol. There might be some whitespace so
         * we skip that. anything else is invalid data */
        while (isspace(*end))
        {
                ++end;
        }
        if (*end)
        {
                fprintf(stderr, "error: %s is not numeric.\n", input);
                return FALSE;
        }
        /* validate that the number extracted is within the range of an integer
         */
        if (lresult < INT_MIN || lresult > INT_MAX)
        {
                fprintf(stderr,
                        "Error: %s is not within the range of an int.\n",
                        input);
                return FALSE;
        }
        *output = lresult;
        return TRUE;
}

/**
 * the main workhorse of this program. It tries to convert a string to a date
 * structure. The date structure is wrapped is a validatable_date because the
 * conversion can fail.
 **/
struct validatable_date get_date(const char* input)
{
        struct validatable_date result;
        /* copy the string as we don't want to modify it */
        char* copy = strdup(input);
        /* each token extracted */
        char* tok;
        /* the count of tokens */
        int tok_count = 0;

        /* extract the first token */
        tok = strtok(copy, DELIM);
        /* keep extracting tokens until we run out */
        while (tok)
        {
                /* deal with each token - extract the int and store it in the
                 * structure */
                switch (tok_count)
                {
                        case TT_DAY:
                                if (!int_from_string(tok, &result.thedate.day))
                                {
                                        result.success = FALSE;
                                        return result;
                                }
                                break;
                        case TT_MONTH:
                                if (!int_from_string(tok,
                                                     &result.thedate.month))
                                {
                                        result.success = FALSE;
                                        return result;
                                }
                                break;
                        case TT_YEAR:
                                if (!int_from_string(tok, &result.thedate.year))
                                {
                                        result.success = FALSE;
                                        return result;
                                }
                                break;
                }
                /* extract the next token and keep a count of how many extracted
                 */
                tok = strtok(NULL, "/");
                ++tok_count;
        }
        /* check that this is a valid date */
        if (tok_count != DATE_TOKENS ||
            !valid_day(result.thedate.day, result.thedate.month) ||
            !valid_month(result.thedate.month) ||
            !valid_year(result.thedate.year))
        {
                fprintf(stderr, "Error: %s is not a valid date.\n", input);
                result.success = FALSE;
        }
        else
        {
                /* otherwise all is good so we set the success value to true */
                result.success = TRUE;
        }
        free(copy);
        return result;
}

/**
 * prints out the date in string format
 **/
void print_date(const struct date* thedate)
{
        /* the months os the year as an array of strings - makes it easy to
         * covert from numbers to strings */
        char* months[] = { "January",   "February", "March",    "April",
                           "May",       "June",     "July",     "August",
                           "September", "October",  "November", "December" };
        /* do the printing out - note that as we have a pointer to a struct we
         * must use the -> operator rather than the . */
        printf("The date is: %d %s %d\n", thedate->day,
               months[thedate->month - 1], thedate->year);
}

int main(int argc, char* argv[])
{
        /* the date structure for converting from string to date */
        struct validatable_date thedate;
        /* validate command line args */
        if (argc != NUMARGS)
        {
                fprintf(stderr, "Error: incorrect number of arguments. Please "
                                "enter a date delimited by the / character.\n");
                return EXIT_FAILURE;
        }
        /* extract the date */
        thedate = get_date(argv[DATEARG]);
        if (!thedate.success)
        {
                return EXIT_FAILURE;
        }
        /* print it */
        print_date(&thedate.thedate);
        return EXIT_SUCCESS;
}
