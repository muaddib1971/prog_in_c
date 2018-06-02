#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "safemalloc.h"
#include "matrix.h"

#define WIDTH 4
#define HEIGHT 500

int main(void)
{
        struct matrix *mymat;
        /* allocate a matrix with random numbers of the width and height
         * specified */
        mymat = rand_matrix(WIDTH, HEIGHT);
        print_matrix(mymat);
        free_matrix(mymat);
        return EXIT_SUCCESS;
}

/***************************************************************************
* initialise the matrix - because all elements need to be set to 0 the
* easiest way is with memset.
***************************************************************************/
void matrix_init(struct matrix *matrix)
{
        memset(matrix, 0, sizeof(struct matrix));
}

/***************************************************************************
* initialise the matrix according to the dimensions passed in.
***************************************************************************/
struct matrix *rand_matrix(const unsigned width, const unsigned height)
{
        struct matrix *mymat = safemalloc(sizeof(struct matrix));
        unsigned wcount, hcount;
        matrix_init(mymat);
        /* initialise the random seed */
        srand(time(NULL));
        /* allocate space for the first dimension */
        mymat->array = safemalloc(height * sizeof(int *));

        for (hcount = 0; hcount < height; ++hcount)
        {
                /* allocate space for the second dimension */
                mymat->array[hcount] = safemalloc(width * sizeof(int));
                /* assign random numbers for each column */
                for (wcount = 0; wcount < width; ++wcount)
                {
                        mymat->array[hcount][wcount] = rand();
                }
        }
        mymat->width = width;
        mymat->height = height;
        return mymat;
}

/***************************************************************************
* print_matrix() : print out the rows and columns of the matrix
***************************************************************************/
void print_matrix(struct matrix *matrix)
{
        unsigned wcount, hcount;
        for (wcount = 0; wcount < matrix->width; ++wcount)
        {
                printf("\n");
                for (hcount = 0; hcount < matrix->height; ++hcount)
                {
                        printf("%d\t", matrix->array[hcount][wcount]);
                }
        }
        printf("\n");
}

/***************************************************************************
* free all the memory for the matrix - free each column and then free the
* rows in one go.
***************************************************************************/
void free_matrix(struct matrix *matrix)
{
        unsigned hcount;
        /* free each column */
        for (hcount = 0; hcount < matrix->height; ++hcount)
        {
                free(matrix->array[hcount]);
        }
        /* free the rows */
        free(matrix->array);
        /* free the pointer itself as it was dynamically allocated */
        free(matrix);
}
