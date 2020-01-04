#include "utility.h"

/**
 * this function is required for buffer clearing. It simply removes all 
 * characters from the input buffer. Note: you should only call this when
 * you detect buffer overflow. 
 **/
void read_rest_of_line(void)
{
        int ch;
        while ( ch = getc(stdin), ch != '\n' && ch != EOF)
                ;
}


/**
 * prompts a user to input a string and then returns that string as an "out"
 * parameter to the function that calls this one. If ctrl-d is pressed, 
 * return IR_RTM. If the new line is missing, this has been a failure in the 
 * call to fgets() and therefore we return IR_FAILURE. Otherwise we will remove
 * the newline character and return IR_SUCCESS.
 *
 * @param prompt the string prompt to display to the user
 * @param output the output buffer to store the string read in from the user
 * @param len the length of the buffer, including terminating characters 
 * written by fgets.
 **/
enum input_result get_string_from_user(const char * prompt, char * output,
                int len)
{
        /* display the prompt */
        printf("%s", prompt);
        /* read in the string with fgets */
        if(!fgets(output, len, stdin))
        {
                /* if the string is empty return IR_RTM as this means the user
                 * has chosen to return to the main menu
                 */
                return IR_RTM;
        }
        /* test for the newline character and if it's missing, 
         * return failure */
        if(!HAS_NL(output))
        {
                fprintf(stderr, "Error: too much input was entered\n");
                read_rest_of_line();
                return IR_FAILURE;
        }
        if(*output == '\n')
        {
                return IR_RTM;
        }
        /*success - remove the newline character and return IR_SUCCESS status */
        REMOVE_NL(output);
        return IR_SUCCESS;
}

/**
 * prompts the user for input and reads it in. It then converts that input
 * to an integer, if such input is available. If there was input entered in
 * the form of a valid integer value, it is returned, otherwise a failure 
 * status is returned.
 *
 * @param prompt the prompt to display to the user
 * @param output a pointer to the integer to be sent as output to the function
 * that called this one.  
 **/
enum input_result get_int_from_user(const char * prompt, int * output)
{
        /* the buffer to hold input retrieved from the user */
        char input[LINELEN + EXTRA_CHARS];
        enum input_result result;
        long lnum;
        char * end;

        while ( result = get_string_from_user(prompt, input,
                                LINELEN + EXTRA_CHARS),
                        result == IR_FAILURE)
        {
                fprintf(stderr, "user input failed. Please try again.\n");
        }
        lnum = strtol(input, &end, DECIMAL);
        if(*end)
        {
                fprintf(stderr, "Error: %s is not a valid number.\n",
                                input);
                return IR_FAILURE;
        }
        if(lnum < INT_MIN || lnum > INT_MAX)
        {
                fprintf(stderr, "Error: %s is outside the range "
                                "of an integer\n", input);
                return IR_FAILURE;
        }
        *output = lnum;
        return IR_SUCCESS;
}

long get_next_long(char** string, char delim)
{
        static char * end;
        long num;
        num = strtol(*string, &end, DECIMAL);
        if(*end != delim)
        {
                *string = NULL;
        }
        *string = end;
        return num;
}

BOOLEAN extract_move(struct move * move, char * move_str)
{
        /* format: x,y-x,y */
        long num;
        char * iterator = move_str;
        num = get_next_long(&iterator, ',');
        if(!iterator || num < MOVE_MIN || num > MOVE_MAX|| *iterator != ',')
        {
                return FALSE;
        }
        move->start.x = num - 1;
        ++iterator;
        num = get_next_long(&iterator, '-');
        if(!iterator || num < MOVE_MIN || num > MOVE_MAX || *iterator != '-')
        {
                return FALSE;
        }
        move->start.y = num - 1;
        ++iterator;
        num = get_next_long(&iterator, ',');
        if(!iterator || num < MOVE_MIN || num > MOVE_MAX || *iterator != ',')
        {
                return FALSE;
        }
        move->end.x = num - 1;
        ++iterator;
        num = get_next_long(&iterator, '\0');
        if(!iterator || num < MOVE_MIN || num > MOVE_MAX || *iterator)
        {
                return FALSE;
        }
        move->end.y = num - 1;
        return TRUE;
}

void unputc(FILE* out)
{
        fputc('\b', out);
}

struct location location_add(struct location start, struct location loc_add)
{
        struct location result;
        result.x = start.x + loc_add.x;
        result.y = start.y + loc_add.y;
        return result;
}

