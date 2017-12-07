#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "safemalloc.h"
#define DELIMS ","
void display_vals(char*, ...);
char * mystrdup(char*);
int main(void)
{
    display_vals("int,string,int,unsigned", 45, "fred is funny", -3, 34);
    return EXIT_SUCCESS;
}

/* shows how to use stdarg.h to write a limited printf type function */
void display_vals(char * format, ...)
{
    char * tok;
    /* make a copy of the format string so we can parse it with strtok and 
     * not alter the original */
    char * fmtcpy = mystrdup(format);
    va_list args;
    /* start tokenizing the format string */
    tok = strtok(fmtcpy, DELIMS);
    /* start the processing of arguments */
    va_start(args, format);
    while(tok)
    {
        /* is the next element an int? */
        if(!strcmp(tok, "int"))
        {
            printf("got an int with the value: %d\n", va_arg(args, int));
        }
        /* is the next element a string */
        else if(!strcmp(tok, "string"))
        {
            printf("got a string with the value: %s\n", va_arg(args, char*));
        }
        /* is the next element an unsigned integer ? */
        else if(!strcmp(tok, "unsigned"))
        {
            printf("got an unsigned with the value: %u\n", va_arg(args, unsigned));
        }
        /* oops, there was an error in the format string */
        else
        {
            fprintf(stderr, "Error: type not matched\n");
        }

        tok = strtok(NULL, DELIMS);
    }
    /* perform cleanup - reset the args and free the malloced string */
    va_end(args);
    free(fmtcpy);
}

/* a drop-in replacement for strdup as strdup is not ansi c */
char * mystrdup(char* str)
{
    unsigned len = strlen(str);
    char * copy = safemalloc((len+1) * sizeof(char));
    
    strcpy(copy, str);
    return copy;
}
