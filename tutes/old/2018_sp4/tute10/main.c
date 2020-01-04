#include "menu.h"

int main(void)
{
        menu_init();
        while (TRUE)
        {
                choose_option();
        }
        return EXIT_SUCCESS;
}
