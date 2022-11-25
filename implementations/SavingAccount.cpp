#include"SavingAccount.h"
#include<iostream>
using namespace std;

SavingAccount::SavingAccount(int ID, int balance, char* cusName, int interest)
	: Account(ID, balance, cusName), m_interest{ interest }
{
}

// the interest is added to the balance when the deposit is made
void SavingAccount::deposit(int amount)
{
	Account::deposit(amount);
	Account::deposit(amount * (m_interest / 100.0));
}