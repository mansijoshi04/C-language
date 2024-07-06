#include <stdio.h>
#include "students.h"
#include "courses.h"
#include "registration.h"


int main() {
    int numStudents;
    int numCourses;
    int registrationTable[MAX_STUDENTS][MAX_COURSES] = {0};
    printf("Welcome to Student Registration System.\n");

    
    
    struct Student students[MAX_STUDENTS];
    inputStudents(students, &numStudents);

    
    
    struct Course courses[MAX_COURSES];
    inputCourses(courses, &numCourses);

    
    

    int option;
    do {
        printf("\nMain Menu:\n");
        printf("[1] Register a student into a course.\n");
        printf("[2] Drop a student from a course.\n");
        printf("[3] Display Registration table.\n");
        printf("[4] Exit.\n");
        printf("Enter an option from the menu: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                registerStudent(registrationTable, students, numStudents, courses, numCourses);
                break;
            case 2:
                dropStudent(registrationTable, students, numStudents, courses, numCourses);
                break;
            case 3:
                displayTable(registrationTable, students, numStudents, courses, numCourses);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != 4);

    return 0;
}
