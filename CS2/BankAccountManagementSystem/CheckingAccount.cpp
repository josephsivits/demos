// CheckingAccount.cpp
// Member-function definitions for class CheckingAccount

#include <iostream>
using namespace std;

#include "CheckingAccount.h" // CheckingAccount class definition

CheckingAccount::CheckingAccount(double initialBalance, double initialInterest)
	: Account(getBalance())
{
	chargeFee(1.0);
	if (initialBalance >= 0.0)
		setBalance(initialBalance);
	else
	{
		cout << "Error: Initial balance cannot be negative." << endl;
		setBalance(0.0);
	} // end if...else
} // end accountConstructor

// credit (add) an amount to the account balance and charge fee
void CheckingAccount::credit(double creditAmount)
{
	setBalance(getBalance() + creditAmount);
}


// Debit (subtract) an amount from the account balance and charge fee
bool CheckingAccount::debit(double amount)
{
	if (amount > getBalance())
	{
		cout << "Debit amount exceeded account balance." << endl;
		return false;
	}
	else // debit amount does not exceed balance
	{
		setBalance(getBalance() - amount);
		return true;
	} // end else
} // end function debit


// Subtract transaction fee
void CheckingAccount::chargeFee(double amount)
{
	if (debit(amount) == true)
	{
		cout << "$1 transaction fee charged.";
		setBalance(getBalance() - 1);
	}
}