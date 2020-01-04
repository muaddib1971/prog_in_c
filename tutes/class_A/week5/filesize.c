#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    FILE* reader;
    reader = fopen(argv[1], "a");
    if (!reader) {
        perror("fopen");
        return EXIT_FAILURE;
    }
    printf("The file \"%s\" is %ld bytes.\n", argv[1], ftell(reader));

    return EXIT_SUCCESS;
}
