/**************************************************************
* Name: Mansi Joshi
* Student Number: 041091664
* Course Name: C Language
* Course Section: CST8234_302
* Assignment Name: LAB 3
* Purpose: To randomize the elements in a 2D array.
* Date Submitted: October 6, 2023
* Due Date: Novemver 17, 2023
* Professor: Natalie
* List of Sources: N/A
**************************************************************/
#include "function.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

/*************************************************************
 * Function Name: randomize_array
 * Purpose: Randomly shuffles the elements of a 2D array
 * Function In Parameters: int (*arr)[MAX_LENGTH], int rowSize, int columnSize
 * Function Out: N/A
 * Version: 1
 * Author: Mansi Joshi
*****************************************************************/

void randomize_array(int (*arr)[MAX_LENGTH], int rowSize, int columnSize) {
    int totalElements = rowSize * columnSize;
    int i;
    for (i = 0; i < totalElements; i++) {
        int randRow1 = rand() % rowSize;
        int randCol1 = rand() % columnSize;
        int randRow2 = rand() % rowSize;
        int randCol2 = rand() % columnSize;

        int temp = arr[randRow1][randCol1];
        arr[randRow1][randCol1] = arr[randRow2][randCol2];
        arr[randRow2][randCol2] = temp;
    }
}


