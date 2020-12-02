#include <stdio.h>
#include "myBank.h"
static int accountNumb = 901;

int newAccount (double firstDeposit) {
    int i = 0;
    while (bankAccounts[i][0] != 0) {
        i++;
        if(i==50){
            return -999999999;
        }
    }
    bankAccounts[i][1] = firstDeposit;
    bankAccounts[i][0] = 1;
    return accountNumb+i;
}

double Balance(int account_number){
    if(bankAccounts[account_number - accountNumb][0] == 0 ){
        return  -9999999999;
    }
    return bankAccounts[account_number - accountNumb][1];
}

double Deposit(int account_number,double amount){
    if(bankAccounts[account_number - accountNumb][0] == 0 ){
        return -9999999999;
    }
    else if(amount < 0){
        return -9999999999.1;
    }
    return bankAccounts[account_number-accountNumb][1] = bankAccounts[account_number-accountNumb][1] + amount;
}



double withdrawal(int account_number,double amount){
    if(bankAccounts[account_number - accountNumb][0] ==0 ){
        return  -9999999999;
    }
    if(bankAccounts[account_number-accountNumb][1] < amount){
        return  -9999999999.2;
    }
    return bankAccounts[account_number-accountNumb][1] = bankAccounts[account_number-accountNumb][1] - amount;
}

void terminateAccount(int account_number){
    if(bankAccounts[account_number - accountNumb][0] == 0 ){
        printf("This account is already closed");
    }
    bankAccounts[account_number - accountNumb][0] = 0;
}

void addInterest(double interest_rate){
    int i = 0;
    while(bankAccounts[i][0] == 1){
        bankAccounts[i][1] += (bankAccounts[i][1]*interest_rate)/100;
        i++;
    }
}


void printAccounts(){
    int i = 0;
    while(bankAccounts[i][0] != 0){
        printf("The balance of account number %d is: %.2lf", accountNumb+i, bankAccounts[i][1]);
        i++;
    }
}

void Exit(){
    for(int i=0;i<50;i++){
        bankAccounts[i][0] = 0;
    }
}

