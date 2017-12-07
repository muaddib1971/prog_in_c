#include <stdio.h>
#include <stdlib.h>


void doit()
{
}

int main(void)
{
    int ch;
    doit();
    /* while the user has not pressed ctrl-d, keep on receiving characters*/
    /* note that the input is not processed until the enter key has been
     * pressed
     */
    while (ch=getchar(), ch != '\n' && ch != EOF)
    {
        putchar(ch);
    }
    return EXIT_SUCCESS;
}
