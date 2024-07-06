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

/* Function prototype for sumOfDivisors */
int sumOfDivisors(int num);

/*************************************************************
 * Function Name: main
 * Purpose: Prompts the user and check if the numbers entered are amicable
 * Function In Paramaters: N/A
 * Function Out: N/A
 * Version: 1
 * Author: Mansi Joshi
*****************************************************************/
int main() {
    int num1, num2, sum1, sum2;

    printf("Enter the two numbers: ");
    scanf("%d %d", &num1, &num2);

     sum1 = sumOfDivisors(num1);
     sum2 = sumOfDivisors(num2);

    if (sum1 == num2 && sum2 == num1) {
        printf("Entered numbers are amicable.\n");
    } else {
        printf("Entered numbers are not amicable.\n");
    }

    return 0;
}

/*************************************************************
 * Function Name: sumOfDivisors
 * Purpose: To calculate the sum of proper divisors of a number 
 * Function In Paramaters: int sum , int i
 * Function Out: N/A
 * Version: 1
 * Author: Mansi Joshi
*****************************************************************/
int sumOfDivisors(int num) {
    int sum = 0;
    int i = 0;
    for (i = 1; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return sum;
}

