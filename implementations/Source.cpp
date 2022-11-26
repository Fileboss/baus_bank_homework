#include<iostream>
#include "Account.h"
#include "AccountHandler.h"
#include "BankCommon.h"
using namespace std;


int main()
{
	AccountHandler manager;
	int choice;
	bool run = true;

	while (run)
	{
		manager.ShowMenu();
		cout << "Select option: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case BANK::MAKE:
			manager.MakeAccount();
			break;
		case BANK::DEPOSIT:
			manager.DepositMoney();
			break;
		case BANK::WITHDRAW:
			manager.WithdrawMoney();
			break;
		case BANK::SHOW:
			manager.ShowAllAccInfo();
			break;
		case BANK::EXIT:
			run = false;
			break;
		default:
			cout << "Invalid selection" << endl;
			break;
		}
	}
	return 1;
}