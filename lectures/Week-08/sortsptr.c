#include "sortsptr.h"

/* this is a reworked version of sorts.c where we use an array of pointers to
 * student rather than just students - I only comment here on the differences
 */
#define NUMCMPS 6
int main(void)
{
    char * sort_types[NUMCMPS] = {
        "id", "first name", "last name", "gpa", "degree", "major"  
    };
 

    
    int (*comparers[NUMCMPS])(const student*, const student*) = 
    { 
        cmp_by_id, cmp_by_fname, cmp_by_lname, 
        cmp_by_gpa, cmp_by_degree, cmp_by_major
    };
    unsigned count;
    
    /* we need to assign these separately as the array is initialised with 
     * the return value from a function - we can't use an initialiser list 
     */
    student * students[NUMSTUDENTS];
    students[0]=create_student("34563234", "Fred", "Flintstone", 3.5, "Maths", 
        "Encryption");
    students[1] = create_student("12345160", "Barney", "Rubble", 1.7, "English", 
        "Grammar");
    students[2] = create_student("98712354", "Wilma", "Zafika", 3.8, 
        "Computer Science", "Security");
    students[3] = create_student("23451764", "David", "Makta", 2.4, "Physics", 
            "String Theory"),
    students[4] = create_student("76548912", "Zech", "Valla", 3.0, "Psychology", 
            "Applied Linguistics");
    for(count = 0; count < NUMSORTS; ++count)
    {
        sort(students, NUMSTUDENTS, comparers[count], swapper);
        printf("\n\nthe student list sorted by %s:\n", sort_types[count]);
        print_students(students, NUMSTUDENTS);
    }
    free_students(students, NUMSTUDENTS);
    return EXIT_SUCCESS;
}


/******************************************************************************
* this time we have an array of pointers to student
******************************************************************************/
void print_students(student ** array, unsigned num)
{
    unsigned count;
    for(count = 0; count < num; ++count)
    {
        printf("%s\t%s\t%s\t%f\t%s\t%s\n", array[count]->id, 
            array[count]->fname, array[count]->lname, 
            array[count]->gpa, array[count]->degree, array[count]->major);
    }
}
/* implementation of bubble sort with function pointers */
void sort(student ** students , size_t numstudents, 
    int (*cmp)(const student*, const student *),void (*swap)(student*, student*))
{
    unsigned outer, inner;
    for(outer = 0; outer < numstudents-1; ++outer)
    {
        for(inner = numstudents-1; inner > outer; --inner)
        {
            if(cmp(students[outer], students[inner]) > 0)
            {
                swap(students[outer], students[inner]);
            }
        }
    }
}


void swapper(student* first, student * second)
{
    student copy = *first;
    *first = *second;
    *second = copy;
}

int cmp_by_id(const student* first, const student * second)
{
    return strcmp(first->id, second->id);
}

int cmp_by_fname(const student* first, const student* second)
{
    return strcmp(first->fname, second->fname);
}

int cmp_by_lname(const student* first , const student* second)
{
    return strcmp(first->lname, second->lname);
}

int cmp_by_gpa(const student* first, const student* second)
{
    return (int)((first->gpa - second->gpa) * 100);
}

int cmp_by_degree(const student* first, const student* second)
{
    return strcmp(first->degree, second->degree);
}

int cmp_by_major(const student* first, const student* second)
{
    return strcmp(first->major, second->major);
}

/***************************************************************************
* allocates memory for a student and copies the data passed in into the 
* pointer allocated.
***************************************************************************/
static student * create_student(char * id, char * fname, char * lname, 
    double gpa, char * degree, char * major)
{
    student * newstudent = safemalloc(sizeof(student));
    strcpy(newstudent->id, id);
    strcpy(newstudent->fname, fname);
    strcpy(newstudent->lname, lname);
    newstudent->gpa=gpa;
    strcpy(newstudent->degree, degree);
    strcpy(newstudent->major, major);
    return newstudent;
}

/*****************************************************************************
* free all the students allocated
*****************************************************************************/
void free_students(student ** students, size_t numstudents)
{
    unsigned count;
    for(count = 0; count < numstudents; ++count)
        free(students[count]);
}
