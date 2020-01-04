#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( void )
{
	int ints[80];
        
	int count;
        memset(ints, 0, sizeof(int) * 80);	
        for(count = 0; count < 80; ++count)
	{
		printf("%d\n", ints[count]);
	}
	return EXIT_SUCCESS;
}
