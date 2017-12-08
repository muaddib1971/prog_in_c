#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
/* int errno */
/* 0 == SUCCESS */

#define MAXNUMS 10
#define NUMARGS 2
#define FILEIND 1
#define LINELEN 80
#define EXTRACHARS 2
#define DECIMAL 10

/* use the BUFSIZ constant */
typedef enum{
    FALSE, TRUE
} BOOLEAN;

void printusage(void)
{
    /* explain what the user did wrong */
    fprintf(stderr, "Error: invalid number"
        " of arguments.\n");
    /* how to use the program */
    fprintf(stderr, "Please provide a "
        "filename to open.\n");
}

BOOLEAN strtoint(const char * str, int * num)
{
    long result; 
    char * end;
    result = strtol(str, &end, DECIMAL);
    if(*end){
        fprintf(stderr, "Error: invalid integer.\n");
        return FALSE;
    }
    if(result < INT_MIN || result > INT_MAX){
        fprintf(stderr, "Error: number out of range.\n");
        return FALSE;
    }
    *num = result;
    return TRUE;
}

#define DELIM ","
/* read line in, tokenize, convert to int and store in 
 * int array
 */
BOOLEAN read_line(FILE * in, int array[], int * amt_read)
{
    char in_line[BUFSIZ + EXTRACHARS];
    char * tok;
    int cur_ind = 0;
    if(!fgets(in_line, BUFSIZ + EXTRACHARS, in)){
        fprintf(stderr, "Error: no data to read.\n");
        return FALSE;
    }
    if(in_line[strlen(in_line)-1]!='\n'){
        fprintf(stderr, "Error: buffer overflow.\n");
        return FALSE;
    }
    in_line[strlen(in_line)-1]=0;
    tok = strtok(in_line, DELIM);
    while(tok != NULL){
        int num;
        if(!strtoint(tok, &num)){
            fprintf(stderr, "Error: invalid "
                "number in file.\n");
            return FALSE;
        }
        array[cur_ind++] = num;
        tok = strtok(NULL, DELIM);
    }
    *amt_read = cur_ind;
    return TRUE;
}

int array_sum(int array[], int num_elts)
{
    int count, sum = 0;
    for(count = 0; count < num_elts; ++count){
        sum += array[count];
    }
    return sum;
}

BOOLEAN sum_write(const char fname[], const int array[], 
    const int len, int sum)
{
    FILE * writer = fopen(fname, "w");
    int count;

    if(!writer){
        perror("failed to open file");
        return FALSE;
    }
    for(count = 0; count < len; ++count){
        if(fprintf(writer, "%d,", array[count]) <= 0){
            fprintf(stderr, "Error writing data.\n");
            return FALSE;
        }   
    }
    fprintf(writer, "%d\n", sum);
    fclose(writer);
    return TRUE;
}

int main(int argc, char** argv)
{
    int array[MAXNUMS];
    FILE * reader;
    int num_read;
    int sum;

    if(argc != NUMARGS){
        printusage();
        return EXIT_FAILURE;
    }
    reader = fopen(argv[FILEIND], "r");
    if(!reader){
        /* errno */
        if(errno == ENOENT){
            fprintf(stderr, "Error: no such file or "
                "directory.\n");
        }
        /*perror */
        else{
            perror("file could not be opened");
        }
        return EXIT_FAILURE;
    }
    if(!read_line(reader, array, &num_read)){
        return EXIT_FAILURE;
    }
    fclose(reader);
    sum = array_sum(array, num_read);
    if(!sum_write(argv[FILEIND], array, num_read, sum)){
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
