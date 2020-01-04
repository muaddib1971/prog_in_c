#include "menu.h"
#define MENUSIZE 6
#define MIN_MENU 1
#define MAX_MENU MENUSIZE
static struct menu_item menu[MENUSIZE];

void menu_init(void)
{
        struct menu_item init_items[MENUSIZE] = { { "first item", first },
                                                  { "second item", second },
                                                  { "third item", third },
                                                  { "fourth item", fourth },
                                                  { "fifth item", fifth },
                                                  { "quit program", quit } };
        memcpy(menu, init_items, sizeof(struct menu_item) * MENUSIZE);
}

void choose_option(void)
{
        int count;
        int option;
        char* heading = "Choose and option";
        printf("%s\n", heading);
        PUTLINE('-', strlen(heading));
        for (count = 0; count < MENUSIZE; ++count)
        {
                printf("%d) %s\n", count + 1, menu[count].description);
        }
        if (!get_int("Please enter an option: ", &option) ||
            option < MIN_MENU || option > MAX_MENU)
        {
                fprintf(stderr, "Error in input. Please try again.\n");
                choose_option();
                return;
        }
        /* validate for a number in the allowed range */
        menu[option - 1].func();
}

void first(void)
{
        printf("%s\n", "first option");
}

void second(void)
{

        printf("%s\n", "second option");
}

void third(void)
{

        printf("%s\n", "third option");
}

void fourth(void)
{

        printf("%s\n", "fourth option");
}

void fifth(void)
{

        printf("%s\n", "fifth option");
}

void quit(void)
{
        exit(EXIT_SUCCESS);
}
