/**************************************************************
* Name: Mansi Joshi
* Student Number: 041091664
* Course Name: C Language
* Course Section: CST8234_302
* Assignment Name: LAB 2
* Purpose: Reverses the elements in an array.
* Date Submitted: October 6, 2023
* Due Date: October 22, 2023
* Professor: Prableen Singh
* List of Sources: N/A
**************************************************************/
#include "function.h"
#include <stdio.h>

/*************************************************************
 * Function Name: reverse_array
 * Purpose: Reverses the rows and columns of a 2D array
 * Function In Parameters: int (*arr)[MAX_LENGTH], int rowSize, int columnSize
 * Function Out: N/A
 * Version: 1
 * Author: Mansi Joshi
*****************************************************************/

void reverse_array(int (*arr)[MAX_LENGTH], int rowSize, int columnSize) {
    int i, j, temp;
    
    /*Reverse rows*/ 
    for (i = 0; i < rowSize; i++) {
        for (j = 0; j < columnSize / 2; j++) {
            temp = arr[i][j];
            arr[i][j] = arr[i][columnSize - j - 1];
            arr[i][columnSize - j - 1] = temp;
        }
    }

    /*Reverse columns*/
    for (i = 0; i < columnSize; i++) {
        for (j = 0; j < rowSize / 2; j++) {
            temp = arr[j][i];
            arr[j][i] = arr[rowSize - j - 1][i];
            arr[rowSize - j - 1][i] = temp;
        }
    }
}

