/*
* This program uses a structure to store
* the results of exams from many students.
* The program uses this data from the structure
* and passes it to two methods. One method
* uses the data to calculate the average score
* for each student. The other method takes the data 
* to calculate the average score per test. The 
* results are printed when the main function
* calls each method
* Sukhamrit Singh, July 1, 2021
*/

#include <stdio.h>

// defining constant global variables so that
// I can use these variables as much as possible
// in methods and the main function
const int N_TESTS = 4;
const int N_STUDENTS = 5;

// Defining the structure so that we can store
// the testing information for each student
struct student {

    long id;
    int year_in_college;
    double test_scores[4];

};

/*
This method takes takes one student data structure as
its single parameter. Using this, the program takes 
each student's scores and calculates the average score
for that one student
*/
void show_student_average(struct student student_data[]) {

    // for loop to go through all the students
    // for each student, the program will have to
    // calculate the average score
    for (int i = 0; i < N_STUDENTS; i++) {

        // Declaring variables to store information
        // which will be used to calculate average score
        double total_score = 0;
        double student_avg = 0;

        // Nested for loop which will go through each score 
        // and add them all up for each student
        for (int j = 0; j < N_TESTS; j++) {

            // adding all the student scores together
            total_score += student_data[i].test_scores[j];

        }
        
        // finding the student average by dividing the total
        // by the numbr of tests. Then we print the results
        student_avg = total_score / N_TESTS;
        printf("%ld    %.2f\n", student_data[i].id, student_avg);
    }
}

/*
This method takes one student data structure as
its single parameter. Then, using its data, it
calculates the average score for each test. The
results are stored and printed in the end
*/
void show_test_average(struct student student_data[]) {

    // For loop to go through each test for
    // each student. It looks at the first test
    // for all students and keeps going
    for (int i = 0; i < N_TESTS; i++) {

        // Declaring variables to store information
        // which will be used to calculate average score
        double total_score = 0;
        double average = 0;

        // Nested for loop which will go through each student's 
        // test and add them all up for the test number the loop is on
        for (int j = 0; j < N_STUDENTS; j++) {
            
            // Adding the scores based on the test number
            // which will be used to calculate the average
            total_score += student_data[j].test_scores[i];

        }

        // finding the test average by dividing the total
        // by the numbr of students. Then we store it into the array
        // for the specific test number and print the results
        average = total_score / N_STUDENTS;
        printf("%i     %.2f\n", i + 1, average);
    }
    
}

int main(void) {

    /* 
    using the student structure created earlier
    to create an array of 5 students with 
    different data for each student. This data
    will be passed to the methods to make calculations
    */
    struct student school_students[] = {
        {9781473, 1, {97.25, 96.5, 90, 87.5}},
        {6014552, 2, {77.8, 80.0, 81.5, 79.5}},
        {3773909, 2, {85.5, 79, 79, 90.5}},
        {8102274, 1, {88.9, 90.5, 92, 94}},
        {4582934, 1, {90, 90, 92, 89.5}}
    };

    // The results are printed in table format
    // and the data is passed to the methods to
    // make calculations and print results 
    printf("   ID      Average Test Score\n");
    printf("--------   ---------------------\n");
    show_student_average(school_students);
    printf("\nTest  Average Score\n");
    printf("----  -------------\n");
    show_test_average(school_students);

    // conclude program
    return 0;
}

