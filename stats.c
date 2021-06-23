/*
* This program asks the user to enter
* up to 20 values of weights in kilograms
* with 0 as the sentinel value. The user's
* inputs are stored in an array and at the 
* end of the program, the code calculates
* and prints the total amount of weights,
* the average weight, and the closest values
* to the average weight
* Sukhamrit Singh, June 22, 2021
*/

#include <stdio.h>
#include <math.h>

int main (void) {

    /*
    initializing the values of the array
    and variables that will be used to store
    and calculate the results. Initializing to
    0 so that whenever the program starts, there
    are no random values in them
    */

    double weight[20] = {0};
    double user_input = 0;
    int entries = 0;
    double total_weight = 0;
    double average_weight = 0;
    double minimum_deviation = 0;
    int i = 0;
     
    /*
    For loop will run from i = 0 to i = 19 so that
    the user can be prompted 20 times to input their
    weights
    */
    for (i = 0; i < 20; i++) {

        // Prompting user each time to enter weight in kg
        // if input = 0, the loop will break
        printf("Enter a weight in kg, or 0 to quit: ");
        scanf("%lf", &user_input);
        
        // Need to check if input is a valid value or 0
        // so that program can break loop or display error message
        if (user_input > 0) {

            /* 
            adding the user's inputs into the array and 
            incrementing the value of entries so that
            the results could be properly determined and
            displayed at the end
            */

            weight[i] = user_input;
            total_weight = total_weight + weight[i];
            entries += 1;

        } else if (user_input < 0) {

            // printing error message since input is less than 0
            // decreasing value of i so that loop can run another time
            // since this user input value was invalid
            printf("Invalid weight, please enter a valid input\n");
            i -= 1;

        } else {

            // if user input is 0, loop has to break
            break;
        }
    }

    // Need to check if user entered no entries because
    // total_weight / 0 is not possible
    if (entries == 0) {

        // if there are no entries, average weight is 
        // automatically 0
        average_weight = 0;
    } else {

        // Calculate average weight with the collected data
        average_weight = total_weight / entries;
    }
    
    // define the value of minimum_deviaton to find closest values
    minimum_deviation = fabs(weight[0] - average_weight);

    // initializing variables and another array to store
    // and count values vlosest to average
    int n_closest = 0;
    double closest[entries];

    // for loop to calculate the best value of the minimum
    // deviation. It checks all the values and find the most
    // precise value
    for (i = 0; i < entries; i++) {

        // checking for more precise value of minimum_deviation
        double mdev = fabs(weight[i] - average_weight);

        if( mdev < minimum_deviation) {
            minimum_deviation = mdev;
        }
    }
    
    // loop to check and find closest values to average value
    // by using the determined value of the minimum deviation
    for (i = 0; i < entries; i++) {

        // finding the closest values and storing them in 
        // the closest array to be displayed at the end
        double mdev = fabs(weight[i] - average_weight);
        if (mdev == minimum_deviation) {
            closest[n_closest] = weight[i];
            n_closest += 1;
        }
    }

    // Printing the results to the user based on their data
    printf("Number of entries: %i\n", entries);
    printf("Average weight: %.3lf kg\n", average_weight);
    printf("Number of items closest to average: %i\n", n_closest);
    printf("The item(s) - weight in kg:\n");

    // If there are no entries, that means there are no close values
    // That is why we need to check using an if statament
    if (entries == 0) {

        // printing that there are no values
        printf("None\n");

    } else {

        // printing each value in the close array
        for (i = 0; i < n_closest; i++) {
            printf("%.3lf\n", closest[i]);
         }
    }

    // conclude program
    return 0;

}
