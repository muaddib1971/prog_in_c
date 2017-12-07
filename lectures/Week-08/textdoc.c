#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "textdoc.h"
#include "safemalloc.h"

int main(int argc, char * argv[])
{
    FILE * in=NULL;
    /* we use bufsiz here as it gives us a nice large buffer */
    char line[BUFSIZ + EXTRACHARS];
    document newdoc;

    /* test command line arguments */
    if(argc != NUM_ARGS)
    {
        fprintf(stderr, "Error: Invalid arguments\n\n");
        return EXIT_FAILURE;
    }

    /* initialise our document */
    doc_init(&newdoc);

    /* try to open the file and if it fails, display an error and exit */
    if((in = fopen(argv[FILENAME], "r")) == NULL)
    {
        perror("failed to open file");
        return EXIT_FAILURE;
    }

    /* read each line from the file */
    while(fgets(line, BUFSIZ + EXTRACHARS, in) != NULL)
    {
        /* remove the newline character */
        line[strlen(line)-1]=0;
        /* add the line to the document */
        if(!doc_add(&newdoc, line))
        {
            fprintf(stderr, "Error: we were not able to add a line.\n\n");
            break;
        }
    }
    doc_print(&newdoc);
    doc_free(&newdoc);
    fclose(in);

    return EXIT_SUCCESS;
}

/******************************************************************************
* initialise the document - allocate space for the first ten pointers and 
* set other values to the correct starting points.
******************************************************************************/
void doc_init(document * doc)
{
    assert(doc);
    doc->document=safemalloc(sizeof(char*) * MINLINES);
    doc->lines_allocated=MINLINES;
    doc->lines_used=0;
}

/******************************************************************************
* add a line to our document. 
******************************************************************************/
BOOLEAN doc_add(document* doc, const char* line)
{
    /* test whether we need to allocate some more pointers */
    if(doc->lines_allocated == doc->lines_used)
    {
        /* allocate memory and test it was successful */
        void * memory= saferealloc(doc->document, doc->lines_allocated * 2 
            * sizeof(char*));
        if(!memory)
        {
            fprintf(stderr, "Error: failed to allocate memory.\n\n");
            return FALSE;
        }
        else
        {
            /* memory allocation successful - assign the pointer and record 
             * the number of lines allocated 
             */
            doc->document = memory;
            doc->lines_allocated *=2;
        }
    }
    /* allocate memory for the current line and copy the data to the document */
    doc->document[doc->lines_used]=safemalloc((strlen(line)+1) * sizeof(char));
    strcpy(doc->document[doc->lines_used++], line);
    return TRUE;
}

/******************************************************************************
* print out all the lines in the document 
******************************************************************************/
void doc_print(const document * const doc)
{
    unsigned lcount;
    for(lcount = 0; lcount < doc->lines_used; ++lcount)
    {
        printf("%s\n", doc->document[lcount]);
    }
}

/******************************************************************************
* free the memory allocated for the document
******************************************************************************/
void doc_free(document *doc)
{
    unsigned lcount;
    /* free each line of the document */
    for(lcount = 0; lcount < doc->lines_used; ++lcount)
    {
        free(doc->document[lcount]);
    }
    /* free the pointers for each line of the document */
    free(doc->document);
}
