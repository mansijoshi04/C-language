/**************************
Name: Mansi Joshi
Student Number: 041091664
Course Name: C Language
Course Section: CST8234_302
Assignment Number: 1(B)
Assignment Name: LAB 1
Purpose: To check if a number has three consecutive 0s
Date Submitted: September ,2023
Due Date: September 21,2023
Professor: Natalie Gluzman
List of Sources:N/A
******************************/

#include <stdio.h>  



int hasThreeConsecutiveZeroes(int number) {
    int count = 0; /*Counter for consecutive zeroes*/
    
    /*Iterate through each digit of the number*/
    while (number != 0) {
        int digit = number % 10;  /*Get the rightmost digit*/
        if (digit == 0) {
            count++;  /*Increment the count of consecutive zeroes*/
            if (count == 3) {
                return 1;  /*Return true if three consecutive zeroes are found*/
            }
        } else {
            count = 0;  /*Reset the count if the digit is not zero*/
        }
        
        number /= 10;  /*Move to the next digit*/
    }
    
    return 0;  /*Return false if three consecutive zeroes are not found*/
}

/*************************************************************
 * Function Name: main
 * Purpose: Prompts the user and check if the number entered has 3 consecutive zeros
 * Function In Paramaters: N/A
 * Function Out: N/A
 * Version: 1
 * Author: Mansi Joshi
*****************************************************************/
int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    if (hasThreeConsecutiveZeroes(number)) {
        printf("The number has three consecutive zeroes.\n");
    } else {
        printf("The number does not have three consecutive zeroes.\n");
    }

    return 0;
}
