// CheckingAccount.h
// Definition of CheckingAccount class
#ifndef CHECKING_H
#define CHECKING_H

#include "Account.h"

class CheckingAccount : public Account
{
public:
	// constructor initializes balance and transaction fee
	CheckingAccount(double, double) : Account(getBalance()) {} ;

	void credit(double);
	bool debit(double);

private:
	double transactionFee;

	// utility function to charge fee
	void chargeFee(double);
}; // end class CheckingAccount

#endif