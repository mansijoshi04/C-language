/**************************************************************
* Name: Mansi Joshi
* Student Number: 041091664
* Course Name: C Language
* Course Section: CST8234_302
* Assignment Name: Assignment 2 
* Purpose: Student Registration Table
* Date Submitted: November 19, 2023
* Due Date: Novemver 19, 2023
* Professor: Natalie GLuzman
* List of Sources: N/A
**************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];

    // Read data from the file
    struct student *students;
    int numStudents = readStudentData(filename, &students);

    // Sort data by studentID
    qsort(students, numStudents, sizeof(struct student), compareStudentID);

    // Print sorted student data
    printf("Student Data Sorted by studentID:\n");
    printStudentData(students, numStudents);

    // Calculate and print average and median
    calculateAndPrintStatistics(students, numStudents);

    // Free allocated memory
    free(students);

    return 0;
}
