/**************************************************************
* Name: Mansi Joshi
* Student Number: 041091664
* Course Name: C Language
* Course Section: CST8234_302
* Assignment Name: LAB 3
* Purpose: Given two numbers, to check if the sum of the proper divisors 
* of one number is equal to the other number and vice versa. This program
* aims to explore the relationships between numbers and their divisors.
* Date Submitted: October 22, 2023
* Due Date: October 22, 2023
* Professor: Prableen Singh
* List of Sources: N/A
**************************************************************/
#include "function.h"
#include <stdio.h>


/*************************************************************
 * Function Name: sort_array
 * Purpose: Sorts a 2D array of integers in ascending order
 * Function In Parameters: int (*arr)[MAX_LENGTH], int rowSize, int columnSize
 * Function Out: N/A
 * Version: 1
 * Author: Mansi Joshi
*****************************************************************/

void sort_array(int (*arr)[MAX_LENGTH], int rowSize, int columnSize) {
    int flattened[MAX_LENGTH * MAX_LENGTH];
    int i, j, index = 0;

    /*Flatten the 2D array into a 1D array*/
    for (i = 0; i < rowSize; i++) {
        for (j = 0; j < columnSize; j++) {
            flattened[index++] = arr[i][j];
        }
    }

    /*Sort the flattened array (bubble sort)*/
    for (i = 0; i < rowSize * columnSize - 1; i++) {
        for (j = 0; j < rowSize * columnSize - i - 1; j++) {
            if (flattened[j] > flattened[j + 1]) {
                int temp = flattened[j];
                flattened[j] = flattened[j + 1];
                flattened[j + 1] = temp;
            }
        }
    }

    /*Reshape the sorted array back into the 2D array*/
    index = 0;
    for (i = 0; i < rowSize; i++) {
        for (j = 0; j < columnSize; j++) {
            arr[i][j] = flattened[index++];
        }
    }
}
