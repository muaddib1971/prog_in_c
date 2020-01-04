#include <stdio.h>
#include <stdlib.h>

struct name {
    char *first, *second;
};

void assign_names(struct name* names[]) {
    char lasts[3][10] = {"Mitchell", "Wood", "Holloway"};
    char firsts[3][10] = {"Kevin", "Briony", "Patrick"};
    int count;
    for (count = 0; count < 3; ++count) {
        names[count] = malloc(sizeof(struct name));
        if (!names[count]) {
            perror("malloc");
        }
        names[count]->first = firsts[count];
        names[count]->second = lasts[count];
    }
}

void print_names(struct name* thenames[]) {
    int count;
    for (count = 0; count < 3; ++count) {
        printf("%s %s\n", thenames[count]->first, thenames[count]->second);
    }
}

int main() {
    struct name* thenames[3];

    assign_names(thenames);
    print_names(thenames);
    return EXIT_SUCCESS;
}
