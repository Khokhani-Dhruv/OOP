#include <iostream>
#include "bankaccount.h"
#include "savingaccount.h"
#include "currentaccount.h"
#include "bank.h"
#include "date.h"
using namespace std;
int main()
{
    cout << endl << "\t Lab 11 Q1: " << endl;
    cout << "------------------------------------------------------------------" << endl;
       //Lab 10 Q1
    cout<<"\t Lab 10 Q1 : "<<endl<<endl;
    SavingAccount a1("Sunil", 2000);
    CurrentAccount a2("Pankaj", 1000);

    try {
        a1.deposit(5000);
        a1.withdraw(3000);
        cout << "Account-1 Balance: " << a1.getBalance() << endl;
        a1.withdraw(2000);
        //a1.deposit(1500);
        a2.setOD_Limit(10000);
        cout << "Account-2 Balance: " << a2.getBalance() << endl;
        a2.withdraw(5000);
        a2.deposit(3000);
        a2.deposit(3000);
        a2.deposit(3000);
        a2.deposit(3000);
        a2.withdraw(10000);
        cout << "Account-2 Balance: " << a2.getBalance() << endl;
        a2.eom();
        cout << "Account-2 Balance: " << a2.getBalance() << endl;
        //a1.withdraw(2000);
    }
    catch(InSufficientBalance& e) {
        cout << "Error: " << e.what() << endl;
    }
    catch(TransactionLimitExceeds& e) {
        cout << "Error: " << e.what() << endl;
    }
    catch(...) {
        cout << "Unknown Error Occurred! " << endl;
    }

    cout << "------------------------------------------------------------------";


    cout<<endl << "\tLab 10 Q2 : "<<endl<<endl;
    //Lab 10 Q2
    Bank bank;
    bank.open_saving_account("Sunil", 2000); //1001
    bank.open_saving_account("Manisha", 1000); //1003
    bank.open_current_account("Pankaj", 1000); //1005
    bank.open_current_account("Amit", 1000); //1007
    bank.print_all_accounts( cout );
    try
    {
        BankAccount& ba = bank.find( 1003 );
        if (ba.GetAccountType() == BankAccount::CURRENT)
        {
            CurrentAccount& ca = static_cast<CurrentAccount&>(ba);
            ca.setOD_Limit(5000);
        }
        ba.deposit(2000);
        ba.deposit(2500);
        ba.deposit(1000);
        ba.deposit(3000);
        ba.withdraw( 4000 );
        cout << ba.getBalance() << endl;
        ba.eom();
        cout << ba.getBalance() << endl;
        cout << ba.toString() << endl<<endl;
        bank.close(1005);
        bank.print_all_accounts( cout );
    }
    catch(AccountNotFound& e) {
        cout << "Error: " << e.what() << endl;
    }
    catch(InSufficientBalance& e) {
        cout << "Error: " << e.what() << endl;
    }
    catch(TransactionLimitExceeds& e) {
        cout << "Error: " << e.what() << endl;
    }
    catch(...) {
        cout << "Unknown Error Occurred! " << endl;
    }
    cout << "------------------------------------------------------------------";

    cout <<endl << "\tLab 11 Q2 ( for Bankaccount) : " <<endl;

    try{
    BankAccount account_open("Preet", 2000,Date(2021,2,23)); // account open on this date 23-2-2021
    account_open.deposit(2000, Date(2021, 2, 26));
    account_open.withdraw(1000, Date(2021, 2, 27));
    account_open.deposit(5000, Date(2021, 3, 11));
    account_open.withdraw(500, Date(2021, 3, 19));
    account_open.deposit(7000, Date(2021, 3, 24));
    account_open.withdraw(700, Date(2021, 4, 10));
    account_open.deposit(1500, Date(2021, 5, 20));
    account_open.withdraw(2000, Date(2021, 5, 25));
    account_open.withdraw(2000, Date(2021, 6, 10));
    account_open.withdraw(2000, Date(2021, 6, 12));

    vector<Transaction> passbook = account_open.getTransactions(Date(2021,2,26),Date(2021,6,10));
    // 1 deposit ...2..withdraw....if 0 then bankacoount is open that day
    cout << endl << "Transaction from date 27-2-2021 to 10-6-2021"<< endl;
    for(int i=0;i<int(passbook.size());i++)
        cout << passbook[i].GetString() << " type : " << passbook[i].GetAccType() << " Balance : " << passbook[i].GetCurrBalance() <<" Transaction : "<< passbook[i].GetTransactionAmount() << endl;

    double march = account_open.averageMonthlyBalance("2021-03"); // (3000*12 + 8000*8 + 7500*5)/25 = 5500
    cout<<endl << "Average balance of March is: "<<march<<endl; // varify from above passbook


    }
    catch(InSufficientBalance& e) {
        cout << "Error: " << e.what() << endl;
    }

    cout << "------------------------------------------------------------------";


    cout <<endl << "\tLab 11 Q3(for saving bank account) : " <<endl;

    SavingAccount acc("Manav",10000,Date(2021,2,11)); // account open on this day 11-2-2021
    try{
    acc.deposit(2000, Date(2021, 2, 26));
    acc.withdraw(100, Date(2021, 2, 27));
    acc.deposit(5000, Date(2021, 3, 11));
    acc.withdraw(500, Date(2021, 3, 19)); // you can do 4 transaction per day only
    //acc.withdraw(500, Date(2021, 3, 19)); // Here saving account has some transaction limit per month

    vector<Transaction> passbook = acc.getTransactions(Date(2021,2,26),Date(2021,3,19));
    // 1 deposit ...2..withdraw ... if 0 then bankacoount is open that day
    cout << endl << "Transaction from date 27-2-2021 to 19-3-2021"<< endl;
    for(int i=0;i<int(passbook.size());i++)
        cout << passbook[i].GetString() << " type : " << passbook[i].GetAccType() << " Balance : " << passbook[i].GetCurrBalance() <<" Transaction : "<< passbook[i].GetTransactionAmount() << endl;

   double march = acc.averageMonthlyBalance("2021-03"); // here yyyy-mm is more effective than yy-mm
   cout<<endl <<"Average balance of March is: "<<march<<endl;
    }
    catch(TransactionLimitExceeds &e)
    {
        cout << "Error: "<< e.what() << endl;
    }
    catch(InSufficientBalance& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}
