#include "bool.h"
#include "safemalloc.h"
#define NUM_ARGS 2
#define EXTRACHARS 2
#define MINLINES 10
#define FILENAME 1 /* first argv element */

typedef struct doc
{
    char ** document;
    unsigned lines_allocated;
    unsigned lines_used;
} document;

void doc_init(document*);
BOOLEAN doc_add(document*, const char*);
void doc_print(const document * const);
void doc_free(document *);
