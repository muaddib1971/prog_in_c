#include "safemalloc.h"
/* safe memory allocation function */
void * safe_malloc(size_t size, unsigned long line)
{
    void * result;
    /* allocate memory*/
    result = malloc(size);
    /* test that allocation was successful */
    if(!result /* or result==NULL */)
    {
        /* if the allocation was not successful, display an error and 
         * exit
         */
        perror("failed to allocate memory");
        fprintf(stderr, "on line %ld\n", line);
        exit(EXIT_FAILURE);
    }
    /* if successful return the memory */
    return result;
}

/* safe memory allocation function using calloc */
void * safe_calloc(size_t nmem, size_t size, unsigned long line)
{
    void * result;
    /* try to allocate memory */
    result = calloc(nmem, size);
    /* test that it was successful */
    if(!result)
    {
        /* if the memory allocation failed, display a message and 
         * exit the program
         */
        perror("failed to allocate memory");
        fprintf(stderr, "on line %ld\n", line);
        exit(EXIT_FAILURE);
    }
    return result;
}

/* safe memory allocation function using a pointer to the memory to be 
 * allocated
 */
void safe_ptr_malloc(void ** memory, size_t size, unsigned long line)
{
    void * allocation;
    /* try to allocate the memory */
    allocation = malloc(size);
    if(!allocation)
    {
        /* if memory allocation failed, display an error and 
         * exit the program
         */
        perror("failed to allocate memory");
        fprintf(stderr, "on line %ld\n", line);
        exit(EXIT_FAILURE);
    }
    /* if memory allocation was successful, assign to the output 
     * memory address
     */
    *memory=allocation;
}

void * safe_realloc(void* memory, size_t newsize, unsigned long lineno)
{
    void * newmem=NULL;
    assert(memory);

    newmem = realloc(memory, newsize);
    if(!newmem)
    {
        perror("failed to allocate memory");
        fprintf(stderr, "the line that caused this problem was %ld\n", lineno);
        return NULL;
    }
    return newmem;
}
