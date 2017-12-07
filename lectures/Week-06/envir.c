#include <stdio.h>
#include <stdlib.h>

#define UNUSED(x) (void) (x)

int main(int argc, char** argv, char ** envp)
{
    char ** env;
    /* getting rid of warnings for unused variables*/
    UNUSED(argc);
    UNUSED(argv);
    /* print out environment variables */
    for(env = envp; *env != NULL; ++env)
    {
        printf("%s\n", *env);
    }
    return EXIT_SUCCESS;
}
