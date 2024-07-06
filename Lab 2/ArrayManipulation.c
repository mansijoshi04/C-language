/**************************
Name: Mansi Joshi
Student Number: 041091664
Course Name: C Language
Course Section: CST8234_302
Assignment Number: 1(A)
Assignment Name: LAB 1
Purpose: Given two numbers, to check if the sum of the proper divisors 
of one number is equal to the other number and vice – versa.
Date Submitted: September ,2023
Due Date: September 21,2023
Professor: Natalie Gluzman
List of Sources: N/A
******************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 100

/*************************************************************
 * Function Name: reverse_array
 * Purpose: To reverse the array
 * Function In Parameters: int arr[], int length
 * Function Out: N/A
 * Version: 1
 * Author: Mansi Joshi
*****************************************************************/
void reverse_array(int arr[], int length) {
    int i;
    for (i = 0; i < length / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[length - i - 1];
        arr[length - i - 1] = temp;
    }
}

/*************************************************************
 * Function Name: randomize_array
 * Purpose: To randomize the array
 * Function In Parameters: int arr[], int length
 * Function Out: N/A
 * Version: 1
 * Author: Mansi Joshi
*****************************************************************/
void randomize_array(int arr[], int length) {
    int i;
    srand(time(NULL));  /* Seed the random number generator */
    for (i = 0; i < length; i++) {
        int j = rand() % length;  /* Generate a random index */
        /* Swap array[i] with array[j] */
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

/*************************************************************
 * Function Name: sort_array
 * Purpose: To sort the array
 * Function In Parameters: int arr[], int length
 * Function Out: N/A
 * Version: 1
 * Author: Mansi Joshi
*****************************************************************/
void sort_array(int arr[], int length) {
    /* Using insertion sort*/
    int i;
    for (i = 1; i < length; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

/*************************************************************
 * Function Name: main
 * Function In Parameters: N/A
 * Function Out: N/A
 * Version: 1
 * Author: Mansi Joshi
*****************************************************************/
int main() {
    int length;
    int arr[MAX_LENGTH];
    int i;
    int choice;

    printf("Enter the length: ");
    scanf("%d", &length);

    if (length > MAX_LENGTH || length <= 0) {
        printf("Invalid length. Please try again.\n");
        return 1;
    }

    printf("Enter %d numbers (space separated): ", length);
    for (i = 0; i < length; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("\nChoose an operation:\n");
        printf("(0) : exit\n");
        printf("(1) : reverse array\n");
        printf("(2) : randomize array\n");
        printf("(3) : sort array\n");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Exiting...\n");
            break;  /* Exit the loop */
        }

        switch (choice) {
            case 1:
                reverse_array(arr, length);
                break;
            case 2:
                randomize_array(arr, length);
                break;
            case 3:
                sort_array(arr, length);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        if (choice != 0) {
            int i;
            printf("{ ");
            for (i=0; i < length; i++) {
                printf("%d ", arr[i]);
            }
            printf("}\n");
        }
    }

    return 0;
}
