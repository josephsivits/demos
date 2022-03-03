// SavingsAccount.cpp
// Member-function definitions for class AsavingsAccount.

#include <iostream>
using namespace std;

 #include "SavingsAccount.h"

// construcotr initializes balance and interest rate
SavingsAccount::SavingsAccount(double initialAmount, double interestR)
	: Account(getBalance())
{
	calculateInterest(initialAmount, interestR);
	cout << "Adding $" << interestRate << " interest to " << etc.
}

// return the amount of interest earned
void SavingsAccount::calculateInterest(double iA, double iR)
{
	interestRate = iR * iA;
}