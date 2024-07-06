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
#ifndef STUDENT_H
#define STUDENT_H

#include <stdint.h>

struct student {
    int studentID;
    double percentMark;
};

int readStudentData(const char *filename, struct student **students);
int compareStudentID(const void *a, const void *b);
void convertToLetterGrade(double percentMark, char *letterGrade);
void printStudentData(const struct student *students, int numStudents);
void calculateAndPrintStatistics(const struct student *students, int numStudents);

#endif  // STUDENT_H
