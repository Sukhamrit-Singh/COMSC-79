/*
 * This program calculates parking charges. It asks the user
 * for the time a vehicle entered and exited the parking lot in
 * 24-hour format (such as 1029 or 1453).
 * 
 * It calculates the number of hours and minutes the vehicle was parked,
 * and uses that to figure out the cost:
 *      $2.00 for the first three hours
 *      $0.50 for each additional hour or fraction thereof
 * 
 * The program then asks the user if they wish to enter another set
 * of data (Y for yes or N for no), and then repeats the process if
 * the user enters Y, or ends the program if they enter N.
 * 
 * Sukhamrit Singh, June 23, 2021
 */
 
#include <stdio.h>
#include <ctype.h>  // utilities for characters
#include <stdbool.h> // for easier use of booleans

/*
 * Write a function named valid_time() that takes an integer
 * representing a time in 24-hour format, such as 1329 or 0945 and
 * returns a boolean.
 * 
 * This function checks that the hours part (the first two digits)
 * are in the range 0-23. If not, the function prints an error message.
 * 
 * It then checks that the minutes part (the last two digits)
 * are in the range 0-59. If not, the function prints an error message.
 * 
 * If both the hours and minutes are OK, the function returns true;
 * otherwise it returns false 
 */

bool valid_time(int time) { 

    // define variables which will be used
    // to make calculation and decisions
    bool valid = 0;

    /* 
    * Need to perform these opertations to get the 
    * hours and minutes dividing by a 100 will give 
    * exact hours and modulus will give exact minutes
    */
    int hours = time / 100;
    int minutes = time % 100;

    // if loop to check if the hours and and minutes are valid
    if ((hours >= 0 && hours < 24) && (minutes >= 0 && minutes < 60)) {

        // if valid, make boolean true which will be returned
        valid = 1;
    } 
    
    if (hours < 0 || hours >= 24) {

        // will print error message since conditions are false
        printf("Hours must be from 0-23\n");
    }
        
    if (minutes >= 60) {

        // will print error message since conditions are false
        printf("Minutes must be from 0-59\n");
    }

    // returning boolean value to calling function
    return valid;
    
}

//===============================================

/*
 * Write a function named calculate_charges() that takes two integers
 * representing the number of hours and the number of minutes that a person
 * was parked. 
 * 
 * This function returns a double for the parking charge:
 * $2.00 minimum fee to park for up to three hours
 * and an additional $0.50 per hour for each hour or part thereof
 * over three hours.
 */

double calculate_charges(int hours, int minutes) {

    // define variables which will be used
    // to make calculation and decisions
    double parking_charge = 0;

    // if loops checking how long parking time is
    // with this, will calculate total fees
    if ((hours == 3 && minutes == 0) || (hours <= 2)) {
        parking_charge = 2;
    } else if (hours > 3 && minutes == 0) {
        parking_charge = 0.5 * (hours - 3) + 2;
    } else {
        parking_charge = 0.5 * (hours - 2) + 2;
    }
    
    // returning double value to calling function
    return parking_charge;
}
//===============================================

/*
 * Write a function named get_time() that takes an array of
 * characters as its argument - this is the prompt string.
 * 
 * The function will display the prompt and input a
 * time in 24-hour format as an integer. It will do this
 * repeatedly as long as the input is not a valid time;
 * once the time is valid, it returns the time as an integer.
 * 
 * This function *must* call the valid_time() function to determine
 * if the time the user gave is valid or not.
 */

int get_time(char prompt_str[]) {

    // define variables which will be used
    // to make calculation and decisions
    int user_input = 0;

    // prompt user and gaher input which
    // will be used to check if time is valid
    printf("%s", prompt_str);
    scanf("%d", &user_input);

    // if the time is not valid, the 
    // user will keep getting prompted
    while (valid_time(user_input) == 0) {

        printf("%s", prompt_str);
        scanf("%d", &user_input);

    }

    // returning int value to calling function
    return user_input;
}

//===============================================

/*
 * This function takes no input and returns no value;
 * it is a utility function to clear out the input buffer.
 */
void clear_keyboard(void) {
    while (getchar() != '\n') {
        // keep going
    }
}

/*
 * Write a function named get_yes_no() that takes an array of
 * characters as its argument - this is the input prompt.
 * 
 * This function will repeatedly display the prompt and get a
 * single-character response until the user enters either Y or N
 * in upper or lower case. If the user enters a character other than
 * Y or N, the function prints an appropriate error message.
 * 
 * It returns true if the user entered Y or y, false otherwise.
 * 
 * Hint: use a do/while loop, and call clear_keyboard() at the beginning
 * of the loop before displaying the input prompt. 
 */

bool get_yes_no(char prompt_str[]) {

    // define variables which will be used
    // to make calculation and decisions
    char user_input;
    bool value = 0;

    /*
    * do while loop which will keep prompting
    * user to input text. If not valid, will keep
    * on prompting because program can only move
    * forward if has valid input
    */
    do {

        clear_keyboard();

        // prompting user every time condition is not met
        printf("%s", prompt_str);
        scanf("%c", &user_input); 

        user_input = toupper(user_input);

        // checking if condition is met. If it is, will print
        // error message
        if (user_input != 'Y' && user_input != 'N') {
            printf("Please enter Y for yes or N for no\n");
        }
    } while (user_input != 'Y' && user_input != 'N');    

    // if input if yes, change value to 1 so that program
    // will continue prompting user
    if (user_input == 'Y') {
        value = 1;
    } 

    // returning boolean value to calling function
    return value;

}

//===============================================

// Leave the main() function exactly as it is here.

int main(void)
{
    int start_time = 0;
    int end_time = 0;
    bool proceed = false;
     
    do
    {
        start_time = get_time("Enter starting time in 24-hour format: ");
        end_time = get_time("Enter ending time in 24-hour format: ");
        
        // Split the starting and ending times into their hours and minutes
        int start_hr = start_time / 100;
        int start_min = start_time % 100;
        
        int end_hr = end_time / 100;
        int end_min = end_time % 100;
        
        // Calculate the total number of minutes the vehicle was parked
        int duration = (end_hr - start_hr) * 60 + (end_min - start_min);
        
        // And split that into hours and minutes
        int duration_hr = duration / 60;
        int duration_min = duration % 60;
        
        // Then calculate the charge for parking and print the result
        double charge = calculate_charges(duration_hr, duration_min);
        printf("Charge for parking %i hr %i min: $%.2f\n", duration_hr, duration_min, charge);
        
        proceed = get_yes_no("Enter more data? (Y/N): ");
        printf("\n"); // for spacing
        
    } while (proceed);

    return 0;
}
