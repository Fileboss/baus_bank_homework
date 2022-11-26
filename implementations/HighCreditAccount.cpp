#include"HighCreditAccount.h"

using namespace std;

HighCreditAccount::HighCreditAccount(int ID, int balance, char* cusName, int interest, int special)
	: SavingAccount(ID, balance, cusName, interest), m_specialInterestRate{ special }
	//Call the SavingAccount constructor and initialize the specialInterestRate
{
}

void HighCreditAccount::deposit(int amount)
{	
	SavingAccount::deposit(amount); // Call the deposit function of SavingAccount so the normal rate is added
	Account::deposit(amount * (m_specialInterestRate / 100.0)); // Add the special rate by using the deposit function of Account so the normal rate is not added again
}
