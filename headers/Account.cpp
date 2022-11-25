#include <iostream>
#include "Account.h"
using namespace std;

Account::Account(int ID, int balance, char* cusName)
	: m_accID{ ID }, m_balance{ balance }
{
	int len = strlen(cusName) + 1;
	m_cusName = new char[len];
	strcpy_s(m_cusName, len, cusName);
}

//Implement the copy constructor
Account::Account(const Account& copy)
	: m_accID{ copy.m_accID }, m_balance{ copy.m_balance }
{
	int len = strlen(copy.m_cusName) + 1;
	m_cusName = new char[len];
	strcpy_s(m_cusName, len, copy.m_cusName);
}

Account::~Account()
{
	delete[] m_cusName;
}

int Account::getAccID() const
{
	return m_accID;
}

void Account::deposit(int amount)
{
	m_balance += amount;
}

int Account::withdraw(int amount) {
	if (m_balance < 0 || amount > m_balance)
	{
		return -1;
	}
	m_balance -= amount;
	return amount;
}

void Account::ShowAccInfo() const
{
	cout << "Account ID: " << m_accID << endl;
	cout << "Name: " << m_cusName << endl;
	cout << "Balance: " << m_balance << endl;
}
