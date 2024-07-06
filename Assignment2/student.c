/**************************************************************
* Name: Mansi Joshi
* Student Number: 041091664
* Course Name: C Language
* Course Section: CST8234_302
* Assignment Name: Assignment 2 
* Purpose: Student Registration Table
* Date Submitted: November 19, 2023
* Due Date: Novemver 19, 2023
* Professor: Natalie Gluzman
* List of Sources: N/A
**************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> 
#include <string.h>


struct student {
    int studentID;
    double percentMark;
};


/************************************************************* 
 * Function Name: readStudentData
 * Purpose: Reads student data from a binary file into an array of student structures
 * Function In Parameters: const char *filename - Name of the binary file, struct 
 * student **students - Pointer to an array of student structures
 * Function Out: Returns the number of students read from the file
 * Version: 1 
 * Author: Mansi Joshi
 *************************************************************/
int readStudentData(const char *filename, struct student **students) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    int numStudents = fileSize / sizeof(struct student);
    *students = malloc(numStudents * sizeof(struct student));

    if (!*students) {
        perror("Memory allocation error");
        fclose(file);
        exit(1);
    }

    fread(*students, sizeof(struct student), numStudents, file);
    fclose(file);

    return numStudents;
}

/************************************************************* 
 * Function Name: compareStudentID
 * Purpose: Compares two student structures based on their student ID for qsort
 * Function In Parameters: const void *a - Pointer to the first student 
 * structure, const void *b - Pointer to the second student structure
 * Function Out: Returns an integer less than, equal to, or greater than zero if the 
 * student ID of the first structure is less than, equal to, or greater than the student ID 
 * of the second structure
 * Version: 1 
 * Author: Mansi Joshi
 *************************************************************/
int compareStudentID(const void *a, const void *b) {
    return (int)(((struct student *)a)->studentID - ((struct student *)b)->studentID);
}


/************************************************************* 
 * Function Name: convertToLetterGrade
 * Purpose: Converts a percentage mark to a letter grade
 * Function In Parameters: double percentMark - Percentage mark of the 
 * student, char *letterGrade - Pointer to store the resulting letter grade
 * Function Out: N/A
 * Version: 1 
 * Author: Mansi Joshi
 *************************************************************/
void convertToLetterGrade(double percentMark, char *letterGrade) {
    // For demonstration purposes, a simple grading is used
    if (percentMark >= 90) {
        strcpy(letterGrade, "A+");
    } else if (percentMark >= 85) {
        strcpy(letterGrade, "A");
    } else if (percentMark >= 80) {
        strcpy(letterGrade, "A-");
    } else if (percentMark >= 75) {
        strcpy(letterGrade, "B+");
    } else if (percentMark >= 70) {
        strcpy(letterGrade, "B");
    } else if (percentMark >= 65) {
        strcpy(letterGrade, "B-");
    } else if (percentMark >= 60) {
        strcpy(letterGrade, "C+");
    } else if (percentMark >= 55) {
        strcpy(letterGrade, "C");
    } else if (percentMark >= 50) {
        strcpy(letterGrade, "C-");
    } else if (percentMark >= 45) {
        strcpy(letterGrade, "D+");
    } else if (percentMark >= 40) {
        strcpy(letterGrade, "D");
    } else {
        strcpy(letterGrade, "F");
    }
}



/************************************************************* 
 * Function Name: printStudentData
 * Purpose: Prints student data including student ID, percent mark, and letter grade
 * Function In Parameters: const struct student *students - Pointer to an 
 * array of student structures, int numStudents - Number of students in the array
 * Function Out: N/A
 * Version: 1 
 * Author: Mansi Joshi
 *************************************************************/
void printStudentData(const struct student *students, int numStudents) {
    for (int i = 0; i < numStudents; ++i) {
        char letterGrade[4]; // Increased size to accommodate A-
        convertToLetterGrade(students[i].percentMark, letterGrade);

        printf("Student ID: %d, Percent Mark: %.2f, Letter Grade: %s\n",
               (int)students[i].studentID, students[i].percentMark, letterGrade);
    }
}

/************************************************************* 
 * Function Name: calculateAndPrintStatistics
 * Purpose: Calculates and prints the median and average percent marks of students
 * Function In Parameters: const struct student *students - Pointer to an 
 * array of student structures, int numStudents - Number of students in the array
 * Function Out: N/A
 * Version: 1 
 * Author: Mansi Joshi
 *************************************************************/
void calculateAndPrintStatistics(const struct student *students, int numStudents) {
    // Calculate average
    double sum = 0;
    for (int i = 0; i < numStudents; ++i) {
        sum += students[i].percentMark;
    }
    double average = sum / numStudents;

    // Calculate median
    double median;
    if (numStudents % 2 == 0) {
        median = (students[numStudents / 2 - 1].percentMark + students[numStudents / 2].percentMark) / 2.0;
    } else {
        median = students[numStudents / 2].percentMark;
    }

    // Print results
    printf("Median Percent Mark: %.2f\n", median);
    printf("Average Percent Mark: %.2f\n", average);
}


