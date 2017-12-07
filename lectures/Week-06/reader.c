#include <stdio.h>
#include <stdlib.h>
#include "fsupport.h"
#include "phone.h"

int load(struct phone_entry*, FILE*);
void print_book(struct phone_entry*, int);
typedef enum { FNAME, LNAME, NUMBER } token_number;
#define NUMTOKENS 3
#define READER 1

int main(int argc, char** argv)
{
    FILE *fpRead;
    struct phone_entry list[DIRECTORYSIZE];
    int result;

    /* zero out the array so it is fully initialised */
    memset(list, sizeof(struct phone_entry) * DIRECTORYSIZE, 0);

    /* check for the correct number of command line arguments */
    if(argc != 2)
    {
        fprintf(stderr, "Error: invalid arguments.\n\n");
        return EXIT_FAILURE;
    }
    /* open the input file */
    fpRead = gropen(argv[READER]);
    /* load the data and handle errors */
    result = load(list, fpRead);
    fclose(fpRead);
    if(result <= 0)
    {
        fprintf(stderr, "Error: failed to load data.\n\n");
        return EXIT_FAILURE;
    }
    /* print out the data */
    print_book(list, result);
    return EXIT_SUCCESS;
}

/*****************************************************************************
* load data in from disk. 
*****************************************************************************/
int load(struct phone_entry* entries, FILE* fpRead)
{
    size_t nelts;
    if(fread(&nelts, sizeof(size_t), 1, fpRead) != 1 || 
        fread(entries, sizeof(struct phone_entry), nelts, fpRead) != nelts)
        return EOF;
    return nelts;
}

/***************************************************************************
* print out the data in the phone book.
***************************************************************************/
void print_book(struct phone_entry* entries, int num_entries)
{
    unsigned count; 
    /* document our assumption that the array has already been 
     * processed already
     */
    assert(num_entries > 0);
    /* print out each entry */
    for(count = 0; count < (unsigned)num_entries; ++count)
    {
        printf("%s\t%s\t%s\n", entries[count].fname, entries[count].lname,
            entries[count].number);
    }
}
