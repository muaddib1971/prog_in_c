#include "file_process.h"
#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DECIMAL 10
#define NUM_MENU_OPTIONS 4
#define LINELEN 80

enum menu_choice
{
        SHUFFLE,
        EVERY_OTHER,
        SHIFT,
        QUIT
};

enum input_result
{
        FAILURE,
        SUCCESS,
        EMPTY
};

typedef void (*action)(char[]);
struct menu_item
{
        char title[LINELEN + 1];
        action act;
};

enum menu_choice menu(struct menu_item[]);
enum input_result get_string(char string[], int maxlen);
enum input_result get_int(int* result);
