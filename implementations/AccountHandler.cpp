#include "AccountHandler.h"

AccountHandler::AccountHandler()
	: m_accNum{ 0 }
{
}

 
AccountHandler::~AccountHandler()
{
	delete[] m_accArr;
}

int AccountHandler::GetAccIdx(int id) const
{
	for (int i = 0; i < m_accNum; i++)
	{
		if (m_accArr[i]->getAccID() == id)
		{
			return i;
		}
	}
	return -1;
}

void AccountHandler::ShowMenu() const
{
	// Show the menu
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
		MakeSavingAccount(); // Call the MakeSavingAccount function
		break;
	case 2:
		MakeHighCreditAccount(); // Call the MakeHighCreditAccount function
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
	
	int idx = GetAccIdx(id);
	if (idx == -1)
	{
		cout << "Invalid account ID" << endl;
		return;
	}
	m_accArr[idx]->deposit(money); // Calls the corresponding deposit function, because it is a virtual function
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

	int idx = GetAccIdx(id); // Get the index of the account

	if (idx == -1) // If the index is -1, it means that the account does not exist
	{
		cout << "Invalid account ID" << endl;
		return;
	}

	int amount = m_accArr[idx]->withdraw(money);

	if (amount == -1) // If the amount is -1, it means that the account does not have enough money
	{
		cout << "Insufficient balance" << endl;
	}
	else
	{
		cout << "Withdrawal amount: " << amount << endl;
	}
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

	// put rate to upper case so user can alo input a, b or c
	rate = toupper(rate);
	
	// Set the special rate depending on the input Character
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
		return;
	}

	m_accArr[m_accNum++] = new HighCreditAccount(id, balance, name, interest, special);
}
