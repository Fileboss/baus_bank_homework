#include "AccountHandler.h"
using namespace std;

AccountHandler::AccountHandler()
	: m_accNum{ 0 }
{
}
 
AccountHandler::~AccountHandler()
{
	delete[] m_accArr;
}

void AccountHandler::ShowMenu() const
{
	cout << "-----Menu-----" << endl;
	cout << "1. Open an account" << endl;
	cout << "2. Deposit" << endl;
	cout << "3. Withdraw" << endl;
	cout << "4. Show all account info" << endl;
	cout << "5. Exit" << endl;
}

void AccountHandler::MakeAccount()
{
	// show submenu to select account type
	int choice;
	cout << "-----Select account type-----" << endl;
	cout << "1. Saving" << endl;
	cout << "2. High credit" << endl;
	cout << "Select option: ";
	cin >> choice;
	cout << endl;
	
	switch (choice)
	{
	case 1:
		MakeSavingAccount();
		break;
	case 2:
		MakeHighCreditAccount();
		break;
	default:
		cout << "Invalid selection" << endl;
		break;
	}
}

void AccountHandler::DepositMoney()
{
	int money;
	int id;
	cout << "[Deposit]" << endl;
	cout << "Account ID: ";
	cin >> id;
	cout << "Amount: ";
	cin >> money;

	for (int i = 0; i < m_accNum; i++)
	{
		if (m_accArr[i]->getAccID() == id)
		{
			m_accArr[i]->deposit(money);
			cout << "Deposit complete." << endl << endl;
			return;
		}
	}
	cout << "Invalid ID" << endl << endl;
}

void AccountHandler::WithdrawMoney()
{
	int money;
	int id;
	cout << "[Withdraw]" << endl;
	cout << "Account ID: ";
	cin >> id;
	cout << "Amount: ";
	cin >> money;

	for (int i = 0; i < m_accNum; i++)
	{
		if (m_accArr[i]->getAccID() == id)
		{
			if (m_accArr[i]->withdraw(money) == -1)
			{
				cout << "Insufficient balance." << endl << endl;
				return;
			}
			cout << "Withdraw complete." << endl << endl;
			return;
		}
	}
	cout << "Invalid ID" << endl << endl;
}

void AccountHandler::ShowAllAccInfo() const
{
	for (int i = 0; i < m_accNum; i++)
	{
		m_accArr[i]->ShowAccInfo();
		cout << endl;
	}
}

void AccountHandler::MakeSavingAccount()
{
	int id;
	char name[MAX_NAME_LEN];
	int balance;
	int interest;

	cout << "[Make saving account]" << endl;
	cout << "Account ID: ";
	cin >> id;
	cout << "Name: ";
	cin >> name;
	cout << "Balance: ";
	cin >> balance;
	cout << "Interest rate: ";
	cin >> interest;

	m_accArr[m_accNum++] = new SavingAccount(id, balance, name, interest);
}

void AccountHandler::MakeHighCreditAccount()
{
	int id;
	char name[MAX_NAME_LEN];
	int balance;
	int interest;
	char rate;
	int special;

	cout << "[Make high credit account]" << endl;
	cout << "Account ID: ";
	cin >> id;
	cout << "Name: ";
	cin >> name;
	cout << "Balance: ";
	cin >> balance;
	cout << "Interest rate: ";
	cin >> interest;
	cout << "Special rate (A: 7%, B: 4%, C: 2%): ";
	cin >> rate;

	switch (rate)
	{
	case 'A':
		special = 7;
		break;
	case 'B':
		special = 4;
		break;
	case 'C':
		special = 2;
		break;
	default:
		cout << "Invalid selection" << endl;
		break;
	}

	m_accArr[m_accNum++] = new HighCreditAccount(id, balance, name, interest, special);
}
