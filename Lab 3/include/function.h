#ifndef FUNCTION_H
#define FUNCTION_H
#define MAX_LENGTH 100

/***************************************************************
* Name: Mansi Joshi
* Student Number: 041091664
* Course Name: C Language
* Course Section: CST8234_302
* Assignment Name: LAB 2
* Purpose: Function prototypes for sorting operations on a 2D array treated as a 1D array.
* Date Submitted: October 6, 2023
* Due Date: October 22, 2023
* Professor: Prableen Singh
* List of Sources: N/A
***************************************************************/

void reverse_array(int (*arr)[MAX_LENGTH], int rowSize, int columnSize);
void randomize_array(int (*arr)[MAX_LENGTH], int rowSize, int columnSize);
void sort_array(int (*arr)[MAX_LENGTH], int rowSize, int columnSize);
void print_array(int arr[][MAX_LENGTH], int rowSize, int columnSize);

#endif 
