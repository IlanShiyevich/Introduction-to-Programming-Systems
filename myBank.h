#ifndef _MYBANK_H
#define _MYBANK_H

#include <stdbool.h>

double bankAccounts[50][2];

int newAccount(double firstDeposit);
double Balance(int account_number);
double Deposit(int account_number,double amount);
double withdrawal(int account_number,double amount);
void terminateAccount(int account_number);
void addInterest(double interest_rate);
void printAccounts();
void Exit();


#endif 

