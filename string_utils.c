/*
 * This program uses a series of functions to manipulate strings.
 * A variety of functions have been made to perform many
 * types of tasks such as trimming strings and spliting
 * them.
 * Sukhamrit Singh, June 12, 2021
 */
 
#include <stdio.h>
#include <ctype.h> // will use the functions from this in program

/*
 * Return the length of the given string.
 */
int str_length(const char *p_str) {

    // initialize length
    int length = 0;

    // keep running loop until a null charactee
    // Incriment length to find the strings length
    for (int i = 0; p_str[i] != '\0'; i++) {
        length += 1;
    }

    // return the value of length
    return length;
}

/*
 * Trim whitespace from the beginning and end of a given string.
 */
void trim(const char *p_str, char *p_result) {

    // define the start and end index
     int length = str_length(p_str);
     int start = 0;
     int end = length;

    // start from the beginning of the string
    // and calculate index until when first
    // character is no longer space
     for (int j = 0; j < length; j++) {
        int check_space = isspace(p_str[j]);

        if (check_space == 0) {
            break;
        } else {
            start = j+1;
        }
    }

    // start from the end of the string and 
    // calculate index until last non space
    // character in the string
     for (int i = length - 1; i >= 0; i--) {
        int check_space = isspace(p_str[i]);

        if (check_space == 0) {
            break;
        } else {
            end = i;
        }
    }

    // using new start and end indexes,
    // add the string without the spaces
    // to p_result pointer
     int k = 0;
     for (int i = start; i < end; i++) {
        p_result[k] = p_str[i];
        k++;
     }

    // set last character to null character
     p_result[k] = '\0';    
}

/*
 * This function finds the position of a delimiter in
 * a string, starting at a given position. Returns -1
 * if the delimiter is not found. If the start position is less than zero,
 * use zero. If the start position is greater than the string length,
 * return -1.
 */
int find_char(char delimiter, const char *p_str, int start_position) {

    // define the start and end index
    int index_val = 0;
    int length = str_length(p_str);

    // create checks to check for invalid start positions
    if (start_position < 0) {
        start_position = 0;
    } else if (start_position > length) {
        index_val = -1;
    }

    // start from start position and until index does not 
    // reach a delimiter, keep running loop. Once it reaches
    // a delimiter, break. If it never does, set index val to -1
    for (int i = start_position; i < length; i++) {

         index_val = i;

         if (p_str[i] == delimiter) {
              break;
         } else if (i + 1 == length) {
              index_val = -1;
         } else {
              index_val++;
         }
    }

    // return value of index_val
    return index_val;
}

/*
 * Copy the substring of a given string, from the given
 * start position up to but not including the given end position.
 * If the start position is less than 0, start at 0.
 * The end position may be greater than the string length.
 * If the end position is -1, take the substring up to the end of the string.
 */
void substring(const char *p_str, int start_position, int end_position, char *p_result) {

    // define the start and end index
    int length = str_length(p_str);
    int j = 0;

    // create checks to check for invalid start positions
    // and invalid end positions
    if (start_position < 0) {
        start_position = 0;
    }

    if (end_position > length || end_position == -1) {
        end_position = length;
    }

    // adding the characters frrom p_str to p_results
    for (int i = start_position; i < end_position; i++) {
        p_result[j] = p_str[i];
        j++;
    }

    // setting the end character to null character
    p_result[j] = '\0'; 
}

/*
 * Split an array of characters on a delimiter, calculating an
 * array of integers giving the positions of the delimiter in the
 * string, with -1 as the last entry in the array.
 * 
 * Example:
 * char date[20] = "2021-03-15";
 * int positions[21]; // every character could be a delimiter
 * split('-', date, positions); // 4, 7, -1
 */
void split(char delimiter, const char *p_str, int *position_array) {

    // define the start and end index
    int length = str_length(p_str);
    int j = 0;

     // running a loop to find the index of each delimiter
     // by also calling the find_char function
     for (int i = 0; i < length; i++) {
          int current_index = find_char(delimiter, p_str, i);
          position_array[j] = current_index;

          if (current_index == -1) {
               break;
          }

          j++;
          i = current_index;
     }
}
        

int main(void) {
    char trim_test[100] = " \t abc  def \n \t   ";
    char trim_result[100];
    trim(trim_test, trim_result);
    printf("Trimmed string: |%s|\n", trim_result); // |abc  def|
    
    int trimmed_length = str_length(trim_result);
    printf("Trimmed length: %d\n", trimmed_length); // 8
    
    char find_test[100] = "abc:defg:hij";
    int pos1 = find_char(':', find_test, 0);
    int pos2 = find_char(':', find_test, 4);
    int pos3 = find_char('?', find_test, 0);
    int pos4 = find_char(':', find_test, 25);
    int pos5 = find_char('e', find_test, -10);
    // should print out 3, 8, -1, -1, and 5
    printf("find_char results: %d, %d, %d, %d, and %d\n",
        pos1, pos2, pos3, pos4, pos5);
    
    char word[15] = "dumbwaiters";
    char part_word[15];
    substring(word, 4, -1, part_word);
    // should print out waiters
    printf("Substring of %s from position 4 to end is %s\n", word, part_word);
    
    char date[20] = "2021-03-15";
    int split_points[21]; // could have a delimiter at each position
    split('-', date, split_points);
    
    int index = 0;
    printf("Results of split: ");
    do {
        printf("%d ", split_points[index]);
    } while (split_points[index++] != -1);
    printf("\n");
    
    char year[10];
    char month[10];
    char day[10];
    substring(date, 0, split_points[0], year);
    substring(date, split_points[0] + 1, split_points[1], month);
    substring(date, split_points[1] + 1, split_points[2], day);
    printf("Reformatted date: %s/%s/%s\n", month, day, year); // 03/15/2021
    
    printf("\n");
    return 0;
}
