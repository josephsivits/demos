// bankAccounts.cpp
// Test program for Account hierarchy.

#include <iostream>
#include <iomanip>
using namespace std;

#include "Account.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"

int main()
{
	Account account1(50.0); // create Account object
	SavingsAccount account2(25.0, 0.03); // create SavingsAccount object
	CheckingAccount account3(80.0, 1.0); // create CheckingAccount object

	cout << fixed << setprecision(2);

	// display initial balance of each object
	cout << "account1 balance : $" << account1.getBalance() << endl;
	cout << "account2 balance : $" << account2.getBalance() << endl;
	cout << "account3 balance : $" << account3.getBalance() << endl;

	system("pause");
	return 0;
}

