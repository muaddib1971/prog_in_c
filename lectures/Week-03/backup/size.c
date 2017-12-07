#include <stdio.h>
#include <stdlib.h>

typedef enum truefalse
{
    FALSE, TRUE
} BOOLEAN;

typedef enum side
{
    ONE, TWO, THREE, FOUR, FIVE, SIX
} dice_side;

/* change the type here to change the size of each element 
 * of the struct
 */

typedef double type;

struct stuff
{
    type a;
    type b;
    type c;
};

#define NUM_SIDES 6

int main(void)
{
    dice_side dice[NUM_SIDES];
    dice_side * dice_ptr = dice;
    printf("total size of dice: %lu\n", sizeof(dice));
    printf("size of a side: %lu\n", sizeof(dice_side));
    printf("size of a side: %lu\n", sizeof(dice)/NUM_SIDES);
    printf("size of the dice_ptr: %lu\n", sizeof(dice_ptr));
    printf("size of BOOLEAN: %lu\n", sizeof(BOOLEAN));
    printf("size of struct stuff: %lu\n", sizeof(struct stuff));
    return EXIT_SUCCESS;
}

