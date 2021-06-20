/*
* This program repeatedly asks users to input the prices 
* of their purchased items until the user enters 0. When
* the user enters 0, the program caculates the total cost
* of all the items and the final cost with tax.
* Negative integer inputs give an error message
* Sukhamrit Singh - June 17, 2021
*/

#include <stdio.h>

int main (void) {

    /* Defining variables where components such as
    * user input, accumulated price, subtotal, and number of
    * purchased items will be stored.
    */
    double user_input, subtotal, total_price, tax_price;
    int number_of_items;

    /* Setting tax variable a constant because it wil never be 
    * changed. This variable will be used to calculate the total
    * tax of the final cost.
    */
    const double TAX_RATE = 7.5;

    // prompting user to enter price of the first item
    printf("Enter the item's price, or zero when finished: $");
    scanf("%lf", &user_input);

    /*
    * While loop will keep prompting user to enter prices
    * of items as long as input is not $0. When $0 is entered,
    * the while loop will end.
    */
    while (user_input != 0) {

        /*
        * if statement to check if the input is
        * a valid price. To be a valid price, it
        * must be greater than 0
        */
        if (user_input > 0) {

            /*
            * input will be stored and the prices
            * will accumulate in the subtotal variable
            * Number of items will keep being added
            * as long as user input is valid
            */
            number_of_items += 1;
            subtotal += user_input;
        
            
        /*
        * Negative inputs are invalid and the program
        * will display to the user an error message
        */  
        } else if (user_input < 0) {
            printf("Invalid price, please re-enter the item's price\n");
            
        } 

        /* 
        * While loop will keep printing the below statement
        * and will keep prompting user to enter price 
        */
        printf("Enter the item's price, or zero when finished: $");
        scanf("%lf", &user_input);

    }
    
    /*
    * Once while loop ends, tax price and
    * total price is calculated with the 
    * values of the variables
    */
    tax_price = (TAX_RATE / 100) * subtotal;
    total_price = tax_price + subtotal;


    /*
    * Final part of the program will display to the user
    * the number of items purchased, the subtotal, the tax
    * price, and the total end price
    */
    printf("\n");
    printf("Number of items purchased: %i\n", number_of_items);
    printf("Subtotal:                  $%.2f\n", subtotal);
    printf("Sales tax %.2f%%:           $%.2f\n", TAX_RATE, tax_price);
    printf("Total:                     $%.2f\n", total_price);

    // conclude program
    return 0;

}