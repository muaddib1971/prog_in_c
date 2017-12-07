#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "safemalloc.h"
#define IDLEN 8
#define MAXNAMELEN 20
#define MAXGPA 4.0
#define MAXDEGREELEN 100
#define MAXMAJORLEN MAXDEGREELEN
#define NUMSORTS 6
#define NUMSTUDENTS 5
struct student
{
    char id[IDLEN + 1];
    char fname[MAXNAMELEN + 1];
    char lname[MAXNAMELEN + 1];
    double gpa;
    char degree[MAXDEGREELEN+1];
    char major[MAXMAJORLEN+1];
};
typedef struct student student;
void sort(student ** students , size_t numstudents, 
    int (*cmp)(const student*, const student *), 
    void (*swap)(student*, student*)
    );
int cmp_by_id(const student*, const student *);
int cmp_by_fname(const student*, const student*);
int cmp_by_lname(const student*, const student*);
int cmp_by_gpa(const student*, const student*);
int cmp_by_degree(const student*, const student*);
int cmp_by_major(const student*, const student*);
void print_students(student ** array, unsigned num);
void swapper(student*, student *);
static student * create_student(char * , char *, char *, double,char *, char *);
void free_students(student **students, size_t numstudents);

