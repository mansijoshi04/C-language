#include <stdio.h>
#include "students.h"

void inputStudents(struct Student students[], int *numStudents) {
    printf("Enter the number of students to register: ");
    scanf("%d", numStudents);

    for (int i = 0; i < *numStudents; ++i) {
        do {
            printf("Enter the student index[%d] student id [5-digits]: ", i);
            scanf("%d", &students[i].id);

            if (!isValidStudentID(students[i].id, students, i)) {
                printf("Student ID must be 5 digits and unique.\n");
            }
        } while (!isValidStudentID(students[i].id, students, i));
    }
}

int isValidStudentID(int id, struct Student students[], int numStudents) {
    if (id < 10000 || id > 99999) {
        return 0;  // Not 5 digits
    }

    for (int i = 0; i < numStudents; ++i) {
        if (students[i].id == id) {
            return 0;  // Already exists
        }
    }

    return 1;  // Valid ID
}
