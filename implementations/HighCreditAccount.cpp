#include"HighCreditAccount.h"
#include<iostream>
using namespace std;

HighCreditAccount::HighCreditAccount(int ID, int balance, char* cusName, int interest, int special)
	: SavingAccount(ID, balance, cusName, interest), m_specialInterestRate{ special }
{
}

void HighCreditAccount::deposit(int amount)
{
	SavingAccount::deposit(amount);
	Account::deposit(amount * (m_specialInterestRate / 100.0));
}