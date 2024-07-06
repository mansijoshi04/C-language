#include <stdio.h>
#include <string.h>
#include "registration.h"

int i;
int j;
void registerStudent(int table[MAX_STUDENTS][MAX_COURSES], struct Student students[], int numStudents, struct Course courses[], int numCourses) {
    int studentIndex, courseIndex;

    printf("List of Student IDs\n");
    for (i = 0; i < numStudents; ++i) {
        printf("Index %d\t%s\n", i, students[i].id);
    }

    printf("Enter the Student's ID to register a course: ");
    char studentID[6]; 
    scanf("%5s", studentID);

    
    for (i = 0; i < numStudents; ++i) {
        if (strcmp(studentID, students[i].id) == 0) {
            studentIndex = i;
            break;
        }
    }

    printf("List of Available Course IDs\n");
    for (i = 0; i < numCourses; ++i) {
        printf("Index %d\t%s\n", i, courses[i].code);
    }

    printf("Enter the course ID [3-Alphas] [4-digits]: ");
    char courseID[8]; 
    scanf("%7s", courseID);

    
    for (i = 0; i < numCourses; ++i) {
        if (strcmp(courseID, courses[i].code) == 0) {
            courseIndex = i;
            break;
        }
    }

    
    table[studentIndex][courseIndex] = 1;

    printf("Registration Successful\n");
}

void dropStudent(int table[MAX_STUDENTS][MAX_COURSES], struct Student students[], int numStudents, struct Course courses[], int numCourses) {
    int studentIndex, courseIndex;

    displayTable(table, students, numStudents, courses, numCourses);

    printf("Please select the Index number to drop student registration: ");
    scanf("%d", &studentIndex);

    
    for (i = 0; i < numCourses; ++i) {
        table[studentIndex][i] = 0;
    }

    printf("Drop course successful.\n");
}

void displayTable(int table[MAX_STUDENTS][MAX_COURSES], struct Student students[], int numStudents, struct Course courses[], int numCourses) {
    printf("\tRegistration Table\n");
    printf("Registration Index\tStudent ID\tCourse ID\tRegistration Status\n");

    for (i = 0; i < numStudents; ++i) {
        printf("\t%d\t\t%s\t\t", i, students[i].id);

        for (j = 0; j < numCourses; ++j) {
            printf("%s\t\t", table[i][j] ? "R" : "D");
        }

        printf("\n");
    }
}
