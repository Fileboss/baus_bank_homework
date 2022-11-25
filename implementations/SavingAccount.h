#ifndef SAVING_ACCOUNT_H
#define SAVING_ACCOUNT_H
#include "Account.h"

class SavingAccount : public Account
{
private:
	int m_interest;
public:
	SavingAccount(int ID, int balance, char* cusName, int interest);
	virtual void deposit(int amount);
};

#endif