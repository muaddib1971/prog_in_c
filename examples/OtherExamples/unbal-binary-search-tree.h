/*
 * IntCollection -- unbalanced binary search tree implementation
 *
 */

#define MAXSIZE 32768

#define SUCCESS 1
#define FAILURE 0

typedef struct intnode * IntNodePtr;

typedef struct intnode
{
   int num;
   IntNodePtr left, right;
} IntNode;

typedef struct
{
   IntNodePtr root;
   int numInts;

} IntCollection;

int MakeCollection(IntCollection*);
void FreeCollection(IntCollection*);
int AddCollection(IntCollection*, int);
int SearchCollection(IntCollection*, int);
int SizeCollection(IntCollection*);
void DisplayCollection(IntCollection*);

