#include "swapper.h"
/**
 * @file swapper.c contains the implementation of the @ref main function
 * for this program as well as a helper function @ref print_buffer
 **/

/**
 * @file swapper.c contains the main function for this program as well as
 * the @ref print_buffer function which prints the contents of a buffer
 **/
int main(int argc, char** argv)
{
    /* the buffers to read the files into  - note that we are assuming 
     * that each line has a maximum of LINE_LEN characters, and so 
     * this program will not work if that is not the case - we will get 
     * buffer overflow.
     */
    char firstbuffer[BUFSIZ][LINE_LEN+1];
    char secondbuffer[BUFSIZ][LINE_LEN+1];
    /* the number of lines held in each buffer */
    size_t firstsize, secondsize;
    char * firstname, *secondname;
    /* check the number of arguments is correct */
    if(argc != NUM_ARGS)
    {
        fprintf(stderr, "\nError: invalid arguments entered.\n\n");
        fprintf(stderr, "You call swapper as follows: \n");
        fprintf(stderr, "./swapper first second\n");
        fprintf(stderr, "Where first and second are the files you wish"
            " to swap the contents of.\n\n");
        return EXIT_FAILURE;
    }
    /* grab the file names whose contents we are to swap */
    firstname = argv[FIRSTFILE];
    secondname = argv[SECONDFILE];
    /* read the contents of the two files into memory */
    if(!readfile(firstname, firstbuffer, &firstsize) || 
        !readfile(secondname, secondbuffer, &secondsize))
    {
        fprintf(stderr, "Error reading a file. We will exit now.\n\n");
        return EXIT_FAILURE;
    }
    /* output the contents of each buffer to the screen */
    print_buffer(firstbuffer, firstsize);
    printf("\n\n");
    print_buffer(secondbuffer, secondsize);
    /* write the data to the files -- the first file's contents is 
     * written to the second file name and the second file's contents
     * is written to the first file name
     */
    writefile(secondname, firstbuffer, firstsize);
    writefile(firstname, secondbuffer, secondsize);
    /* all good so we indicate to the operating system that the program
     * ran correctly
     */
    return EXIT_SUCCESS;
}

/**
 * @param contents the buffer we are to print
 * @param num_lines the number of lines contained in @ref contents
 **/
void print_buffer(char contents[][LINE_LEN+1], size_t num_lines)
{
    unsigned lineno=0;
    /* iterate over the array, outputting each line. */
    const char * line=contents[lineno];
    /* print out each line until we get to the end of the array */
    while(lineno < num_lines)
    {
        puts(line);
	/* point to the next line to be printed */
        line = contents[lineno++];
    }
}
