#ifndef BANKACCOUNT_H_INCLUDED
#define BANKACCOUNT_H_INCLUDED

#include <iostream>
#include <stdexcept>
#include <string>
#include "exception_is.h"
#include "transaction.h"
#include "date.h"
#include <vector>
using namespace std;

class BankAccount {

private:
    int accno;
    string cust_name;
    double balance;
    static int next_account_no; // = 1001;

protected:
    vector<Transaction> passbook;
    void withdraw_od(double amount);//
    void INC_Balance(double amount);
    void DEC_Balance(double amount);

public:
    //constructors
    BankAccount();
    BankAccount(string cname);
    BankAccount(string cname, double ini_balance);

    BankAccount(Date d);
    BankAccount(string cname,Date d);
    BankAccount(string cname, double ini_balance,Date d);

    // getter/setter functions
    int getAccountNumber();//
    void SetCustomerName(string name);//
    string GetCustomerName(); //
    double getBalance();

    // deposit and withdraw functions
    virtual void deposit(double amount);
    virtual void deposit(double amount,Date d);
    virtual void withdraw(double amount);
    virtual void withdraw(double amount,Date d);
    //void payInterest(double rate);

    // toString()
    virtual string toString(); // here virtual is required

    // virtual functions
    virtual void eod(); //
    virtual void eom(); //

    // Account type
    virtual short GetAccountType(); // 1 for saving and 2 for current

    // static data types .......
    // I don't do it...................
    static int CURRENT;
    static int SAVING;

    // BELOW FUNCTION ARE FOR LAB-11
    double averageMonthlyBalance(string yyyy_mm);
    vector<Transaction> getTransactions(Date from, Date to);
    void operator=(BankAccount &acc);

};


#endif // BANKACCOUNT_H_INCLUDED

