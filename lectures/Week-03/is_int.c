#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#define LINELEN 80
#define EXTRACHARS 2
typedef enum {FALSE, TRUE} BOOLEAN;
BOOLEAN is_int(const char *);
void readRestOfLine(void);
int main(void)
{
    char line[LINELEN+EXTRACHARS];
    while( printf("enter a number, ctrl-d to end: "), 
        fgets(line, LINELEN + EXTRACHARS, stdin)!=NULL)
    {
        char * end;
        int num;
        if(line[strlen(line)-1]!='\n')
        {
            printf("Error: buffer overflow.\n");
            readRestOfLine();
            continue;
        }
        line[strlen(line)-1]=0;
        if(is_int(line))
        {
            num=(int)strtol(line, &end, 0);
            /* sanity check that is_int() is working - should never fail */
            assert(*end==0);
            printf("%d in hexadecimal is %x\n", num, num);
        }
        else
        {
            printf("%s is not numeric.\n", line);
        }
    }
    return EXIT_SUCCESS;
}

void readRestOfLine(void)
{
    int ch;
    while(ch = getc(stdin), ch!='\n' && ch != EOF) ;
    clearerr(stdin);
}

BOOLEAN is_int(const char * s)
{
    while(*s)
    {
        if(!isdigit(*s))
            return FALSE;
        ++s;
    }
    return TRUE;
}
