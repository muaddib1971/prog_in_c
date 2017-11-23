/*
 *  This example program demonstrates the use of isspace(), 
 *  ispunct(), islower(), isupper(), isdigit() from the 
 *  standard C library (ctype)
 *  updated by Paul Miller December 2015
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_TEXT 32

int main(void) 
{
        char text[MAX_TEXT];
        int i=0;

        printf("\nEnter up to %d characters, press enter when done: ", 
                MAX_TEXT);
        if (fgets(text, MAX_TEXT, stdin) != NULL)
        {
                for(i=0; text[i] != '\0'; i++) 
                {
                        switch(text[i])
                        {
                                case '\n' : printf("'\\n' ");
                                            break;

                                case '\r' : printf("'\\r' ");
                                            break;

                                case '\t' : printf("'\\t' ");
                                            break;

                                default   : printf("'%c' ", text[i]);
                        }

                        if ( isspace( (text[i]) ) )
                        {
                                printf("is a white space according "
                                        "to isspace()\n");
                        }
                        if ( islower( (text[i]) ) )
                        {
                                printf("is a lower case alphabetic "
                                        "according to islower()\n");
                        }
                        else if(isupper((text[i]) ) ) 
                        {
                                printf("is an upper case alphabetic "
                                        "according to isupper()\n");
                        }
                        else if( isdigit((text[i]) ) )
                        {
                                printf("is a digit according to "
                                        "isdigit()\n");
                        }
                        else if(ispunct( (text[i]) ) )
                        {
                                printf("is a punctuation character "
                                        "according to ispunct()\n");
                        }
                }
        }
        else
        {
                printf("\nNo input fetched!\n");
        }

        return EXIT_SUCCESS;
}      

/*
 * Notes:
 * 
 * 1. The ctype macros such as isalpha() should be able to accept
 *    an int (character code) or a char parameter type some 
 *    compilers, notably gcc on Solaris, may give a warning message 
 *    like: subscript has type `char'
 *    Strictly speaking this should not happen, it appearing to
 *    be an artifact of the means of implementing the macros 
 *    as a mapping array. This is particularly the case as a char is an 
 *    integer type just smaller than an int.
 *    A safe workaround is to cast the parameter to int
 *    eg. isalpha( (int)(text[i]) )
 *
 */
