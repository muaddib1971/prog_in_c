#include <stdio.h>
#include <stdlib.h>
size_t mystrlen(const char str[])
{
        const char* iterator = str;
        while (*(++iterator) != '\0')
                ;
        return iterator - str;
}

int main(void)
{
        char name[] = "Paul";
        printf("%ld\n", mystrlen(name));
        puts(name);
        return EXIT_SUCCESS;
}
