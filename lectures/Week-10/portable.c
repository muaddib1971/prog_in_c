#include <stdio.h>
#include <stdlib.h>

int main(void)
{
#ifdef __linux
    printf("We are running linux\n\n");
#elif defined(WIN32) || defined(_WIN32) || defined(__WIN32) && \
    !defined(__CYGWIN__)
    printf("We are running windows\n\n");
#elif defined(sun) && defined(__srv4__)
    printf("We are running Solaris\n\n");
#endif
    return EXIT_SUCCESS;
}

