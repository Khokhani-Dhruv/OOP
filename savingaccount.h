#ifndef SAVINGACCOUNT_H_INCLUDED
#define SAVINGACCOUNT_H_INCLUDED

#include "bankaccount.h"
#include <string>
using namespace std;

class SavingAccount: public BankAccount{

   private:
       double MonthInterestRate;
       int DailyTransectionCount=0;
       double min_balance; // declared to store minimum balance for payInterset();
   public:
    //constructor
     SavingAccount();
     SavingAccount(string cust_name);
     SavingAccount(string cust_name, double ini_balance);

     SavingAccount(Date d);
     SavingAccount(string cust_name,Date d);
     SavingAccount(string cust_name, double ini_balance,Date d);

    // getter setter
    void SetInterestRate(double rate);
    double GetInterestRate();

    void deposit(double amount); // override
    void deposit(double amount,Date d); // override
    void withdraw(double amount); // override
    void withdraw(double amount,Date d); // override
    void payInterest();

    // to string functions
    string toString(); // override

     void eod(); // override
     void eom(); // override

     short getAccountType(); // override

};
#endif // SAVINGACCOUNT_H_INCLUDED
