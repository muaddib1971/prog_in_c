#include <stdio.h>
#include <stdlib.h>

#define MATRIXWIDTH 5
void matrix_sum(int mata[][MATRIXWIDTH], 
    int matb[][MATRIXWIDTH], 
    int result[][MATRIXWIDTH]);
void print_matrix(int mat[][MATRIXWIDTH]);
int main(void)
{
    int matrix[MATRIXWIDTH][MATRIXWIDTH]={
        { 0, 1, 2, 3,4 } ,
        { 2, 3, 4, 5,5 } ,
        { 4, 7, 9, 2, 0} ,
        { 9, 7, 11, 2, 3}, 
        { 5, 4, 3, 2, 1}
    };
    int othermat[MATRIXWIDTH][MATRIXWIDTH] = {
        { 0, 1, 2, 3,4 } ,
        { 2, 3, 4, 5,5 } ,
        { 4, 7, 9, 2, 0} ,
        { 9, 7, 11, 2, 3}, 
        { 5, 4, 3, 2, 1}
    };
    int summat[MATRIXWIDTH][MATRIXWIDTH] = {{0},{0},{0},{0},{0}};
    matrix_sum(matrix, othermat, summat);

    print_matrix(matrix);
    print_matrix(othermat);
    print_matrix(summat);
    return EXIT_SUCCESS;
}


void matrix_sum(int mata[][MATRIXWIDTH], 
    int matb[][MATRIXWIDTH], 
    int result[][MATRIXWIDTH])
{
    unsigned county, countx;
    for(county=0; county < MATRIXWIDTH; ++county)
    {
        for(countx=0; countx<MATRIXWIDTH; ++countx)
        {
            result[county][countx]=mata[county][countx]+
                matb[county][countx];
        }
    }
}


void print_matrix(int mat[][MATRIXWIDTH])
{
    unsigned county, countx;
    for(county = 0; county < 5; ++county)
    {
        for(countx=0; countx<5; ++countx)
        {
            printf("%d\t", mat[county][countx]);
        }
        putchar('\n');
    }
    putchar('\n');
}
