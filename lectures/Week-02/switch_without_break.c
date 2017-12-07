#include <stdio.h>
#include <stdlib.h>
int main()
{
        int something;
        for(something = 1; something < 3; ++something)
        {
                switch(something)
                {
                        case 1:
                                printf("moo\n");
                        case 2:
                                printf("cow\n");
                        case 3: 
                                printf("grass\n");

                }
        }
        return EXIT_SUCCESS;
}
