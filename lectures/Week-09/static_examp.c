#include <stdio.h>
#include <stdlib.h>
#define IDLEN 8
char * get_id(void);
int main(void)
{
    char * id;
    unsigned count; 
    /* generate 20 ids */
    for(count = 0; count < 20; ++count)
    {
        id = get_id();
        printf("%s\n", id);
        /* free id as it was malloced */
        free(id);
    }
    return EXIT_SUCCESS;
}

/**************************************************************************
 * returns the next id number available. this is kept track of using a 
 * static id.
 *************************************************************************/
static unsigned next_id_no(void)
{
    static unsigned next_id=1;
    return next_id++;
}

/**************************************************************************
 *
 *************************************************************************/
char * get_id(void)
{
    char * next_id = malloc((IDLEN+1) * sizeof(char));
    if(!next_id)
    {
        perror("failed to allocate memory");
        return NULL;
    }
    sprintf(next_id, "%0*u", IDLEN ,next_id_no());
    return next_id;
}

