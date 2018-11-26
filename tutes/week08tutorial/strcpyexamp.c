#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
        char dest[82];
        char* src = "foo";
        strcat(strcpy(dest, src), "bar");
        printf("%s\n", dest);
        return EXIT_SUCCESS;
}
