#include <iostream>
#include "bankaccount.h"
#include "currentaccount.h"
#include "exception_is.h"
#define month 45

using namespace std;
CurrentAccount::CurrentAccount():BankAccount(){
   // ask sir what to do with it...... MonthTransectionCount...and...overdraft...
   this->MonthTransactionCount=0;
    this->overdraft = 36000; // default overdraft limit
}

CurrentAccount::CurrentAccount(string name):BankAccount(name){
   // ask sir what to do with it...... MonthTransectionCount...and...overdraft...
    this->MonthTransactionCount=0;
    this->overdraft = 36000;
}

CurrentAccount::CurrentAccount(string name,double ini_balance):BankAccount(name,ini_balance){
   // ask sir what to do with it...... MonthTransectionCount...and...overdraft...
       this->MonthTransactionCount=0;
       this->overdraft=36000;
}

CurrentAccount::CurrentAccount(Date d):BankAccount(d){
   // ask sir what to do with it...... MonthTransectionCount...and...overdraft...
   this->MonthTransactionCount=0;
    this->overdraft = 36000; // default overdraft limit
}

CurrentAccount::CurrentAccount(string name,Date d):BankAccount(name,d){
   // ask sir what to do with it...... MonthTransectionCount...and...overdraft...
    this->MonthTransactionCount=0;
    this->overdraft = 36000;
}

CurrentAccount::CurrentAccount(string name,double ini_balance,Date d):BankAccount(name,ini_balance,d){
   // ask sir what to do with it...... MonthTransectionCount...and...overdraft...
       this->MonthTransactionCount=0;
       this->overdraft=36000;
}

double CurrentAccount::deductCharges(){
     if(this->MonthTransactionCount>month)
     {
         cout << endl << "You have done " << this->MonthTransactionCount-month << " over transaction in this Month" << endl;
         cout << "Over transaction is amount of "<< this->ExtraAmount << endl;
         double panltiy = 0.045*this->ExtraAmount;
         this->DEC_Balance(panltiy);
         return panltiy;
     }
     else{

        cout << endl << "You have not crossed Transaction count limit" << endl;
        return 0;
     }
}
void CurrentAccount::deposit(double amount){
    if(this->MonthTransactionCount>month) // maximum transaction possible is 3
    {
        this->ExtraAmount += amount;
        this->MonthTransactionCount++;
        INC_Balance(amount);
        return;
    }
    else
    {
     this->INC_Balance(amount); //this->balance += amount;
     this->MonthTransactionCount++;
    }
}

void CurrentAccount::deposit(double amount,Date d){
    if(this->MonthTransactionCount>month) // maximum transaction possible is 3
    {
        this->ExtraAmount += amount;
        this->MonthTransactionCount++;
        INC_Balance(amount);
        return;
    }
    else
    {
     this->INC_Balance(amount); //this->balance += amount;
     this->MonthTransactionCount++;
     this->passbook.push_back(Transaction(d,1,this->getBalance(),amount));
    }
}


void CurrentAccount::withdraw(double amount){

    if(this->MonthTransactionCount>month)// maximum transaction possible is 3
    {
       this->ExtraAmount += amount;
       this->MonthTransactionCount++;
       DEC_Balance(amount);
       return;

    }
    else if (amount > (this->getBalance()+this->overdraft)) // amount is less than balance then...
     {
       // cout << amount <<" " <<this->getBalance()+this->overdraft;
        char str[80];
        sprintf(str,"{Your account's balance(+ overdraft) is  : %0.3lf and you try to withdraw : %0.3lf }",this->getBalance()+this->overdraft,amount);
        string msg(str);
        throw InSufficientBalance(msg);
        return;
    }
    else
    {
     DEC_Balance(amount); // this->Balance -= amount;
     this->MonthTransactionCount++;
    // this->payInterest();
     return;
    }
}

void CurrentAccount::withdraw(double amount,Date d){

    if(this->MonthTransactionCount>month)// maximum transaction possible is 3
    {
       this->ExtraAmount += amount;
       this->MonthTransactionCount++;
       DEC_Balance(amount);
       return;

    }
    else if (amount > (this->getBalance()+this->overdraft)) // amount is less than balance then...
     {
       // cout << amount <<" " <<this->getBalance()+this->overdraft;
        char str[80];
        sprintf(str,"{Your account's balance(+ overdraft) is  : %0.3lf and you try to withdraw : %0.3lf }",this->getBalance()+this->overdraft,amount);
        string msg(str);
        throw InSufficientBalance(msg);
        return;
    }
    else
    {
     DEC_Balance(amount); // this->Balance -= amount;
     this->MonthTransactionCount++;
    // this->payInterest();1
     this->passbook.push_back(Transaction(d,2,this->getBalance(),amount));
    }
}

void CurrentAccount::setOD_Limit(double amount){

    this->overdraft=amount;
}

 string CurrentAccount::toString(){
     char str[70];
	sprintf(str, "{ %5d, %s, %6.2lf, Overdraft: %0.2f ,MonthTransactionCount: %d, Account type : Current}", this->getAccountNumber(),
         this->GetCustomerName().c_str(),
         this->getBalance(),
         this->overdraft,
         this->MonthTransactionCount);

    return string(str);
 }

void CurrentAccount::eom(){
     double x=this->deductCharges();
     cout <<endl <<"Deducted charges are : " << x << endl;
     this->MonthTransactionCount=0;
}

short CurrentAccount::GetAccountType(){
   return 2;
}

