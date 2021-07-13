/*
Using a bank_account structure, the program
stores the bank account information of 3 users.
Passing a pointer of type struct that is set to the 
structure I created, a update_account is able to 
update the information about each bank account.
Interest is added to the bank account balances and
the results are printed in the end
Sukhamrit Singh, July 12, 2021
*/

#include <stdio.h>

/*
 setting the number of bank accounts 
 to be global and constant so I can 
 reference it everywhere
*/
const int N_ACCOUNTS = 3;

// Creating a bank account structure that will be
// used to store the information for each account and
// the pointer will access it
struct bank_account {

    // all the data stored per account
    int number;
    double balance;
    double interest_rate;
};

/*
Method that updates the bank account of each user.
The method takes a pointer and uses the values to
update the accounts
*/
void update_account(struct bank_account *account) {

    // performing calculations to update account balanaces using
    // interest rates per account
    account->balance = account->balance * (1 + account->interest_rate);
}

int main(void) {

    // creating an array of type struct
    // that will hold the bank info. for 3 people 
    struct bank_account my_accounts[] = {
        {10907, 2000.00, 0.015},
        {47112, 5372.25, 0.024},
        {87435, 1800.00, 0.030}
    };

    // creating a pointer and setting it to my_accounts[]
    // this will be passed to the update_account function
    struct bank_account *account_pointer = my_accounts;

    // printing the format of the output
    printf("\nAcct #   Balance\n");
    printf("------   -------\n");

    // for each account, update the balance by
    // calling the update_account method
    for (int i = 0; i < N_ACCOUNTS; i++) {

        /* pass the pointer to the function
           print the results
           then incremement the pointer so 
           that it can go to the next account
        */

        update_account(account_pointer);
        printf("%i    $%.2f\n", account_pointer->number, account_pointer->balance);
        account_pointer++;
    }

    // conclude program
    return 0;
}