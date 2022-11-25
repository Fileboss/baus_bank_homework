// Class HighCreditAccount inherits of SavingAccount. it has 2 interest rate, the one from 
// SavingAccount, and another one called specialInterestRate. 
#include "SavingAccount.h"

#ifndef HIGH_CREDIT_ACCOUNT
#define HIGH_CREDIT_ACCOUNT

class HighCreditAccount : public SavingAccount
{
private:
	int m_specialInterestRate;
public:
	HighCreditAccount(int ID, int balance, char* cusName, int interest, int special);
	virtual void deposit(int money);
};

#endif