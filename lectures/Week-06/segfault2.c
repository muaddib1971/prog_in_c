#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    /* segmentation fault caused by not allocating enough memory on the 
     * stack. Can you explain why the segmentation fault happens 
     * when exiting main? Could valgrind or gdb help in tracking down 
     * errors like this?
     */
    char name[10];
    strcpy(name, "hi fred, how are things?");
    printf("%s\n", name);
    return EXIT_SUCCESS;
}
