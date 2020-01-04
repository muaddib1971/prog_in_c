#include <stdio.h>
#include <stdlib.h>

char* getname(void);

int main(void)
{
        char* player1, *player2;

        player1 = getname();
        player2 = getname();

        printf("the players are: %s and %s.\n", player1, player2);
        return EXIT_SUCCESS;
}

char* getname(void)
{
        static char buffer[81];
        printf("please enter your name: ");
        fgets(buffer, 81, stdin);
        return buffer;
}
