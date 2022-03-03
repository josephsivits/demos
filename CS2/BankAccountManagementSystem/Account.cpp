// Account.cpp
// Member-function defintiions for class Account.
#include <iostream>
using namespace std;

#include "Account.h"

// Account constructor initializes data member balance
Account::Account(double initialBalance)
{
	if (initialBalance >= 0.0)
		balance = initialBalance;
	else
	{
		cout << "Error: Initial balance cannot be negative." << endl;
		balance = 0.0;
	} // end if...else
} // end accountConstructor

void Account::credit(double amount)
{
	balance = balance + amount; // add amount to balance
} // end fuanction credit

bool Account::debit(double amount)
{
	if (amount > balance)
	{
		cout << "Debit amount exceeded account balance." << endl;
		return false;
	} // end if
	else // debit amount does not exceed balance
	{
		balance = balance - amount;
		return true;
	} //  end else
} // end function debit

double Account::getBalance()
{
	return balance;
} // end function getBalance