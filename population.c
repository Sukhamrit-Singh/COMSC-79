/*
* This program takes statistics from the US Census
* Bureau to estimate the population of the United
* States from years 2011 to 2020. Using the data,
* the program calculates the deaths, births, and
* migrants in the US each year. Using a for loop,
* the program is able to determine the population
* of the US each year from 2011 to 2020.
* Sukhamrit Singh - June 17, 2021
*/
#include <stdio.h>

int main (void) {

    /*
    * Defining constant variables which store
    * the data from the US Census
    * Bureau. These variables will be used to
    * calculate the population of the United States
    * each year
    */
    const int TIME_FOR_BIRTH = 9;
    const int TIME_FOR_DEATH = 10;
    const int TIME_FOR_MIGRANT = 47;
    long population = 308401808;
    int year =  2010;

    /* 
    * Calculating the amount of seconds each year
    * so that the program can determine how many births,
    * deaths, and migrants come into the US each year.
    */
    const int SECONDS_IN_YEAR = 60 * 60 * 24 * 365;
    
    /*
    * Calculating how many births, deaths, and migrants 
    * come into the US each year using the defined variables
    */
    int births_per_year = SECONDS_IN_YEAR / TIME_FOR_BIRTH;
    int deaths_per_year = SECONDS_IN_YEAR / TIME_FOR_DEATH;
    int migrants_per_year = SECONDS_IN_YEAR / TIME_FOR_MIGRANT;

    /*
    * Printing the format of the table which will display
    * the population of the US each year from 2011-2020
    */
    printf("\nYear    Estimated Population");
    printf("\n----    --------------------\n\n");

    /*
    * Creating a for loop that will calculate the population each
    * year from 2011-2020. The loop starts from i = 0 (year 2011)
    * and keep incrementing until i = 9 (year 2020). When i = 10,
    * the loop breaks
    */
    for (int i = 0; i < 10; i++) {

        /*
        * Adding to the value of population each year. Births each
        * year mean an addition to the population, migrants entering
        * the US mean an addition to the population, but deaths mean
        * a subtraction from the population.
        */
        population = population + births_per_year - deaths_per_year 
            + migrants_per_year;

        /* 
        * Adding 1 to year so that the year progresses as 
        * the population increases
        */
        year += 1;
        printf("%i    %ld\n", year, population);

    }

    printf("\n");
    
    // concluding program
    return 0;
    
}