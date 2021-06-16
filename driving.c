/*
Sukhamrit Singh
June 15, 2021

This program calculates a driver's daily driving cost
by using data such as the miles they drive per day and 
cost per gallon of gasoline. This driving data is stored
in variables that are of data type integer or double.
*/

#include <stdio.h>

int main (void) {
    
    /* 
    storing the driver's driving information in
    variables
    */
    int milesPerDay = 40;
    double milesPerGallon = 36.5;
    double costPerGallon = 4.23;
    double dailyParkingFee = 4.75;
    double dailyTollCost = 6.25;

    // using the variables to determine the total cost of gas
    double totalGasCost = (milesPerDay / milesPerGallon) * costPerGallon;

    /*
    using the variables and the total cost of gas to find 
    the driver's cost per day
    */
    double totalCost = totalGasCost + dailyParkingFee + dailyTollCost;

    
    // Printing driver's costs and details
    printf("Miles driven per day: %i\n", milesPerDay);
    printf("Cost per gallon of gasoline: $%.2f\n", costPerGallon);
    printf("Miles per gallon: %.2f\n", milesPerGallon);
    printf("Daily parking fees: $%.2f\n", dailyParkingFee);
    printf("Daily tolls: $%.2f\n", dailyTollCost);

    // Printing the driver's final cost per day
    printf("Your driving cost per day: $%.2f\n", totalCost); 

    

    return 0;

}