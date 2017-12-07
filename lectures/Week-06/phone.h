/***************************************************************************
* header file for the phone entry type used in the phone book examples.
***************************************************************************/
#include <string.h>
#ifndef PHONE_H
#define PHONE_H
#define NAMELEN 30
#define PHONELEN 8
#define DIRECTORYSIZE 10
struct phone_entry
{
    char fname[NAMELEN+1];
    char lname[NAMELEN+1];
    char number[PHONELEN+1];
};
#endif
