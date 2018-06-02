#include "fsupport.h"

/***************************************************************************
* graceful read open - try to open the file and if it fails, display an 
* error and exit.
***************************************************************************/
FILE * gropen(char * fname)
{
    FILE * fp;
    if((fp = fopen(fname, "r")) == NULL)
    {
        perror("failed to open file");
        exit(EXIT_FAILURE);
    }
    return fp;
}

/***************************************************************************
* graceful write open - try to open the file and if it fails, display an 
* error and exit.
***************************************************************************/
FILE* gwopen(char * fname)
{
    FILE * fp;
    if((fp=fopen(fname, "w")) == NULL)
    {
        perror("failed to open file");
        exit(EXIT_FAILURE);
    }
    return fp;
}
