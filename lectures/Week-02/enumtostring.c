#include <stdio.h>
#include <stdlib.h>
/**
 * The purpose of this program is to provide a mapping from an enumeration
 * to a string value. Remember that enumerations are by default
 * numbered from 0 upwards so FIFTH in the below enumeration is actually
 * 4
 */
/* enumeration of values */
enum options
{
    FIRST,SECOND,THIRD,FOURTH, FIFTH
}; 
/* array of strings to map from enumeration to output string*/
char* names[] = {"First", "Second", "Third", "Fourth", "Fifth"};

int main(void)
{
    enum options opt=3;
    printf("%s\n", names[opt]);
    return EXIT_SUCCESS;
}
