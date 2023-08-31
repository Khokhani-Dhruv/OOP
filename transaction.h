#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "date.h"
#include <cstring>
#include <iostream>
using namespace std;

class Transaction{
   private:
       Date date;
       short TransactionType;
       double CurrentBalance;
       double TrasactionAmount;
   public:
      Transaction();
      Transaction(Date d,short type,double curr,double tran);

      string GetString();
      Date GetDate();

      short GetAccType();
      double GetCurrBalance();
      double GetTransactionAmount();


};
#endif // TRANSACTION_H
