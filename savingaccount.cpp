#include <iostream>
#include "bankaccount.h"
#include "savingaccount.h"
#include "exception_is.h"
using namespace std;

SavingAccount::SavingAccount() : BankAccount(){
   this->MonthInterestRate=4.5;
   this->min_balance=0;
}

SavingAccount::SavingAccount(string cust_name):BankAccount(cust_name){
   this->MonthInterestRate=4.5;
   this->min_balance=0;
}

SavingAccount::SavingAccount(string cust_name, double ini_balance): BankAccount(cust_name,ini_balance){
  this->MonthInterestRate=4.5;
  this->min_balance=ini_balance;
}

SavingAccount::SavingAccount(Date d) : BankAccount(d){
   this->MonthInterestRate=4.5;
   this->min_balance=0;
}

SavingAccount::SavingAccount(string cust_name,Date d):BankAccount(cust_name,d){
   this->MonthInterestRate=4.5;
   this->min_balance=0;
}

SavingAccount::SavingAccount(string cust_name, double ini_balance,Date d): BankAccount(cust_name,ini_balance,d){
  this->MonthInterestRate=4.5;
  this->min_balance=ini_balance;
}

void SavingAccount::SetInterestRate(double rate){
   this->MonthInterestRate=rate;
}

double SavingAccount::GetInterestRate(){
   return this->MonthInterestRate;
}

void SavingAccount::deposit(double amount){
    if(this->DailyTransectionCount>3) // maximum transaction possible is 3
    {
        char str[80];
        sprintf(str,"{Daily Transection count exceeds and it is : %d ..so you can not do it.}",this->DailyTransectionCount);
        string msg(str);
        throw TransactionLimitExceeds(msg);
        return;
    }
    else
    {
     this->INC_Balance(amount); //this->balance += amount;
     this->DailyTransectionCount++;
    }
}

void SavingAccount::deposit(double amount,Date d){
    if(this->DailyTransectionCount>3) // maximum transaction possible is 3
    {
        char str[80];
        sprintf(str,"{Daily Transection count exceeds and it is : %d ..so you can not do it.}",this->DailyTransectionCount);
        string msg(str);
        throw TransactionLimitExceeds(msg);
        return;
    }
    else
    {
     this->INC_Balance(amount); //this->balance += amount;
     this->DailyTransectionCount++;
     this->passbook.push_back(Transaction(d,1,this->getBalance(),amount));
    }
}

void SavingAccount::withdraw(double amount){
    if(this->DailyTransectionCount>3)// maximum transaction possible is 3
    {
        char str[80];
        sprintf(str,"{Daily Transection count exceeds and it is : %d ..so you can not do it.}",this->DailyTransectionCount);
        string msg(str);
        throw TransactionLimitExceeds(msg);
    }
    else if (amount > this->getBalance()) // amount is less than balance then...
    {
        char str[80];
        sprintf(str,"{Your account's balance is : %0.3lf and you try to withdraw : %0.3lf }",this->getBalance(),amount);
        string msg(str);
        throw InSufficientBalance(msg);
        return;
    }
    else
    {
     DEC_Balance(amount); // this->Balance -= amount;
     this->DailyTransectionCount++;
     /*this->payInterest();*/
     if(this->getBalance() < this->min_balance)
        this->min_balance=this->getBalance();
      return;
    }
}
void SavingAccount::withdraw(double amount,Date d){
    if(this->DailyTransectionCount>3)// maximum transaction possible is 3
    {
        char str[80];
        sprintf(str,"{Daily Transection count exceeds and it is : %d ..so you can not do it.}",this->DailyTransectionCount);
        string msg(str);
        throw TransactionLimitExceeds(msg);
        return;
    }
    else if (amount > this->getBalance()) // amount is less than balance then...
    {
        char str[80];
        sprintf(str,"{Your account's balance is : %0.3lf and you try to withdraw : %0.3lf }",this->getBalance(),amount);
        string msg(str);
        throw InSufficientBalance(msg);
        return;
    }
    else
    {
     DEC_Balance(amount); // this->Balance -= amount;
     this->DailyTransectionCount++;
     if(this->getBalance() < this->min_balance)
        this->min_balance=this->getBalance();
     this->passbook.push_back(Transaction(d,2,this->getBalance(),amount));
     return;
    }
}

 void SavingAccount::payInterest(){
     INC_Balance((this->min_balance*this->MonthInterestRate*30*365)/100.0);
 }

string SavingAccount::toString(){

    char str[70];
	sprintf(str, "{ %5d, %s, %6.2lf, InterestRate: %0.2f ,TransactionCount: %d, Account type : Saving}", this->getAccountNumber(),
         this->GetCustomerName().c_str(),
         this->getBalance(),
         this->MonthInterestRate,
         this->DailyTransectionCount);
    return string(str);
}

void SavingAccount::eod(){
   this->DailyTransectionCount=0;
}

void SavingAccount::eom(){
   this->DailyTransectionCount=0;
   this->payInterest();
   this->min_balance = this->getBalance();
   cout << endl <<"Minimum Balance in Month is : " << this->min_balance << endl;
}

short SavingAccount::getAccountType(){
   return 1; //  because it is saving account
}

