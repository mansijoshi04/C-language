#ifndef COURSES_H
#define COURSES_H

struct Course {
    char code[8];
};

void inputCourses(struct Course courses[], int *numCourses);
int isValidCourseCode(const char *code, struct Course courses[], int numCourses);

#endif
