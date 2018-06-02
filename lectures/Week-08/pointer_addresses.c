#include <stdlib.h>
#include <stdio.h>

int main()
{
        int *array = malloc(5 * sizeof(int));

        printf("array value: %p\n\n", (void *)array);

        printf("array addr: %p\n", (void *)&array);

        free(array);
        return EXIT_SUCCESS;
}
