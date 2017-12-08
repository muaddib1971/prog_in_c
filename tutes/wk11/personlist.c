#include "personlist.h"


int main(void)
{
    char line[LINELEN + EXTRACHARS];
    char fname[NAMELEN+EXTRACHARS];
    char lname[NAMELEN+EXTRACHARS];
    unsigned age;
    long lage; /* variable to assign the results from strtol to in 
                * order to test that it is within the allowed range */
    char * end;
    BOOLEAN success;
    BOOLEAN quit=FALSE;
    struct person * myperson;
    struct list list;
    /* initialise the list to a safe state */
    list_init(&list, person_cmp, person_free);

    /* do a while loop using a terminating condition variable. 
     * while(1) or while(TRUE) is a bad habit.
     * while there are more people to enter, keep on asking.
     */
    while(!quit)
    {
        /* get input from the user */
        success=FALSE;
        while(!success)
        {
            printf("Enter the person's first name: ");
            if(fgets(fname, NAMELEN+EXTRACHARS, stdin) == NULL
                    || *fname=='\n')
            {
                /* if the user has pressed ctrl-d or enter on a new
                 * line, we quit */
                quit=TRUE;
                break;
            }
            if(fname[strlen(fname)-1]=='\n')
            {
                /* remove the newline character as we now know that we got
                 * all the data in the buffer
                 */
                fname[strlen(fname)-1]=0;
                success=TRUE;
            }
            else
            {
                fprintf(stderr, "Error: your input was too long. Please "
                        "try again.\n");
                read_rest_of_line();
            }
        }
        if(quit)
        {
            break;
        }
        /* do the same again for their last name */
        success=FALSE;
        while(!success)
        {
            printf("Enter the person's last name: ");
            if(fgets(lname, NAMELEN+EXTRACHARS, stdin) == NULL
                    || *lname == '\n')
            {
                quit=TRUE;
                break;
            }
            if(lname[strlen(lname)-1]=='\n')
            {
                /* remove the newline character as we now know that we got
                 * all the data in the buffer
                 */
                lname[strlen(lname)-1]=0;
                success=TRUE;
            }
            else
            {
                fprintf(stderr, "Error: your input was too long. Please "
                        "try again.\n");
                read_rest_of_line();
            }
        }
        /* and now their age */
        success=FALSE;
        while(!success)
        {
            printf("Enter their age: ");
            if(fgets(line, LINELEN+EXTRACHARS, stdin) == NULL || 
                    *line == '\n')
            {
                quit=TRUE;
                break;
            } /* end if */
            if(line[strlen(line)-1]=='\n')
            {
                /* remove the newline character as we now know that we got
                 * all the data in the buffer
                 */
                line[strlen(line)-1]=0;
            }/* end if */
            else
            {
                fprintf(stderr, "Error: your input was too long. Please "
                        "try again.\n");
                read_rest_of_line();
                continue;
            } /* end else */
            lage = strtol(line, &end, 0);
            /* check that the input was numeric - no non-digits allowed */
            if(*end)
            {
                fprintf(stderr, "Error: input was not numeric.\n");
                continue;
            }/* end if */
            /* check that the input is within the range of an unsigned int*/
            if(lage < 0 || lage > UINT_MAX)
            {
                fprintf(stderr, "Error: input was not in the "
                        "allowed range\n");
                continue;
            }/* end if */
            success=TRUE;
            age = (unsigned)lage;
        }/* end while for success */

        /* create a person based on the data entered */
        myperson = make_person(fname, lname, age);
        /* add the person pointer to the list */
        if(!list_add(&list, myperson))
        {
            fprintf(stderr, "Error in adding a person.\n\n");
            break;
        }
    }/* end while for quit */
    /* print the contents of the list */
    print_list(&list, print_person);
    /* free the list */
    list_free(&list);
    return EXIT_SUCCESS;
}



/**************************************************************************
 * clear the input buffer
 *************************************************************************/
void read_rest_of_line(void)
{
    int ch;
    /* grab all the chars from the input buffer until we reach the 
     * end of the buffer
     */
    while(ch=getc(stdin), ch!=EOF && ch!='\n')
        ;
    /* reset the error status of the incoming file pointer */
    clearerr(stdin);
}

void print_person(void* data)
{
        struct person * p = data;
        printf("%s %s %d\n", p->fname, p->lname, p->age);
}
