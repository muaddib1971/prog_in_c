/****************************************************************************
* Steven Burrows
* sdb@cs.rmit.edu.au
* updated by Paul Miller Paul.Miller@rmit.edu.au
* getString-advanced.c
*
* This program demonstrates a reusable function for accepting strings with
* dynamic memory allocation.
* If you wish to use this code, you must acknowledge it for plagiarism 
* reasons.
*
* Created June 2006 updated December 2015.
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_LENGTH 5
#define PROMPT_LENGTH 80
#define EXTRACHARS 2

typedef enum {FALSE, TRUE} BOOLEAN;

void readRestOfLine(void);
BOOLEAN getString(char*, const unsigned, const char*);

int main(void)
{
   char string[INPUT_LENGTH + 1];/* +1 for the nul terminator */
   char prompt[PROMPT_LENGTH + 1];

   sprintf(prompt, "Enter a string (max %d characters): ", INPUT_LENGTH);

   getString(string, INPUT_LENGTH, prompt);

   printf("You entered: '%s'\n", string);

   return EXIT_SUCCESS;
}


/****************************************************************************
* getString(): An interactive string input function with dynamic memory.
* This function prompts the user for a string using a custom prompt. A line
* of text is accepted from the user using fgets() and stored in a temporary
* string. When the function detects that the user has entered too much text,
* an error message is given and the user is forced to reenter the input. The
* function also clears the extra text (if any) with the readRestOfLine()
* function.
*
* When a valid string has been accepted, the unnecessary newline character
* at the end of the string is overwritten. Finally, the input string is
* copied to the char pointer passed in so that is availableto the calling 
* function.
****************************************************************************/
BOOLEAN getString(char* string, const unsigned length, const char* prompt)
{
   int finished = FALSE;
   char* input;

   /* Allocate temporary memory. */
   if ((input = malloc(sizeof(char) * (length+EXTRACHARS))) == NULL)
   {
      fprintf(stderr, "Fatal error: malloc() failed in getString().\n");
      exit(EXIT_FAILURE);
   }

   /* Continue to interact with the user until the input is valid. */
   do
   {
      /* Provide a custom prompt. */
      printf("%s", prompt);
      
      /* Accept input. "+2" is for the \n and \0 characters. */
      fgets(input, length + EXTRACHARS, stdin);

      /* A string that doesn't have a newline character is too long. */
      /* the newline character is appended by fgets to indicate that 
       * the whole contents of the input buffer has been copied to the 
       * string
       */
      if (input[strlen(input) - 1] != '\n')
      {
         printf("Input was too long.\n");
         readRestOfLine();
      }
      else
      {
         finished = TRUE;
      }

   } while (finished == FALSE);

   /* Overwrite the \n character with \0. */
   input[strlen(input) - 1] = '\0';
   
   /* Make the result string available to calling function. */
   strcpy(string, input);
   
   /* Deallocate temporary memory. */
   free(input);

   return TRUE;
}


/****************************************************************************
* readRestOfLine(): A function for buffer handling.
* This function reads remaining characters in the standard input buffer
* up to the next newline or EOF. Source:
* https://inside.cs.rmit.edu.au/~sdb/teaching/C-Prog/CourseDocuments/
* FrequentlyAskedQuestions/#alternative
****************************************************************************/
void readRestOfLine()
{
   int c;

   /* read until the end of the line or end-of-file */   
   while ((c = fgetc(stdin)) != '\n' && c != EOF)
      ;

   /* clear the error and end-of-file flags */
   clearerr(stdin);
}
