#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* strdup(const char* word) {
    char* new = malloc((strlen(word) + 1) * sizeof(char));
    if (!new) {
        perror("strdup");
        return NULL;
    }
    strcpy(new, word);
    return new;
}

int main(void) {
    char* name = strdup("Paul");
    ++name;
    printf("%s\n", name);
    free(name);
    return EXIT_SUCCESS;
}
