/*
This program uses two integer values and finds
the sum, difference, product, quotient, and
the remainder of the two values. The results
are printed at the end.

Sukhamrit Singh, June 15, 2021
*/

#include <stdio.h>

int main (void) {

// define two integer values
int number1 = 10;
int number2 = 4;

// completeing all operations using two integers
int sum = number1 + number2;
int difference = number1 - number2;
int product = number1 * number2;
int quotient = number1 / number2;
int remainder = number1 % number2;

// printing all results from operations
printf("The sum of %i and %i is %i\n", number1, number2, sum);
printf("The difference of %i and %i is %i\n", number1, number2, difference);
printf("The product of %i and %i is %i\n", number1, number2, product);
printf("The quotient of %i and %i is %i\n", number1, number2, quotient);
printf("The remainder of %i and %i is %i\n", number1, number2, remainder);

return 0;
}