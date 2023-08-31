#ifndef BANK_H_INCLUDED
#define BANK_H_INCLUDED

#include "bankaccount.h"
#include "currentaccount.h"
#include "savingaccount.h"
#include <map>
#include <cstring>

using namespace std;

class Bank {

private:
    map<int, BankAccount> detail;

public:
    ~Bank();
    BankAccount open_saving_account(string cust_name, int ini_balance=0);
    BankAccount open_current_account(string cust_name, int ini_balance=0);
    BankAccount& find(int acc_no);
    BankAccount close(int acc_no);
    void print_all_accounts(std::ostream& out);
};

#endif // BANK_H_INCLUDED
