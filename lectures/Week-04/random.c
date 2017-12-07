#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef enum
{
    FALSE, TRUE
} BOOLEAN;

#define LINE_LEN 80
#define EXTRA_CHARS 2

void read_rest_of_line(void)
{
    int ch;
    while(ch = getchar(), ch!='\n' && ch!=EOF);
    clearerr(stdin);
}

int main(void)
{
    int num;
    unsigned guess;
    BOOLEAN guessed=FALSE;
    char line[LINE_LEN + EXTRA_CHARS];
    char * end;

    srand(time(NULL));
    num = rand()%10;
    
    printf("OK. I am thinking of a number between 0 and 9.\n\n");
    
    while(!guessed)
    {
        printf("What is it? \n\n");
        fgets(line, LINE_LEN + EXTRA_CHARS, stdin);
        if(line[strlen(line)-1]!='\n')
        {
            printf("Error: line entered was too long.\n\n");
            read_rest_of_line();
            continue;
        }
        line[strlen(line)-1]=0;
        guess = (unsigned)strtol(line, &end, 0);
        if(*end)
        {
            printf("Error: your data entry was not numeric.\n\n");
            continue;
        }
        if(guess <  num)
        {
            printf("try a higher number.\n\n");
        }
        else if(guess > num)
        {
            printf("try a lower number.\n\n");
        }
        else
        {
            guessed=TRUE;
        }
    }
    printf("Well done. You guessed the number. It was %d\n\n", num);
    return EXIT_SUCCESS;
}
