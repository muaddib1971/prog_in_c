#include <stdio.h>
#include <stdlib.h>

int main(void)
{
        int chr;
        for(chr='A'; chr <='Z'; ++chr)
        {
                /* shows that a char is really a small int: */
                /* actually pretty much everything is an integer
                 * under the hood in C
                 */
                printf("character: %c,ascii number(decimal): %d, "
                        "ascii number(hexadecimal): %x\n",
                        chr, chr, chr);
        }
        return EXIT_SUCCESS;
}
