#include <stdio.h>
#include <time.h>
#include <stdlib.h>
enum coin_side
{
        HEADS,
        TAILS
};

#define NUM_COIN_SIDES 2

const char *coins_strings[] = { "heads", "tails" };

#define COIN_COUNT 5

#if 0
int coin_toss()
{
        return rand() % NUM_COIN_SIDES;
}
#endif

#define COIN_TOSS() (rand() % NUM_COIN_SIDES)

int main(void)
{
        int tosses[COIN_COUNT];
        int toss_count;
        srand(time(NULL));
        for (toss_count = 0; toss_count < COIN_COUNT; ++toss_count)
        {
                tosses[toss_count] = COIN_TOSS();
        }
        printf("You tossed the following: ");
        for (toss_count = 0; toss_count < COIN_COUNT; ++toss_count)
        {
                printf("%s,", coins_strings[tosses[toss_count]]);
        }
        printf("\b \n");
        return EXIT_SUCCESS;
}
