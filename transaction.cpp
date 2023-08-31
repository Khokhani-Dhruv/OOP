#include "transaction.h"
#include <cstring>
#include <iostream>
using namespace std;
Transaction::Transaction()
{
    this->date=Date();
    this->TransactionType=0;
    this->CurrentBalance=0;
    this->TrasactionAmount=0;
}

Transaction::Transaction(Date d,short type,double curr,double tran){

    this->date=d;
    this->TransactionType=type;
    this->CurrentBalance=curr;
    this->TrasactionAmount=tran;
}

string Transaction::GetString(){
      char str[50];
      sprintf(str,"{Date : %d-%d-%d }",this->date.getDate(),this->date.getMonth(),this->date.getYear());
      return string(str);
}

/*string Transaction::getdate()
{
    char date_is[50];
    sprintf(date_is,"{Date : %d-%d-%d}",this->date.getDate(),this->date.getMonth(),this->date.getYear());
    return string(date_is);
}*/

Date Transaction::GetDate(){
       return this->date;
}

short Transaction::GetAccType(){
        return this->TransactionType;
}

double Transaction::GetCurrBalance(){
        return this->CurrentBalance;
}

double Transaction::GetTransactionAmount(){
        return this->TrasactionAmount;
}
