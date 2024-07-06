
#ifndef REGISTRATION_H
#define REGISTRATION_H
#include "students.h"
#include "courses.h"
#include "constants.h"

void registerStudent(int table[MAX_STUDENTS][MAX_COURSES], struct Student students[], int numStudents, struct Course courses[], int numCourses);
void dropStudent(int table[MAX_STUDENTS][MAX_COURSES], struct Student students[], int numStudents, struct Course courses[], int numCourses);
void displayTable(int table[MAX_STUDENTS][MAX_COURSES], struct Student students[], int numStudents, struct Course courses[], int numCourses);

#endif 
