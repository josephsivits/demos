// SavingsAccount.h
// Definition of SavingsAccount class
#ifndef SAVINGS_H
#define SAVINGS_H

#include "Account.h"

class SavingsAccount : public Account
{
public:
	// constructor initializes balance and interest rate
	SavingsAccount(double, double) : Account(getBalance()) {} ;

	void calculateInterest(double, double);

private:
	/* Please declare data member interestRate*/
	double interestRate;

}; // end class SavingsAccount

#endif