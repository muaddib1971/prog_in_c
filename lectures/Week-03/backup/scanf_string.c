#include <stdio.h>
#include <stdlib.h>
#define LINELEN 80
#define EXTRA_SPACES 2
int main(void)
{
    char name[LINELEN + EXTRA_SPACES], 
        model[LINELEN + EXTRA_SPACES];

    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Please enter a car model: ");
    scanf("%s", model);
    printf("Hi %s, %s is a good car model.\n", name, model);
    return EXIT_SUCCESS;
}
