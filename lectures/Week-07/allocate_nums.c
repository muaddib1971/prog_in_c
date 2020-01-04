#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
typedef enum {
    FALSE,
    TRUE
} BOOLEAN;

BOOLEAN allocate_ints(int* data, size_t num_ints) {
    data = (int*)malloc(sizeof(int) * num_ints);
    if (!data) {
        perror("failed to allocate memory");
        return FALSE;
    }
    return TRUE;
}

int main(void) {
    int* data;
    allocate_ints(data, 50);
    data[5] = 42;
    return EXIT_SUCCESS;
}
