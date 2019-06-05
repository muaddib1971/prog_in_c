#include <stdio.h>
#include <stdlib.h>

typedef enum truefalse
{
        FALSE,
        TRUE
} BOOLEAN;

typedef enum side
{
        ONE,
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX
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

struct bits
{
        int i : 5; /* I is 5 bits wide */
        int j : 3; /* j is 3 bits wide */
};

#define NUM_SIDES 6
size_t array_size(dice_side *, size_t);
void struct_ptr_size(struct stuff *);
int main(void)
{
        dice_side dice[NUM_SIDES];
        struct bits somebits;
        struct stuff somestuff = { .1, .2, .3 };
        dice_side *dice_ptr = dice;
        printf("total size of dice: %lu\n", sizeof(dice));
        printf("size of a side: %lu\n", sizeof(dice_side));
        printf("size of a side: %lu\n", sizeof(enum side));
        printf("size of a side: %lu\n", sizeof(dice) / NUM_SIDES);
        printf("size of the dice_ptr: %lu\n", sizeof(dice_ptr));
        printf("size of dice from function: %lu\n",
               array_size(dice, NUM_SIDES));
        printf("size of BOOLEAN: %lu\n", sizeof(BOOLEAN));
        printf("size of struct stuff: %lu\n", sizeof(struct stuff));
        struct_ptr_size(&somestuff);
        printf("size of some bits: %lu\n", sizeof(somebits));
        return EXIT_SUCCESS;
}

size_t array_size(dice_side dice[NUM_SIDES], size_t num_sides)
{
        return sizeof(*dice) * num_sides;
}

void struct_ptr_size(struct stuff *mystuff)
{
        /* size of the pointer */
        printf("the size of the pointer is: %ld\n", sizeof(mystuff));
        /* the size of the contents */
        printf("the size of the contents is: %ld\n", sizeof(*mystuff));
        /* the actual contents */
        printf("the struct contains: %f, %f and %f.\n", mystuff->a, mystuff->b,
               mystuff->c);
}
