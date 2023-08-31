#ifndef CURRENTACCOUNT_H_INCLUDED
#define CURRENTACCOUNT_H_INCLUDED

#include <iostream>
#include "bankaccount.h"
using namespace std;

class CurrentAccount : public BankAccount{

   private:
       int MonthTransactionCount;
       double overdraft;
       double ExtraAmount=0;
       double deductCharges();
   public:
       //constructors
       CurrentAccount();
       CurrentAccount(string name);
       CurrentAccount(string name,double ini_balance);

       CurrentAccount(Date d);
       CurrentAccount(string name,Date d);
       CurrentAccount(string name,double ini_balance,Date d);

       // methods
       void deposit(double amount);
       void deposit(double amount,Date d);
       void withdraw(double amount);
       void withdraw(double amount,Date d);
       void setOD_Limit(double);
       string toString();

       void eom();
       short GetAccountType();

};


#endif // CURRENTACCOUNT_H_INCLUDED
