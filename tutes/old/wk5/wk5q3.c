#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
        int ch;
        int bytecount = 0;
        FILE * fp_read;
        /* check for number of args */
        fp_read = fopen(argv[1], "r");
#if 0 
        fseek(fp_read, 0, SEEK_END);
        bytecount = ftell(fp_read);
#endif
        while(ch = getc(fp_read), ch != EOF)
        {
                ++bytecount;
        }
        printf("There are %d bytes in %s\n", bytecount, argv[1]);
        fclose(fp_read);
        return EXIT_SUCCESS;
}
