#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* in this program we show an example of using a typedef to rename
 * a type in c and use that type in the place of the original type
 */

/* here we define a type called a string that is a fixed size array 
 * of 80 char. We can now use the string type to define an array
 * of 80 char anywhere we like. 
 */
typedef char string[80];
int main(void)
{
    /* we define a string called 'name' and initialise it with my 
     * name
     */
    string name;
    strcpy(name, "Paul");
    /* notice that we can now use this string with puts as it is, afterall
     * a char pointer
     */
    puts(name);
    return EXIT_SUCCESS;
}
