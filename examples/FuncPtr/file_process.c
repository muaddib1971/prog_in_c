#include "file_process.h"

/**
 * function that opens the filename specied, shuffles the chars in each line and
 * then writes them to the filename spedified with a .shuffled suffix
 **/
void shuffle(char name[])
{
        int line_count, num_lines;
        char* lines[BUFSIZ];
        char* newname;
        char* suffix = ".shuffled";

        /* seed the random number generator - this should be done exactly once
         * on each run */
        srand(time(NULL));
        /* read the file */
        num_lines = read_file(name, lines);
        if (num_lines == EOF)
        {
                return;
        }
        /* iterate over the lines in the file */
        for (line_count = 0; line_count < num_lines; ++line_count)
        {
                char* line = lines[line_count];
                int char_count;
                int len = strlen(line);
                /* iterate over the first half of the string and pick a
                 * random place to swap the char with and then swap it
                 */
                for (char_count = 0; char_count < len / 2; ++char_count)
                {
                        int newloc;
                        char temp;
                        newloc = rand() % len;
                        temp = line[newloc];
                        line[newloc] = line[char_count];
                        line[char_count] = temp;
                }
        }
        /* concatenate the .shuffle suffix onto the end of the string */
        newname = malloc((strlen(name) + strlen(suffix) + 1) * sizeof(char));
        if (!newname)
        {
                perror("malloc save name failed");
                free_lines(lines, num_lines);
        }
        strcpy(newname, name);
        strcat(newname, suffix);
        /* save the new contents of the file to a new file name */
        if (!write_file(newname, lines, num_lines))
        {
                fprintf(stderr, "Error: failed to save the file.\n");
        }
        /* free the memory */
        free_lines(lines, line_count);
        printf("successfully saved %s\n", newname);
        free(newname);
}
#define MINEVENLEN 1
/**
 * prints out every second character on a line from one file into a second
 * file.
 **/
void every_other(char fname[])
{
        int num_lines, line_count;
        char* lines[BUFSIZ];
        char* newname;
        char* suffix = ".evenchars";

        /* open and read the file into memory */
        num_lines = read_file(fname, lines);
        if (num_lines == EOF)
        {
                return;
        }
        for (line_count = 0; line_count < num_lines; ++line_count)
        {
                char* old_line = lines[line_count];
                int old_len = strlen(old_line);
                int new_len = old_len / 2;
                char* newline;
                int char_count;
                /* if the old line is less than 2 chars long, there is no data
                 * to write */
                if (old_len <= MINEVENLEN)
                {
                        continue;
                }
                /* allocate space for the new line */
                newline = (char*)malloc(sizeof(char) * (new_len + 1));
                if (!newline)
                {
                        perror("malloc failed");
                        free_lines(lines, line_count);
                        return;
                }
                /* copy every other character to the second file */
                for (char_count = 0; char_count < new_len; char_count++)
                {
                        newline[char_count] = old_line[char_count * 2];
                }
                newline[char_count] = 0;
                /* free the old line and assign the new one as we have no
                 * further need of the old line */
                free(old_line);
                lines[line_count] = newline;
        }
        /* allocate space for the new file name (including suffix) and copy the
         * data in */
        newname = malloc((strlen(fname) + strlen(suffix) + 1) * sizeof(char));
        if (!newname)
        {
                perror("malloc new name failed");
                free_lines(lines, line_count);
                return;
        }
        strcpy(newname, fname);
        strcat(newname, suffix);
        /* save the data to the new file name */
        if (!write_file(newname, lines, num_lines))
        {
                fprintf(stderr, "Error: failed to save the file.\n");
        }
        /* free the memory allocated */
        free_lines(lines, line_count);
        printf("successfully saved %s\n", newname);
        free(newname);
}

/**
 * adds one to each char value and saves the modified data to the new file name
 * with the '.shifted' suffix
 **/
void shift(char fname[])
{
        char* lines[BUFSIZ];
        char* newname;
        char* suffix = ".shifted";
        int num_lines;
        int line_count;

        /* load the data into the lines array */
        num_lines = read_file(fname, lines);
        if (num_lines == EOF)
        {
                return;
        }
        /* iterate over each line */
        for (line_count = 0; line_count < num_lines; ++line_count)
        {
                char* curr = lines[line_count];
                /* iterate over each char in the line */
                while (*curr)
                {
                        /* increment the char value for each char in the array
                         */
                        (*curr)++;
                        curr++;
                }
        }
        /* allocate space for the new file name, including prefix */
        newname = malloc(sizeof(char) * (strlen(fname) + strlen(suffix) + 1));
        if (!newname)
        {
                perror("allocation failed for filename");
                return;
        }
        /* copy the new file name */
        strcpy(newname, fname);
        strcat(newname, suffix);
        /* save the data to the new file name */
        if (!write_file(newname, lines, num_lines))
        {
                fprintf(stderr, "Error: failed to save file.\n");
        }
        /* free all memory */
        free_lines(lines, num_lines);
        printf("successfully saved %s\n", newname);
        free(newname);
}

/**
 * quit the application
 **/
void quit(char linep[])
{
        /* ignore the parameter - this gets rid of the compiler warning */
        /* please note that this is only acceptable when in function pointers,
         * you have to use a single interface for all functions but the
         * parameter
         * may not be used for some functions, such as here
         */
        (void)linep;
        exit(EXIT_SUCCESS);
}

/**
 * reads a file into memory
 **/
int read_file(const char fname[], char* lines[])
{
        int count = 0;
        FILE* reader;
        char line[BUFSIZ + EXTRACHARS];

        /* open the file */
        reader = fopen(fname, "r");
        if (!reader)
        {
                perror("open failed");
                return EOF;
        }
        /* read each line from the file */
        while (fgets(line, BUFSIZ + EXTRACHARS, reader))
        {
                char* new;
                /* if we have buffer overflow, free the list, display an
                 * error and exit.
                 */
                if (line[strlen(line) - 1] != '\n')
                {
                        int freecount;
                        fprintf(stderr, "Error: line too long.\n");
                        for (freecount = 0; freecount < count; ++count)
                        {
                                free(lines[freecount]);
                        }
                        return EOF;
                }
                /* copy the string into memory where we can add it to the list
                 */
                new = malloc(sizeof(char) * (strlen(line) + 1));
                strcpy(new, line);
                /* add the new string to the list */
                lines[count++] = new;
        }
        return count;
}

/**
 * save the file contents specified in the lines variable to the filename
 * specified in the fname variable.
 **/
BOOLEAN write_file(const char fname[], char* lines[], int num_lines)
{
        int line_count;
        FILE* writer;

        /* open the file for writing */
        writer = fopen(fname, "w");
        if (!writer)
        {
                perror("opening file for writing");
                return FALSE;
        }
        /* iterate over the lines and try to save each line to the file */
        for (line_count = 0; line_count < num_lines; ++line_count)
        {
                if (fprintf(writer, "%s\n", lines[line_count]) <= 0)
                {
                        fprintf(stderr, "Error writing to the file.\n");
                        return FALSE;
                }
        }
        /* all done, close the file */
        fclose(writer);
        return TRUE;
}

/**
 * iterate over the lines that have been allocated and free each line
 **/
void free_lines(char* lines[], int num_lines)
{
        int line_count;
        for (line_count = 0; line_count < num_lines; ++line_count)
        {
                free(lines[line_count]);
        }
}
