#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void process_numbers(unsigned, ...);
int main(void)
{
    int num1=5, num2=9, num3=42,num4=-10;
    process_numbers(4, num1, num2, num3, num4);
    return EXIT_SUCCESS;
}

void process_numbers(unsigned argcount, ...)
{
    va_list args;
    unsigned count;
    int total=0;

    va_start(args, argcount);
    for(count=0; count < argcount; ++count)
    {
        int num = va_arg(args, int);
        printf("the next number is %d\n", num);
        total += num;
    }
    printf(" and the sum is %d\n", total);
    va_end(args);
}
