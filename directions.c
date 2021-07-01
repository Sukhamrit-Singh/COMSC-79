#include <stdio.h>
#include <math.h> // to use absolute value function
#include <string.h> // to get length and compare strings 

/*
* This program stores the information of many cities
* in a structure called cities. This stored data of
* each city is then displayed to the user in a table
* format and is also used to calculate which direction 
* a city is from the other cities. Using different method,
* these actions are achieved.
* Sukhamrit Singh, June 30, 2021
*/

// creating the structure so that an array of this
// structure can be made to store info. about cities
struct city {

    // characteristics of each city
    // variables to store the difference city info.
    char name[20];
    double latitude;
    double longitude;

};

// variable which will used to format the city information
// the value will be used to input spaces after the city name
int max_length = 0;

/*
This method will be used to display the city info. of each city
in the array structure. By passing in a parameter of type struct,
the values stored in he main function will be passed once the 
method is called
*/
void display_city(struct city cities) {

    // storing the values of lat and long in these variables
    // will be used to display results later
    char latitude = ' ';
    char longitude = ' ';

    // using the information from the paramter to
    // print the cities name
    printf("%s", cities.name);

    /*
    It will find the length and based on it, the cities
    will have a number of spaces displayed after when
    being printed so that all the coordinates start 
    at the same point after
    */
    int len = max_length - strlen(cities.name);
    for (int i = 0; i< len; i++) {
        printf(" ");
    }

    /*
    These if statements will check whether the coordinates
    of the cities are east, west, north, or south. If the latitude
    coordinate is less than 0, that means the city is south, and if
    greater than 0, its north. For longitude, if less than 0, it is west
    and if not, it is east. We have mutiple checks for multiple 
    combinations to accuratley represent the coordinates at the end.
    Once the checks are done, the method will print the results
    */
    if(cities.latitude < 0) {
        if(cities.longitude < 0) {
            latitude = 'S';
            longitude = 'W';

        } else {
            latitude = 'S';
            longitude = 'E';
        }

    } else {
        if(cities.longitude < 0) {
            latitude = 'N';
            longitude = 'W';

        } else {
            latitude = 'N';
            longitude = 'E';
        }
    }
    printf("   %.3f\u00b0%c   %.3f\u00b0%c",
            fabs(cities.latitude), latitude, fabs(cities.longitude), longitude);
}

/*
This method calculates in which direction one city is
from the other. It checks this with all the cities in the
array structure except itself. To check if a city is a 
combination, such as 'south east' or just a solid direction,
such as 'north'. After these checks, the results are printed
showing which direction a city is from all the other cities in
the structure.
*/
void display_direction_to(struct city destination, 
    struct city starting_point) {
    
    // storing the values of the longitude and latitude
    // direction which will be printed in the results
    char *latDir = "";
    char *longDir = "";

    /*
    using conditions to check the latitude direction
    between the two cities. If a cities latiude is greater
    than the other, it is north of the other city and vice versa.
    If a longitude point is greater than another, the city
    is more east than the other and vice versa
    */
    if (starting_point.latitude > destination.latitude) {
        latDir = "north";
    } else {
        latDir = "south";
    }

    if ( starting_point.longitude > destination.longitude ) {
        longDir = "east";
    } else {
        longDir = "west";
    }

    // results are printed
    printf("   %s%s of %s", latDir, longDir, destination.name);
}


int main(void) {

    // setting the number of cities in the structure
    // into a constant so that it can easily be referenced
    const int N_CITIES = 6;
    
    // creating the array structure which will hold
    // all the information of the cities which will be
    // passed to methods
    struct city famous_cities[] = {
        {"Paris", 48.85, 2.35},
        {"Antananarivo", -18.933, 47.517},
        {"Reno", 39.517, -119.817},
        {"Los Angeles", 34.050, -118.250},
        {"Detroit", 42.333, -83.033},
        {"Windsor (Ontario)", 42.283, -83.000}
    };
    
    // finding the amount of spaces needed to be after
    // the name of the city so all coordinates start at an
    // even point
    for(int i = 0; i < N_CITIES; i++) {
        int len = strlen(famous_cities[i].name);
        if ( len > max_length ) {
            max_length = len;
        }
    }
    
    // Calling the display_city method for each city
    // in the structure so that all the information gets
    // displayed to the user
    printf("\n");
    for(int i = 0; i < N_CITIES; i++) {
        display_city(famous_cities[i]);
        printf("\n");
    }

    printf("\n"); // new line for readbility

    /*
    For each city, the for loop calls the display_direction_to
    method which passes the two cities and calculates the direction
    from the start to the destination city.
    */
    for (int i = 0; i < N_CITIES; i++) {

        // first, the loop prints the starting city
        printf("%s is:\n", famous_cities[i].name);

        // the nested for loop now compares every other city with
        // the starting city and calls the display_direction_to method
        // this will allow for the results to be calculated and printed
        for (int j = 0; j < N_CITIES; j++) {

            // if statement to compare the names of the cities. If the
            // destination and starting city names are the same, then 
            // the city is skipped

            // the two cities are being passed to the method and they are
            // being compared to determine the direction they are from one
            // another, the results are printed
            if (strcmp(famous_cities[i].name, famous_cities[j].name) != 0) {
                display_direction_to(famous_cities[j], famous_cities[i]);
                printf("\n");
            }
        }
        printf("\n"); // new line for readbility
    }

    // conclude program
    return 0;
}
