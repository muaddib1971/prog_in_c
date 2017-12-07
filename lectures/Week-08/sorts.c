#include "sorts.h"

int main(void)
{
    /* the various fields we can sort by so that we can output the name of the 
     * field being sorted 
     */
    char * sort_types[NUMSORTS] = {
        "id", "first name", "last name", "gpa", "degree", "major"  
    };
    /* the list of students to sort */
    student students[NUMSTUDENTS] = 
    {
        {
            "34563234", "Fred", "Flintstone", 3.5, "Maths", "Encryption"
        },
        {
            "12345160", "Barney", "Rubble", 1.7, "English", "Grammar"
        },
        {
            "98712354", "Wilma", "Zafika", 3.8, "Computer Science", "Security"
        },
        {
            "23451764", "David", "Makta", 2.4, "Physics", "String Theory"
        },
        {
            "76548912", "Zech", "Valla", 3.0, "Psychology", "Applied Linguistics"
        }
    };

    /* array of comparison functions used for each sort */
    typedef int (*studentcmp)(const student*, const student*);

    studentcmp comparers[NUMSORTS]= 
    { 
        cmp_by_id, cmp_by_fname, cmp_by_lname, 
        cmp_by_gpa, cmp_by_degree, cmp_by_major
    };
    unsigned count;
    for(count = 0; count < NUMSORTS; ++count)
    {
        /* sort the students by each field in turn */
        sort(students, NUMSTUDENTS, comparers[count], swapper);
        printf("\n\nthe student list sorted by %s:\n", sort_types[count]);
        /* print out the student array as it now stands */
        print_students(students, NUMSTUDENTS);
    }
    return EXIT_SUCCESS;

}

/***************************************************************************
* prints out the list of students in the order they are currently located in
* the array
***************************************************************************/
void print_students(student * array, unsigned num)
{
    unsigned count;
    /* print out each student's data in turn */
    for(count = 0; count < num; ++count)
    {
        printf("%s\t%s\t%s\t%f\t%s\t%s\n", array[count].id, 
            array[count].fname, array[count].lname, 
            array[count].gpa, array[count].degree, array[count].major);
    }
}
/* implementation of bubble sort with function pointers */
void sort
(
    student * students , size_t numstudents, 
    /* comparison function */
    int (*cmp)(const student*, const student *), 
    /* function that defines how to swap students */
    void (*swap)(student*, student*)
)
{
    unsigned outer, inner;
    /* iterate over each element */
    for(outer = 0; outer < numstudents-1; ++outer)
    {
        /* iterate backwards over the elements, bubbling them up */
        for(inner = numstudents-1; inner > outer; --inner)
        {
            /* if the outer student is higher in the sort order than the 
             * inner student, swap them
             */
            if(cmp(&students[outer], &students[inner]) > 0)
            {
                swap(&students[outer], &students[inner]);
            }
        }
    }
}

/***************************************************************************
* swap the data in the two student pointers passed in
***************************************************************************/
void swapper(student* first, student * second)
{
    student copy = *first;
    *first = *second;
    *second = copy;
}

/***************************************************************************
* compare students by their student id
***************************************************************************/
int cmp_by_id(const student* first, const student * second)
{
    return strcmp(first->id, second->id);
}

/***************************************************************************
* compare students by their first name
***************************************************************************/
int cmp_by_fname(const student* first, const student* second)
{
    return strcmp(first->fname, second->fname);
}

/***************************************************************************
* compare students by their last name
***************************************************************************/
int cmp_by_lname(const student* first , const student* second)
{
    return strcmp(first->lname, second->lname);
}

/****************************************************************************
* compare students by their grade point average 
***************************************************************************/
int cmp_by_gpa(const student* first, const student* second)
{
    return (int)((first->gpa - second->gpa) * 100);
}

/****************************************************************************
* compare students by their degree alphabetically.
***************************************************************************/
int cmp_by_degree(const student* first, const student* second)
{
    return strcmp(first->degree, second->degree);
}

/****************************************************************************
* compare students by their major.
****************************************************************************/
int cmp_by_major(const student* first, const student* second)
{
    return strcmp(first->major, second->major);
}
