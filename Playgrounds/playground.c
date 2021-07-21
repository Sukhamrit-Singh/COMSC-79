/*
Step 1. Create a string by using digitChar and ending it with null character.
Step 2. Use atoi() function to convert string to integer and store it in digitValue
Step 3: Print digitValue
*/

#include <stdio.h>
#include <stdlib.h>

#define ABSOLUTE_VALUE(x) ( (x) > 0 ) ? (x) : -(x)

typedef int whole_number;
typedef int countable;

void f(whole_number n) {
   printf("f: %d\n", n);
}


int main(void) {
       countable c = 10;
   
   f(c);
   return 0;
}