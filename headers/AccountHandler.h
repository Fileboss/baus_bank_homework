#ifndef ACCOUNT_HANDLER_H
#define ACCOUNT_HANDLER_H
#include "BankCommon.h"
#include "Account.h"
#include "SavingAccount.h"
#include "HighCreditAccount.h"
#include<iostream>

class AccountHandler
{
private:
	Account* m_accArr[MAX_ACCOUNTS];
	int m_accNum;

	int GetAccIdx(int id) const;
public:
	AccountHandler();
	~AccountHandler();
	void ShowMenu() const;
	void MakeAccount();
	// add make a savingAccount
	void MakeSavingAccount();
	// add make a highCreditAccount
	void MakeHighCreditAccount();
	void DepositMoney();
	void WithdrawMoney();
	void ShowAllAccInfo() const;
};

#endif