#include <iostream>
#include <stdexcept>
#include <vector>
#include "bankaccount.h"
#include "date.h"
#include "transaction.h"

using namespace std;
//static int next_account_no = 1001;

int BankAccount::next_account_no = 1001;
int BankAccount::CURRENT=2;
int BankAccount::SAVING=1;


// protected/...........
 void BankAccount::withdraw_od(double amount){
    return;
 }

void BankAccount::INC_Balance(double amount){
   this->balance += amount;
}

void BankAccount::DEC_Balance(double amount){
   this->balance -= amount;
}

 // public ......................
 BankAccount::BankAccount(){

    this->accno = next_account_no;
    this->cust_name ="";
    this->balance = 0;
    BankAccount::next_account_no++;
 }

BankAccount::BankAccount(std::string cname){

    this->accno = next_account_no;
    this->cust_name = cname;
    this->balance = 0;
    BankAccount::next_account_no++;

}

BankAccount::BankAccount(std::string cname, double ini_balance) {

    this->accno = next_account_no;
    this->cust_name = cname;
    this->balance = ini_balance;
    BankAccount::next_account_no++;

}
BankAccount::BankAccount(Date d){

    this->accno = next_account_no;
    this->cust_name ="";
    this->balance = 0;
    BankAccount::next_account_no++;
    this->passbook.push_back(Transaction(d,0,this->balance,0));
 }

BankAccount::BankAccount(std::string cname,Date d){

    this->accno = next_account_no;
    this->cust_name = cname;
    this->balance = 0;
    BankAccount::next_account_no++;
    this->passbook.push_back(Transaction(d,0,this->balance,0));

}

BankAccount::BankAccount(std::string cname, double ini_balance,Date d) {

    this->accno = next_account_no;
    this->cust_name = cname;
    this->balance = ini_balance;
    BankAccount::next_account_no++;
    this->passbook.push_back(Transaction(d,0,this->balance,0));

}
int BankAccount::getAccountNumber(){
     return this->accno;
}

void BankAccount::SetCustomerName(string name){
    this->cust_name = name;
}

string BankAccount::GetCustomerName(){
   return this->cust_name;
}

double BankAccount::getBalance() {

    return this->balance;

}
void BankAccount::deposit(double amount) {
   this->balance += amount;
}
void BankAccount::withdraw(double amount) {

    if (amount > this->balance)
    {
        char str[50];
        sprintf(str,"{Insufficient balance}");
        string msg(str);
        throw InSufficientBalance(msg);
        return;
    }

    this->balance -= amount;
}

void BankAccount::deposit(double amount,Date d) {
   this->balance += amount;
   this->passbook.push_back(Transaction(d,1,this->balance,amount));
}

void BankAccount::withdraw(double amount,Date d) {

    if (amount > this->balance)
    {
        char str[50];
        sprintf(str,"{Insufficient balance}");
        string msg(str);
        throw InSufficientBalance(msg);
        return;
    }
    this->balance -= amount;
    this->passbook.push_back(Transaction(d,2,this->balance,amount));

}
/*void BankAccount::payInterest(double rate) {

    this->balance += this->balance * rate/12/100;

}*/

std::string BankAccount::toString() {

    char str[50];
	sprintf(str, "{ %5d, %s, %6.2lf}", this->accno, this->cust_name.c_str(), this->balance);

    return std::string(str);

}

void BankAccount::eod(){
     return;
}

void BankAccount::eom(){
    return;
}

short BankAccount::GetAccountType(){
    return 0;
}
// LAB 11 METHODS......................
double BankAccount::averageMonthlyBalance(string yyyy_mm){
    int yy = 1000*(yyyy_mm[0] -'0') + 100*(yyyy_mm[1]-'0') + 10*(yyyy_mm[2]-'0') + (yyyy_mm[3]-'0');
    int mm = 10*(yyyy_mm[5] -'0') + (yyyy_mm[6]-'0');
    double avg=0;
    double days_total=0;
    for(int i=0;i<int(this->passbook.size());i++){
        if(this->passbook[i].GetDate().getYear()==yy && this->passbook[i].GetDate().getMonth()==mm){
             double count_days=double(this->passbook[i].GetDate().daysFrom(this->passbook[i-1].GetDate()));
             avg = avg + this->passbook[i-1].GetCurrBalance()*count_days;
             days_total = days_total + count_days;
        }

    }
  //  cout <<" "<<days_total << endl;
    return (avg/days_total);

}

vector<Transaction> BankAccount::getTransactions(Date from, Date to){

    vector<Transaction> details;
    //vector<Transaction> iterator :: iter;
    for(int i=0;i<int(this->passbook.size());i++){

        if((from.compareTo(this->passbook[i].GetDate()))==-1 || from.compareTo(this->passbook[i].GetDate())==0){
                 if((to.compareTo(this->passbook[i].GetDate()))==1 || to.compareTo(this->passbook[i].GetDate())==0){
            details.push_back(this->passbook[i]);
            }
        }

    }
  return details;
}

void BankAccount::operator=(BankAccount &acc){

    this->accno=acc.getAccountNumber();
    this->balance=acc.getBalance();
    this->cust_name=acc.GetCustomerName();
    this->passbook=acc.passbook;


}


