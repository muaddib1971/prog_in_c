#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getstring(const char prompt[], char string[])
{
        char* result;

        puts(prompt);
        printf("%s", prompt);
        result = fgets(string, 80 + 2, stdin);
        if (!result)
        {
                return NULL;
        }
        if (string[strlen(string) - 1] != '\n')
        {
                /* buffer overflow - call readrestofline */
                return getstring(prompt, string);
        }
        string[strlen(string) - 1] = 0;
        return string;
}

int main(void)
{
        char string[80 + 2];
        getstring("Hi Everyone", string);

        printf("%s\n", string);
        return EXIT_SUCCESS;
}
