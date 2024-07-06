/**************************************************************
* Name: Mansi Joshi
* Student Number: 041091664
* Course Name: C Language
* Course Section: CST8234_302
* Assignment Name: LAB 3
* Purpose: This program demonstrates operations on a 2D array,
* treating it as a 1D array, including reversing,
* randomizing, and sorting elements within the array.
* Date Submitted: October 6, 2023
* Due Date: October 22, 2023
* Professor: Prableen Singh
* List of Sources: N/A
**************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "function.h"


/*************************************************************
 * Function Name: main
 * Purpose: Entry point for the program, manages user interactions and array operations
 * Function In Parameters: None
 * Function Out: int
 * Version: 1
 * Author: Mansi Joshi
*****************************************************************/

int main() {
    int arr[MAX_LENGTH][MAX_LENGTH];
    int i, j;
    int rowSize, columnSize;
    int choice;

    /*Get row size*/ 
    printf("Enter the row size of 2D array (must be an integer): ");
    if (scanf("%d", &rowSize) != 1 || rowSize <= 0) {
        printf("Invalid input. Please enter a positive integer for row size.\n");
        return 1;
    }

    /*Get column size*/ 
    printf("Enter the column size of 2D array (must be an integer): ");
    if (scanf("%d", &columnSize) != 1 || columnSize <= 0) {
        printf("Invalid input. Please enter a positive integer for column size.\n");
        return 1;
    }

    if (rowSize != columnSize) {
        printf("Invalid input. The array must be a square matrix (equal row and column size).\n");
        return 1;
    }

    if (rowSize * columnSize > MAX_LENGTH) {
        printf("Invalid input. The array size exceeds the maximum allowed.\n");
        return 1;
    }

    /*initialize the array with user input*/
    printf("Enter %d numbers for the 2D array (space separated):\n", rowSize * columnSize);
    for (i = 0; i < rowSize; i++) {
        for (j = 0; j < columnSize; j++) {
            if (scanf("%d", &arr[i][j]) != 1) {
                printf("Invalid input. Please enter integers only.\n");
                return 1;
            }
        }
    }
   printf("\n");
    print_array(arr, rowSize, columnSize);

    while (1) {
        printf("\nChoose an operation:\n");
        printf("(0) : exit\n");
        printf("(1) : reverse array\n");
        printf("(2) : randomize array\n");
        printf("(3) : sort array\n");
        printf("(4) : print array\n");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice. Please enter a valid option.\n");
            continue;
        }

        if (choice == 0) {
            printf("Exiting...\n");
            break;  /* Exit the loop */
        }

        switch (choice) {
            case 1:
                reverse_array(arr, rowSize, columnSize);
                printf("Array after reversing:\n");
                print_array(arr, rowSize, columnSize);
                break;
            case 2:
                randomize_array(arr, rowSize, columnSize);
                printf("Array after randomizing:\n");
                print_array(arr, rowSize, columnSize);
                break;
            case 3:
                sort_array(arr, rowSize, columnSize);
                printf("Array after sorting:\n");
                print_array(arr, rowSize, columnSize);
                break;
            case 4:
                printf("Current array:\n");
                print_array(arr, rowSize, columnSize);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
