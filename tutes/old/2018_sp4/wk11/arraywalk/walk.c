#include <stdio.h>
#include <stdlib.h>

void array_walk(void* base, size_t size, size_t count, void (*doit)(void*))
{
        void* current;
        size_t curcount;
        for (current = base, curcount = 0; curcount < count; ++curcount)
        {
                doit(current);
                current = ((char*)current) + size;
        }
}

void addone(void* num)
{
        *((int*)num) += 1;
}

void dblnum(void* num)
{
        double* dnum = num;
        *dnum *= 2;
}

void printint(void* num)
{
        printf("%d\n", *(int*)num);
}

void printdbl(void* dbl)
{
        printf("%f\n", *(double*)dbl);
}

#if 0
    int * parray = array;
    parray += 2/* implicit multiplication of 2 by sizeof(int) */;
#endif

int main(void)
{
        int iarray[] = { 1, 3, 5, 7, 9 };
        double darray[] = { 2.5, 3.4, 7.9, 11.1, 9.7 };
        array_walk(iarray, sizeof(*iarray), sizeof(iarray) / sizeof(*iarray),
                   addone);

        array_walk(iarray, sizeof(*iarray), sizeof(iarray) / sizeof(*iarray),
                   printint);
        array_walk(darray, sizeof(double), 5, dblnum);
        array_walk(darray, sizeof(double), 5, printdbl);
        return EXIT_SUCCESS;
}
