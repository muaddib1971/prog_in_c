#include "funcptrs.h"

typedef enum
{
        FALSE,
        TRUE
} BOOLEAN;

void hello(void)
{
        puts("hello");
}

void goodbye(void)
{
        puts("goodbye");
}

void go_away(void)
{
        puts("please go away");
}

void quit(void)
{
        exit(EXIT_SUCCESS);
}

void display_menu(struct menu_item items[], int size)
{
        int count;
        for (count = 0; count < size; ++count)
        {
                printf("%d) %s\n", count + 1, items[count].text);
        }
}

int main(void)
{
        struct menu_item menu[4] = { { "say hello", hello },
                                     { "say goodbye", goodbye },
                                     { "please go away", go_away },
                                     { "quit", quit } };
        BOOLEAN quit = FALSE;
        while (!quit)
        {
                char line[80 + 2];
                int choice;
                display_menu(menu, 4);
                printf("Enter a number: ");
                fgets(line, 80 + 2, stdin);
                choice = strtol(line, NULL, 10);
                --choice;
                printf("calling %s\n", menu[choice].text);
                menu[choice].messenger();
        }
        return EXIT_SUCCESS;
}
