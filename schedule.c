/*
This program uses a structure of a class EVC has.
This structure has the name of the class, the days
it happens, and the start time and end time of it.
The times are in 24-hour format. The program also uses
#define to define names of the week with different bit
values. The program ultimateley checks which classes overlap
and then prints the classes that do along with the details of
each.
Sukhamrit Singh, July 15, 2021
*/

#include <stdio.h>
#include <stdbool.h> // to use bool features

// creating #define statements to hold different
// values of the days in a week which will be used to
// define when a class happens
#define MONDAY 1 
#define TUESDAY 1 << 1
#define WEDNESDAY 1 << 2 
#define THURSDAY 1 << 3
#define FRIDAY 1 << 4
#define SATURDAY 1 << 5
#define SUNDAY 1 << 6

// defining this to switch languages from enlish to german
#define LANG 0

// creating global constants to use in multiple places
// such as in methods and the main function
const int N_DAYS = 7;
const int D_LEN = 3;
const int N_CLASSES = 7;

// preproccesor if statements to check the defined lang macro.
// If the value is 0, then it will be in english, and if 1, then
// german
#if LANG == 0
    char days[N_DAYS][D_LEN] = {"M", "T", "W", "Th", "F", "Sa", "Su"};
    char message[] = "conflicts with";
#elif LANG == 1
    char days[N_DAYS][D_LEN] = {"Mo", "Di", "Mi", "Do", "Fr", "Sa", "So"};
    char message[] = "steht in Konflikt mit";
#endif

// creating a structure which will be used to 
// store the data of each EVC class
struct class_details {

    // all the members of the structure
    char name[20];
    unsigned int days_in_week : N_DAYS;
    unsigned int strt_hr : 5;
    unsigned int str_min : 6;
    unsigned int end_hr : 5;
    unsigned int end_min : 6;
};

/*
 * The has_conflict() function returns true if there is a time conflict
 * between the two sections; false if there is no conflict.
 */
bool has_conflict(struct class_details sect_a, struct class_details sect_b) {
    bool day_conflict = 0;

    // converting all the times to minutes which will make
    // the conditional logic much easier to perform
    int first_start = (sect_a.strt_hr * 60) + sect_a.str_min;
    int first_end = (sect_a.end_hr * 60) + sect_a.end_min;

    int second_start = (sect_b.strt_hr * 60) + sect_b.str_min;
    int second_end = (sect_b.end_hr * 60) + sect_b.end_min;;

    /*
    Checking whether classes are on the same day. If they are,
    then the program checks if the times overlap. If they do, the
    value of the bool day_conflict becomes true
    */
    if ((sect_a.days_in_week & sect_b.days_in_week) != 0) {
        if (first_start <= second_start ) {
            if (first_end >= second_start) {
                day_conflict = 1;
            }
        } else {
            if (first_start >= second_start && first_start <= second_end) {
                day_conflict = 1;
            }
        }
    } 

    // returning value of day_conflict
    return day_conflict;
}

/*
 * The display() function prints the information about the given section;
 * It displays the section name, the days it meets, and the beginning
 * and ending time in 24-hour notation.
 */
void display(struct class_details sect1, struct class_details sect2) {

    // creating values of the number, remainder, and counter
    // so that the days of the classes can be printed properly
    int number = sect1.days_in_week;
    int remainder = 0;
    int i = 0;

    // The program first converts the decimal to binary and
    // wherever there is a 1-bit, the day is noted and printed
    printf("%s ", sect1.name);
    while (number > 0) {
        remainder = number % 2;
        number = number / 2;
        if (remainder != 0) {
            printf("%s", days[i]);
        }
        i++;
    }

    // printing the rest of the half of the message
    printf(" (%02d%02d-%02d%02d) %s %s ", sect1.strt_hr, sect1.str_min,
        sect1.end_hr, sect1.end_min, message, sect2.name);


    // doing the same thing now for the class being compared with
    // printing all the details of that class later on as well
    number = sect2.days_in_week;
    remainder = 0;
    i = 0;
    while (number > 0) {
        remainder = number % 2;
        number = number / 2;
        if (remainder != 0) {
            printf("%s", days[i]);
        }
        i++;
    }
    printf(" (%02d%02d-%02d%02d)\n", sect2.strt_hr, sect2.str_min,
        sect2.end_hr, sect2.end_min);
}

int main(void) {

    // creating subjects of type struct to hold all the data of 
    // all the classes
    struct class_details subjects[] = {
        {"ECON 101", MONDAY | WEDNESDAY, 9, 15, 11, 35},
        {"PHYS 002", TUESDAY | THURSDAY, 10, 25, 13, 00},
        {"COMSC 079C", MONDAY, 7, 45, 9, 30},
        {"ACCTG 0063A", WEDNESDAY | FRIDAY, 10, 15, 12, 35},
        {"CHEM 001", TUESDAY | THURSDAY, 17, 00, 19, 25},
        {"MATH 017", MONDAY | TUESDAY | WEDNESDAY | THURSDAY, 13, 05, 15, 45},
        {"ART 099", TUESDAY | THURSDAY, 12, 05, 16, 35}
    };

    //  calling the methods created and running for loops to compare
    // each class with the next ones. Which ever class has an overlap, 
    // the loop prints it and the details of each class by calling those methods
    bool conflict = 0;
    for(int i  = 0; i < N_CLASSES; i++) {
        for (int j = i + 1; j < N_CLASSES; j++) {
            conflict = has_conflict(subjects[i], subjects[j]);
            if (conflict == 1) {
                display(subjects[i], subjects[j]);
            }
        }
    }

    // conclude program
    return 0;
}
