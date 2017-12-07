#include <stdio.h>
#include <stdlib.h>

#ifdef DEBUG
#define GETC fgetc
#define PUTC fputc
#else
#define GETC getc
#define PUTC putc
#endif

int main(void)
{
    int ch;
    while(ch=GETC(stdin), ch!=EOF)
        PUTC(ch, stdout);
    return EXIT_SUCCESS;
}
