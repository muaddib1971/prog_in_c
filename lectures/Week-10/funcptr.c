#include <stdio.h>
#include <stdlib.h>

int doit(char);
int doit2(char);
int main(void)
{
        /* declaration of a pointer to a function that returns an int and
         * accepts a char */
        int (*func)(char);
        /* declaration of an array of two function pointers */
        int (*funcs[2])(char);
        /* declaration of a pointer to a function pointer and assignment
         * that takes the address of a function pointer */
        int (**myfunc)(char) = &func;
        /* assign the function pointer */
        func = doit;
        /* assignment to the array of function pointers */
        funcs[0] = func;
        funcs[1] = doit2;
        /* calling of functions pointed to - notice there is no difference
         * in whether we use a declared functioni pointer or a function
         * name (which afterall is a function pointer itself
         **/
        printf("%d\n", func('z'));
        printf("%d\n", doit('a'));
        printf("%d\n", doit2('m'));
        printf("%d\n", funcs[0](45));
        printf("%d\n", funcs[1]('g'));
        /* a pointer to a function pointer requires a deference before 
         * using the function pointer component. Notice that we require
         * brackets around the dereference due to the priority of the 
         * function call being higher than the dereference
         */
        printf("%d\n", (*myfunc)('b'));
        return EXIT_SUCCESS;
}

int doit(char ch)
{
        printf("%c\n", ch);
        return ch;
}

int doit2(char ch)
{
        return ch;
}
