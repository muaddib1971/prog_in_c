#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FAIL 0
#define LINE_LEN 80
#define MAX_LINES 20000
#define EXTRA_SPACES 2
#define INPUT_FILE "words.txt"
#define FORMAT_LEN 5
typedef enum
{
    FALSE,TRUE
} BOOLEAN;



unsigned load(char * fname, char lines[][LINE_LEN+1]);
void printarray(char[][LINE_LEN+1],unsigned);
unsigned find_longest(char lines[][LINE_LEN+1], unsigned height);
void putline(unsigned length);
