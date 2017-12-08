#include "player.h"
#include "scoreboard.h"
#include "game.h"
#ifndef MENU_H
#define MENU_H
/* enumeration representing all the options that can be chosen from
 * the main menu
 */
enum menu_choice
{
        MC_PLAY=1, MC_DISPLAY, MC_QUIT, MC_INVALID = -1
};
#define MENU_STR_LEN 13
typedef struct player * (*playfunc)();

struct menu_item
{
        enum menu_choice number;
        char string[MENU_STR_LEN + 1];
        playfunc func;
};

/* how many choices are there from the main menu */
#define NUM_CHOICES 3
/* what's the minimum choice that can be entered */
#define MIN_CHOICE 1
/* what's the maximum choice that can be entered */
#define MAX_CHOICE 3

BOOLEAN init_menu(struct menu_item[]);
struct menu_item get_menu_func(struct menu_item[]);
struct player * quit(void);
#endif
