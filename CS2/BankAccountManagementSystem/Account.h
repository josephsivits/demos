// Account.h
// Defintiion of Accound class
#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
public:
	Account(double); // constructor initializes balance
	void credit(double);
	bool debit(double);

	void setBalance(double);
	double getBalance();

private:
	double balance; // data member that stores teh balance
}; // end class Account

#endif