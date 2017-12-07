#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define IDLEN 8
#define MAXNAMELEN 20
/* a grade point average should be between 0 and 4 - for each course a student
 * is studying they get a grade between 0 and 4 where:
 *     0 is a fail
 *     1 is a pass
 *     2 is a credit
 *     3 is a distinction
 *     4 is a high distinction
 * these grades are added together and divided by the number of courses studies
 * to get an overall average between 0 and 4
 */
#define MAXGPA 4.0
 /* degree and major have the same maximum length */
#define MAXDEGREELEN 100
#define MAXMAJORLEN MAXDEGREELEN
 /* the number of ways we can sort */
#define NUMSORTS 6
 /* the number of students */
#define NUMSTUDENTS 5

/* the data for each student */
struct student
{
    char id[IDLEN + 1];
    char fname[MAXNAMELEN + 1];
    char lname[MAXNAMELEN + 1];
    double gpa;
    char degree[MAXDEGREELEN+1];
    char major[MAXMAJORLEN+1];
};
/* rename the struct student to the student type */
typedef struct student student;

void sort(student * students , size_t numstudents, 
    int (*cmp)(const student*, const student *), 
    void (*swap)(student*, student*)
    );
int cmp_by_id(const student*, const student *);
int cmp_by_fname(const student*, const student*);
int cmp_by_lname(const student*, const student*);
int cmp_by_gpa(const student*, const student*);
int cmp_by_degree(const student*, const student*);
int cmp_by_major(const student*, const student*);
void print_students(student * array, unsigned num);
void swapper(student*, student *);
