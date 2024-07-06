#ifndef STUDENTS_H
#define STUDENTS_H

struct Student {
    int id;
};

void inputStudents(struct Student students[], int *numStudents);
int isValidStudentID(int id, struct Student students[], int numStudents);

#endif
