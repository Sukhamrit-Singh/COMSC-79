/*
This program will repeatedly ask the user 
to enter lines of text, until they press ENTER 
without inputting any data on a line. The program 
then produces a list from A to Z telling how many 
times each character appeared. I use two arrays to 
store each line the user inputs and another to store
the combined input of all lines. The frequency of each
letter is stored in an array structure.
Sukhamrit Singh, July 6, 2021
*/

#include <stdio.h>
#include <ctype.h> // included to check string details
#include <string.h> // included to find length of strings

// creating constants to be accessable everywhere making code
//much more clean
const int BIG_BUFFERSIZE = 1024; // size of the big_buffer array
const int MAX_LEN = 120; // size of the user_input array
const int ALPHABET_COUNT = 26; // size of the alphabet

// creating a structure so that all the data on
// each letter in the alphabet can be stored
struct frequency {

    // data that will be stored in the structure
    char letter;
    int occurrences;
};

/*
 Creating a method that will check each character
 in the array being passed. This array will contain
 the entire user input. Using for loops, each character
 will be converted to upercase and will be checked if it
 is in the alphabet. If it is, the frequency will be incremented
 based on the letter it is
*/
void count_frequency(char input[]) {

    // creating the array structure containing data
    // for each letter in the alphabet
    struct frequency alphabet[] = {
        {'A', 0},
        {'B', 0},
        {'C', 0},
        {'D', 0},
        {'E', 0},
        {'F', 0},
        {'G', 0},
        {'H', 0},
        {'I', 0},
        {'J', 0},
        {'K', 0},
        {'L', 0},
        {'M', 0},
        {'N', 0},
        {'O', 0},
        {'P', 0},
        {'Q', 0},
        {'R', 0},
        {'S', 0},
        {'T', 0},
        {'U', 0},
        {'V', 0},
        {'W', 0},
        {'X', 0},
        {'Y', 0},
        {'Z', 0}
    };

    // finding the length of the array so that
    // the program knows how many characters to go
    // through in the for loop
    int len = strlen(input);

    // for loop that goes through each letter in the
    // alphabet so it can find the frequency of each character
    for (int i = 0; i < ALPHABET_COUNT; i++) {

        // going through each character in the array
        for (int j = 0; j < len; j++) {

            // converting all the letters to upercase
            // which will make the program much more simple
            input[j] = toupper(input[j]);

            // checking if the current character is a letter
            // if it is, is_letter will be '1'. If not, it is '0'
            int is_letter = isalpha(input[j]);

            // if it is a letter and if the current alphabet
            // letter matches with the current array character,
            // incrememnt the frequency of the letter by 1
            if(is_letter == 1) {
                if(input[j] == alphabet[i].letter) {
                    alphabet[i].occurrences++;
                    
                }
            }
        }
    
        // when all letters have been run through, print all the letters
        // and the frequency of each one
        printf("%c:   %i\n", alphabet[i].letter, alphabet[i].occurrences);
        
    }
}

int main (void) {
    
    // creating arrays of specific lengths so that the user input
    // can be stored. The first array takes the input line by line
    // and adds it to the second and bigger array
    char user_input[MAX_LEN] = {""};
    char big_buffer[BIG_BUFFERSIZE] = {""};

    // prompting user to add input
    printf("Input lines of text. Press just ENTER when finished:\n");

    /*
    do while loop which keeps prompting the user until the next line
    has no more input. We check this by seeing if the user_input array
    has only one thing stored which is either '/n' or '/r'
    */
    do {

        // collecting user input and storing in user_input array
        printf("> ");
        fgets(user_input, MAX_LEN, stdin);

        // adding user_input into the bigger array, big_buffer
        if ((strlen(big_buffer) + strlen(user_input)) < BIG_BUFFERSIZE) {
            strcat(big_buffer, user_input);
        }

    } while (user_input[0] != '\n' && user_input[0] != '\r');

    // calling the count_frequency method which passed the big_buffer array
    // the big_buffer array carries all the user input
    count_frequency(big_buffer);

    // conclude program
    return 0;
}
