/****************************************************************************
* Steven Burrows
* sdb@cs.rmit.edu.au
* getString-basic.c
*
* This program demonstrates a reusable function for accepting strings.
* If you wish to use this code, you must acknowledge it for plagiarism 
* reasons.
*
* Created June 2006.
* Updated December 2015 by Paul Miller
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_LENGTH 5
#define PROMPT_LENGTH 80
/* the two chars at the end of a successful call to fgets - \n\0 */
#define EXTRACHARS 2
typedef enum {FALSE, TRUE} BOOLEAN;

void readRestOfLine(void);
BOOLEAN getString(char*, const unsigned, const char*);

int main(void)
{
   char string[INPUT_LENGTH + 1];
   char prompt[PROMPT_LENGTH + 1];

   sprintf(prompt, "Enter a string (max %d characters): ", INPUT_LENGTH);

   getString(string, INPUT_LENGTH, prompt);

   printf("You entered: '%s'\n", string);

   return EXIT_SUCCESS;
}


/****************************************************************************
* getString(): An interactive string input function.
* This function prompts the user for a string using a custom prompt. A line
* of text is accepted from the user using fgets() and stored in a temporary
* string. When the function detects that the user has entered too much text,
* an error message is given and the user is forced to reenter the input. The
* function also clears the extra text (if any) with the readRestOfLine()
* function.
* When a valid string has been accepted, the unnecessary newline character
* at the end of the string is overwritten. Finally, the temporary string is
* copied to the string variable that is returned to the calling function.
****************************************************************************/
BOOLEAN getString(char* output_string, const unsigned length, 
    const char* prompt)
{
   int finished = FALSE;
   char inputString[INPUT_LENGTH + EXTRACHARS];

   /* Continue to interact with the user until the input is valid. */
   do
   {
      /* Provide a custom prompt. */
      printf("%s", prompt);
      
      /* Accept input. "+2" is for the \n and \0 characters. */
      fgets(inputString, length + EXTRACHARS, stdin);

      /* A string that doesn't have a newline character is too long. */
      /* the newline character appended by fgets signifies that 
       * all the data input has been transferred to the string. 
       * If it has not, there is still some input left in the input 
       * buffer
       */
      if (inputString[strlen(inputString) - 1] != '\n')
      {
         printf("Input was too long.\n");
         readRestOfLine();
      }
      else
      {
         finished = TRUE;
      }

   } while (finished == FALSE);

   /* Overwrite the \n character with \0 as we now know that the 
    * input string has been completely transferred to our string.
    */
   inputString[strlen(inputString) - 1] = '\0';
   
   /* Make the result string available to calling function. */
   strcpy(output_string, inputString);

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
