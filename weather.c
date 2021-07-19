/*
This program begins by opening the file san_jose_temperature_2020.txt 
for reading. If the input file can not be opened, the program displays
an error message. If the output file can not be opened, the program displays
an error message and continues to prompt the user to enter the name of the
output file. The program then reads the data from the input file and creates 
an output file with the monthly average maximum and minimum temperatures.
Sukhamrit Singh, July 19, 2021
*/

#include <stdio.h>
#include <string.h> // used to find length of string
#include <stdlib.h> // used to convert string to int/double

FILE  *in, *out; // setting pointers to the input and output files
const int MONTHS = 12; // defining a global constant to use wherever the program can

int main (void) {

    // declaring a string array for the names of the input and output files
    char inName[64] = "san_jose_temperature_2020.txt";
    char outName[20] = "";

    // declaring a string array to store each line fromt input file
    char input[28] = {""};

    // creating an array of the months which will be called when outputting the results
    char months_list[MONTHS][9] = {"Jan 2020", "Feb 2020", "Mar 2020", 
        "Apr 2020", "May 2020", "Jun 2020", "Jul 2020", "Aug 2020",
        "Sep 2020", "Oct 2020", "Nov 2020", "Dec 2020"};

    // declaring these variables to act as counters and to store data which 
    // will be used to calculate the average min and max temperatures of each month
    int prev_month = 0;
    int curr_month = 0;
    double month_max_total = 0;
    double month_min_total = 0;
    int month_days = 0;

    // if statement to check whether a file can be opened in read mode
    // if can not be opened, the program will print an error message
    if ( (in = fopen (inName, "r"))  ==  NULL ) {
        printf ("Can't open %s for reading.\n", inName);
    }

    // if input file can be opened, prompt user to enter name of output file
    printf ("Enter name of output file: ");
    scanf ("%s", outName);

    // loop to check whether the output file can be opened in write mode
    // if can not be opened, the program will print an error message and keep prompting user
    while ((out = fopen (outName, "w"))  ==  NULL ) {
        printf ("Can't open %s for writing.\n\n", outName);

        // prompt user again to enter file output name
        printf ("Enter name of output file: ");
        scanf ("%s", outName);
    }

    // printing the names of the columns in the output file
    fprintf(out, "Mon./Year Avg Max  Avg Min (\u00b0C)\n\n");

    // declaring counter to go through each row in the input file
    int row = 0;

    // while true loop making sure the loop keeps running until there
    // are no more lines in the input file
    while (1) {

        // creating pointers to tokenize each part of the line
        // into a year, month, day, max temp, and min temp string
        char *year = "";
        char *month = "";
        char *day = "";
        char *max_temp = "";
        char *min_temp = "";

        // checking if at the last line of the input file
        // if it is, print the average max and min temperature for the last month
        if (fgets(input, 28, in) == NULL) {
            fprintf(out, "%s   %.2f    %.2f\n", months_list[prev_month - 1], 
                    (month_max_total/month_days), (month_min_total/month_days));
            break;
        }

        // if statatent to make sure not every day in the month should be outputted
        if (strlen(input) == 1)
            continue;

        // creating a token pointer to tokenize each part of the line based 
        // on the space delimiter
        char *token = strtok(input, " ");
        int i = 0;

        // while loop which will assign each token to a variable
        // until there are no more tokens in the line
        while(token != NULL) {
            if (i == 0) {
                year = token;
            } else if (i == 1) {
                month = token;
            } else if (i == 2) {
                day = token;
            } else if (i == 3) {
                max_temp = token;
            } else if (i == 4) {
                min_temp = token;
            }
            
            // making sure to return NULL when there is nothing to tokenize
            token = strtok(NULL, " ");

            // incrementing i to move on to next token
            i++;
        }

        // set current month to the value of month after being converted to int
        curr_month = atoi(month);

        // checking if the values of previous month and current month are the same
        // if not, the program will calculate and output the averages of the month
        if (curr_month != prev_month) {

            if ( prev_month != 0 ) {    
                // month changed, show prev month avg
                fprintf(out, "%s   %.2f    %.2f\n", months_list[prev_month - 1], 
                    (month_max_total/month_days), (month_min_total/month_days));
            }

            // set the value of previous month equal to current month
            prev_month = curr_month;

            // restart the month_days counter and start setting totals
            // from the restart based on the new month
            month_max_total = atof(max_temp);
            month_min_total = atof(min_temp);
            month_days = 1;

        } else {
            
            // continue to add to the value of the max and min temperature totals
            // continue to add to the month_days counter to find how many days total
            month_max_total += atof(max_temp);
            month_min_total += atof(min_temp);
            month_days++;
        }

        // increment row to go onto the next row
        row++;
    }    

    // close the input and output files properly
    fclose (in);
    fclose (out);
    
    // conclude program
    return 0;
}