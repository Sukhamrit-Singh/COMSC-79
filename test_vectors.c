/*
This file contains your main() function, which repeatedly 
asks the user whether they want to add vecctors, scale a 
vector, compute a dot product, or exit. Depending on their 
choice, the program requests them to enter the relevant 
information, does the calculation, and presents the result.
Sukhamrit Singh, July 16, 2021
*/

#include <stdio.h>
#include "vector2d.h" // including the contents from the vector2d.h file

// Compile code:
//   $ gcc -o test_vectors test_vectors.c vector2d.c

// Run program
//   $ ./test_vectors 

int main (void) {

    // declaring the user_input variable which will be used
    // to decide which methods to carry out
    int user_input = 0;

    // if the user does not want to exit the program, keep prompting
    // them to enter their input
    while (user_input != 4) {

        // prompting the user to enter the type of calculations they want
        // to make. If they enter 4, they will exit the program
        printf("1) Add vectors; 2) Scale vector; 3) Dot product; 4) Exit: ");
        scanf("%d", &user_input);

        // initializing the vectors and variables that will be passed to
        // the methods. Setting their values to 0 to make sure no random memory
        // gets stored as their values
        vec2d input_vector1 = {0, 0};
        vec2d input_vector2 = {0, 0};
        double scalar = 0;

        // checking based on the value of user_input which functions to
        // carry out or what to display to the user
        if (user_input == 1) {

            // prompting the user to enter the values of the two vectors
            printf("Enter the x and y values for the first vector, separated by spaces: ");
            scanf("%lf %lf", &input_vector1.x, &input_vector1.y);
            printf("Enter the x and y values for the second vector, separated by spaces: ");
            scanf("%lf %lf", &input_vector2.x, &input_vector2.y);

            // passing the users values to the add method
            // then the results will be printed by calling the display method
            vec2d sum_vector = add(input_vector1, input_vector2);
            printf("Sum is ");
            display_vector(sum_vector);
            printf("\n");

        } else if (user_input == 2) {

            // prompting the user to enter the values of the vector and the scalar
            printf("Enter the x and y values for the first vector, separated by spaces: ");
            scanf("%lf %lf", &input_vector1.x, &input_vector1.y);
            printf("Enter scaling factor: ");
            scanf("%lf", &scalar);

            // passing the users values to the scale method
            // then the results will be printed by calling the display method
            vec2d scale_vector = scale(input_vector1, scalar);
            printf("Scaled vector is ");
            display_vector(scale_vector);
            printf("\n");
        } else if (user_input == 3) {

            // prompting the user to enter the values of the two vectors
            printf("Enter the x and y values for the first vector, separated by spaces: ");
            scanf("%lf %lf", &input_vector1.x, &input_vector1.y);
            printf("Enter the x and y values for the second vector, separated by spaces: ");
            scanf("%lf %lf", &input_vector2.x, &input_vector2.y);

            // passing the users values to the dot_product method
            // printing the results from there
            double product = dot_product(input_vector1, input_vector2);
            printf("Dot product is %.3f\n", product);
        } else if (user_input > 4 || user_input < 1) {

            // if the user_input is not a valid input, re-prompt them to enter it
            printf("Invalid input, please re-enter your choice\n");
        }

        // printing a new line for readability
        printf("\n");
    }

    // if the user exits the program, print a goodbye message
    printf("Goodbye.\n");

    // concluding the program
    return 0;
}