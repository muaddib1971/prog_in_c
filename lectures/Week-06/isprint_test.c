#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    /* the ctype header file provides many function to test and convert
     * the data type of variables. Here we demonstrate some of these.
     */

    /* why is ch an int here? */
    int ch;
    printf("\nEnter printable: ");
    while(isprint(ch=getchar()) && ch != EOF && ch != '\n')
        putchar(ch);
    printf("\nEnter digits: ");
    while(isdigit(ch=getchar()) && ch != EOF && ch != '\n')
        putchar(ch);   
    printf("\nEnter alphabetical: ");
    while(isalpha(ch=getchar()) && ch != EOF && ch != '\n')
        putchar(ch);   
    printf("\nEnter enter alphanumeric: ");
    while(isalnum(ch=getchar()) && ch != EOF && ch != '\n')
        putchar(ch);   
    printf("\nEnter lower case: ");
    while(islower(ch=getchar()) && ch != EOF && ch != '\n')
        putchar(ch);   
    printf("\nEnter upper case: ");
    while(isupper(ch=getchar()) && ch != EOF && ch != '\n')
        putchar(ch);
    putchar('\n');
    return EXIT_SUCCESS;
}
