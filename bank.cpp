#include <iostream>
#include <map>
#include "exception_is.h"
#include "savingaccount.h"
#include "currentaccount.h"
#include "bankaccount.h"
#include "bank.h"

using namespace std;

Bank::~Bank(){}

BankAccount Bank::open_saving_account(string cust_name, int ini_balance)
{
    SavingAccount temp(cust_name, ini_balance);
    this->detail[temp.getAccountNumber()]=temp;
    return temp;
}

BankAccount Bank::open_current_account(string cust_name, int ini_balance)
{
    CurrentAccount temp(cust_name, ini_balance);
    this->detail[temp.getAccountNumber()]=temp;
    return temp;
}

BankAccount& Bank::find(int acc_no)
{
    auto it = detail.begin();
    it = detail.find(acc_no);
    if(it != detail.end())
        return it->second;
    else
        throw AccountNotFound("Account not found");
}

BankAccount Bank::close(int acc_no)
{
    BankAccount temp = find(acc_no);
    detail.erase(acc_no);
    return temp;

}
void Bank::print_all_accounts(std::ostream& out)
{
    for(auto it = detail.begin(); it!=detail.end(); it++)
    {
        out<<it->second.toString()<<endl;
    }
}



