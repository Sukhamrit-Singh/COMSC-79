/*

*/

#include <stdio.h>

int main (void) {

    int i, triangleNumber = 0;

    int userNum;

    printf("please: \n");
    scanf("%i", &userNum);

    for (i = 1; i <= userNum; i++)
        triangleNumber += i;


    printf("%i", userNum);


    return 0;
}