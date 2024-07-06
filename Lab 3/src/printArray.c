/**************************************************************
* Name: Mansi Joshi
* Student Number: 041091664
* Course Name: C Language
* Course Section: CST8234_302
* Assignment Name: LAB 3
* Purpose: Given a 2D array and its dimensions, this program 
  prints the elements of the array in the correct arrangement.
* Date Submitted: October 6, 2023
* Due Date: October 22, 2023
* Professor: Prableen Singh
* List of Sources: N/A
**************************************************************/
#include "function.h"
#include <stdio.h>


/*************************************************************
 * Function Name: print_array
 * Purpose: Prints a 2D array of integers
 * Function In Parameters: int arr[][MAX_LENGTH], int rowSize, int columnSize
 * Function Out: N/A
 * Version: 1
 * Author: Mansi Joshi
*****************************************************************/

void print_array(int arr[][MAX_LENGTH], int rowSize, int columnSize) {
    if (rowSize <= 0 || columnSize <= 0) {
        printf("Invalid dimensions for the array. Please provide valid dimensions.\n");
        return;
    }

    int i, j;
    for (i = 0; i < rowSize; i++) {
        for (j = 0; j < columnSize; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
