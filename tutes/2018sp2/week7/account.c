#include "account.h"

static char* mystrdup(const char str[])
{
        char* newstr = malloc((strlen(str) + 1) * sizeof(char));
        if (!newstr)
        {
                return NULL;
        }
        strcpy(newstr, str);
        return newstr;
}
static BOOLEAN get_balance(const char balstr[], struct money* balance)
{
        char* token;
        char* balcpy = mystrdup(balstr);
        char* endptr;
        long testnum;
        token = strtok(balcpy, ".");
        if (!token)
        {
                fprintf(stderr, "Error: %s is not a valid "
                                "currency.\n",
                        balstr);
                free(balcpy);
                return FALSE;
        }
        testnum = strtol(token, &endptr, 10);
        if (*endptr)
        {
                fprintf(stderr, "Error: %s is not valid "
                                "currency.\n",
                        balstr);
                free(balcpy);
                return FALSE;
        }
        if (testnum > UINT_MAX)
        {
                fprintf(stderr, "Error: %s is not valid "
                                "currency.\n",
                        balstr);
                free(balcpy);
        }
        balance->dollars = testnum;
        token = strtok(NULL, ".");
        if (!token)
        {
                fprintf(stderr, "Error: %s is not a valid "
                                "currency.\n",
                        balstr);
                free(balcpy);
                return FALSE;
        }
        testnum = strtol(token, &endptr, 10);
        if (*endptr)
        {
                fprintf(stderr, "Error: %s is not valid "
                                "currency.\n",
                        balstr);
                free(balcpy);
                return FALSE;
        }
        if (testnum > MAXCENTS)
        {
                fprintf(stderr, "Error: %s is not valid "
                                "currency.\n",
                        balstr);
                free(balcpy);
                return FALSE;
        }
        token = strtok(NULL, ".");
        if (token)
        {
                fprintf(stderr, "Error: %s is not valid "
                                "currency.\n",
                        balstr);
                free(balcpy);
                return FALSE;
        }
        free(balcpy);
        return TRUE;
}

BOOLEAN read_account(struct account* account)
{
        char line[LINELEN + EXTRACHARS];
        struct money balance;
        if (get_string("Please enter the customer name:", line, NAMELEN) == RTM)
        {
                return FALSE;
        }
        strcpy(account->custname, line);
        if (get_string("Please enter the customer "
                       "account number:",
                       line, ACCNOLEN) == RTM)
        {
                return FALSE;
        }
        strcpy(account->accno, line);
        if (get_string("Please enter the customer balance", line, LINELEN) ==
            RTM)
        {
                return FALSE;
        }
        if (!get_balance(line, &balance))
        {
                fprintf(stderr, "Error: %s does not "
                                "contain valid currency.\n",
                        line);
                return FALSE;
        }
        account->balance = balance;
        return TRUE;
}
/*
void foo()
{
        struct account a, b;

        a.custname= "fred";
        a.accno = "111";
        a.balance.dollars = 2;
        a.balance.cents = 50;

        b = a;
}
*/

int bal_cmp(const struct account* accone, const struct account* acctwo)
{
        return (accone->balance.dollars * DOLLCENTS + accone->balance.cents) -
               (acctwo->balance.dollars * DOLLCENTS + acctwo->balance.cents);
}
