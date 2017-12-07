#include <stdio.h>
#include <stdlib.h>

/* defined constants - these are not variables as we cannot change 
 * their value. We define these prior to compilation and then 
 * the preprocessor - which runs before each file is compiled - is run
 * and it replaces each location of the constant with the value 
 * specified
 */
#define ASS1_WORTH 20
#define ASS2_WORTH 30
#define EXAM_WORTH 50

int main(void)
{
    /* what value do these uninitialised variables have ? */
    unsigned ass1, ass2, exam;
    int ass1Sum=0, ass2Sum=0, examSum=0, studentCount=0;
    float grandSum = 0.0;
    char grade;

    printf("\nLine\tAssignment Scores\tExam\tTotal\n");
    printf("Number\t\t1\t2\tScore\tScore\tGrade\n");
    printf("=======================================================\n");
    /* use of scanf to read in data - we will see later that this 
     * has its dangers. In your assignments, you will not be able 
     * to use scanf but rather use fgets, whose use will be explained
     * later
     */
    while ( scanf("%u%u%u", &ass1, &ass2, &exam) == 3 )  
    {
        unsigned total;
        studentCount++;
        /* 100.0 is a magic number - a magic number is a number 
         * whose meaning is unclear from the context - we should
         * avoid them and instead use defined constants
         */

        /* calculate grade for each student */
        total = ass1 * ASS1_WORTH / 100.0 +
            ass2 * ASS2_WORTH / 100.0 +
            exam * EXAM_WORTH / 100.0;
        if ( total < 50.0 )
            grade = 'N';
        else if ( total < 60.0 )
            grade = 'P';
        else if ( total < 70.0 )
            grade = 'C';
        else if ( total < 80.0 )
            grade = 'D';
        else
            grade = 'H';

        printf("%d\t\t%3d\t%3d\t%3d\t%d\t%c\n",
                studentCount, ass1, ass2, exam, total, grade);
        ass1Sum += ass1;
        ass2Sum += ass2;
        examSum += exam;
        grandSum += total;
    }/*  end of while loop    */

    if ( studentCount == 0 )
        printf("\n   Empty input file\n");
    else  
    {
        printf("\t\t============\t=======\t======\n");
        printf("Averages:\t%6.2f\t%6.2f\t%6.2f\t%6.2f\n",
                ass1Sum / (float) studentCount,
                ass2Sum / (float) studentCount,
                examSum / (float) studentCount,
                grandSum / studentCount );
        printf("    Total no. of students = %d\n", studentCount);
    }
    return EXIT_SUCCESS;
}
