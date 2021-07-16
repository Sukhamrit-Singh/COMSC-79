/*
vector2d.h, which contains the type definition for a 
vec2d and the prototypes for the functions in this file.
*/

#include <stdio.h>
#include <math.h> // incluing this 
                  // library to use power and sqrt functions
#include "vector2d.h" // including the vector2d.h file

/*
Prints its argument in the form (x, y) with three digits 
to the right of the decimal point. The data used from the
passed vector
*/
void display_vector(const vec2d v) {
    printf("(%.3f, %.3f)", v.x, v.y);
}

/*
Returns the magnitude of the vector, calculated as the 
square root of x^2 plus y^2. The program uses the function 
of the math.h library here
*/
double magnitude(const vec2d v) {
    double magnitude = sqrt(pow(v.x, 2) + pow(v.y, 2));

    // returning the value of magnitude
    return magnitude;
}

/*
Returns a new vector that is the sum of the two parameters; 
the x value is the sum of the x values of v1 and v2; the y 
value is the sum of the y values of v1 and v2. Uses the data 
from the two passed vectors to make these calculations.
*/
vec2d add(const vec2d v1, const vec2d v2) {
    vec2d v3 = {v1.x + v2.x, v1.y + v2.y};

    // returns the vector v3
    return v3;
}

/*
Returns a new vector whose x and y values have been multiplied 
by the factor. Uses the data from the passed vector and scale factor
to make these calculations.
*/
vec2d scale(const vec2d v, const double factor) {
    vec2d v4 = {v.x * factor, v.y * factor};

    // returns the vector v4
    return v4;
}

/*
Returns the sum of v1.x × v2.x and v1.y × v2.y.
Uses the data from the two passed vectors to make
these calculations.
*/
double dot_product(const vec2d v1, const vec2d v2) {
    double sum = (v1.x * v2.x) + (v1.y * v2.y);

    return sum;
}