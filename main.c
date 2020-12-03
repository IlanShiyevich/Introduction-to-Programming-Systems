#include <stdio.h>
#include "myBank.h"


int checkAccount(int account_number){
    if(account_number>900 && account_number<951){
        return 1;
    }
    return 0;
}

int main() {
    char option;
    double amount;
    int account_number;
    double balance;
    while(1){
        printf("Please choose a transaction type:\n"
               " O-Open Account\n"
               " B-Balance Inquiry\n"
               " D-Deposit\n"
               " W-Withdrawal\n"
               " C-Close Account\n"
               " I-Interest\n"
               " P-Print\n"
               " E-Exit\n");
        scanf(" %c", &option);
        switch(option){

            case 'O':
                printf("Please enter amount for deposit: \n");
                scanf(" %lf",&amount);
                printf("New account number is: %d \n", newAccount(amount));
                break;

            case 'B':
                printf("please enter the account number: \n");
                scanf(" %d",&account_number);

                if(!checkAccount(account_number)){
                    printf("invalid account number \n");
                    break;
                }

                balance = Balance(account_number);

                if(balance == -9999999999){
                    printf("This account is closed \n");
                    break;
                }

                printf("the balance is: %.2lf \n",balance);
                break;

            case 'D':
                printf("please enter the account number: \n");
                scanf(" %d",&account_number);
                if(!checkAccount(account_number)){
                    printf("invalid account number \n");
                    break;
                }

                printf("Please enter amount for deposit: \n");
                scanf(" %lf",&amount);

                balance = Deposit(account_number,amount);
                if(balance == -9999999999){
                    printf("This account is closed \n");
                    break;
                }
                else if(balance == -9999999999.1){
                    printf("The amount to deposit must be positive integer \n");
                    break;
                }
                printf("The balance of account number %d is: %.2lf \n",account_number,balance);
                break;

            case 'W':
                printf("please enter the account number: ");
                scanf(" %d",&account_number);
                if(!checkAccount(account_number)){
                    printf("invalid account number \n");
                    break;
                }
                printf("Please enter amount for withdraw: ");
                scanf(" %lf",&amount);

                balance = withdrawal(account_number,amount);
                if(balance == -9999999999){
                    printf("This account is closed \n");
                    break;
                }
                if(balance == -9999999999.2){
                    printf("Cannot withdraw more than the balance");
                    break;
                }
                printf("The balance of account number %d is: %.2lf \n",account_number,balance);
                break;

            case 'C':
                printf("please enter the account number: ");
                scanf(" %d",&account_number);
                if(!checkAccount(account_number)){
                    printf("invalid account number \n");
                    break;
                }
                terminateAccount(account_number);
            case 'I':
                printf("Please enter interest rate:");
                double interest = 0;
                scanf(" %lf",&interest);
                if(interest == 0){
                    printf("Failed to read the interest rate");
                    break;
                }
                addInterest(interest);
                break;

            case 'P':
                printAccounts();
                break;
            case 'E': Exit();
                return 0;
            default: printf("Invalid transaction type \n"); break;
        }
    }
}
