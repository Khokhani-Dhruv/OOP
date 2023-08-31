#ifndef EXCEPTION_IS_H
#define EXCEPTION_IS_H

#include <iostream>
#include <cstring>
using namespace std;

class InSufficientBalance{
 private:
     string message;
 public:
      InSufficientBalance(string& message){
         this->message=message;
      }
      string what(){return this->message;}

};

class TransactionLimitExceeds{
     private:
     string message;
 public:
      TransactionLimitExceeds(string& message){
         this->message=message;
      }
      string what(){return this->message;}

};

class AccountNotFound{
   private:
     string message;
 public:
      AccountNotFound(string message){
         this->message=message;
      }
      string what(){return this->message;}
};
#endif // EXCEPTION_IS_H
