#include "shared.h"
#include <limits.h>

#ifndef UTILITY_H
#define UTILITY_H
enum input_result
{
        IR_FAILURE, IR_SUCCESS, IR_RTM
};

#define HAS_NL(STR) ((STR)[strlen(STR)-1] == '\n')
#define REMOVE_NL(STR) ((STR)[strlen(STR)-1]) = 0
#define LINELEN 80
#define EXTRA_CHARS 2
#define DECIMAL 10

void read_rest_of_line(void);
enum input_result get_int_from_user(const char *, int *);
enum input_result get_string_from_user(const char *, char *,int);
BOOLEAN extract_move(struct move *,char *);
void unputc(FILE*);
struct location location_add(struct location, struct location);
#endif /* UTILITY_H */
