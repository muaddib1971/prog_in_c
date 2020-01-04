#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "io.h"

#ifndef MENU_H
#define MENU_H

struct menu_item
{
        char description[80 + 1];
        void (*func)(void);
};

void menu_init(void);

void choose_option(void);

void first(void);
void second(void);
void third(void);
void fourth(void);
void fifth(void);
void quit(void);

#endif
