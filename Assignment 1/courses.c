#include <stdio.h>
#include <string.h>
#include "courses.h"

void inputCourses(struct Course courses[], int *numCourses) {
    printf("Enter the number of courses available: ");
    scanf("%d", numCourses);

    for (int i = 0; i < *numCourses; ++i) {
        do {
            printf("Enter the course index[%d] course code [3-Alphas][4-digits]: ", i);
            scanf("%s", courses[i].code);

            if (!isValidCourseCode(courses[i].code, courses, i)) {
                printf("Incorrect Course code input [3-Alphas] [4-digits]\n");
            }
        } while (!isValidCourseCode(courses[i].code, courses, i));
    }
}

int isValidCourseCode(const char *code, struct Course courses[], int numCourses) {
    if (strlen(code) != 7) {
        return 0;  // Incorrect length
    }

    for (int i = 0; i < numCourses; ++i) {
        if (strcmp(courses[i].code, code) == 0) {
            return 0;  // Already exists
        }
    }

    return 1;  // Valid code
}
