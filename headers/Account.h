/*
	This file contains the Account class declaration
	The Account class is the base class for all the
	other account types
*/

#ifndef ACCOUNT_H
#define ACCOUNT_H
class Account
{
private:
	int m_accID;
	int m_balance;
	char* m_cusName;

public:
	Account(int ID, int balance, char* cusName);
	//Add a copy constructor
	Account(const Account& copy);
	~Account();
	int getAccID() const;
	virtual void deposit(int amount);
	int withdraw(int amount);
	void ShowAccInfo() const;
};
#endif