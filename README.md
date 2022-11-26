# BAUS Philippe - Object Oriented Programming
## Homework 2

### Exercise 1:
Create a copy constructor :

    Account::Account(const Account& copy)
    	: m_accID{ copy.m_accID }, m_balance{ copy.m_balance }
    {
    	int len = strlen(copy.m_cusName) + 1;
    	m_cusName = new char[len];
    	strcpy_s(m_cusName, len, copy.m_cusName);
    }
Here, the copy constructor is necessary because we want the m_cusName attribute to point to a new memory space, and not to the same text field as the copied object.

Convert all possible member functions into const member function:
In the Account class, the member functions that can become const are : 

    int getAccID() const;
    void ShowAccInfo() const;
Indeed, those 2 functions do not modify the object or call non const function.

### Exercise 2 and 3
I treated both exercises at the same time, I will focus on interesting pieces of code, for more details, please refer to the source code.

The AccountHandler class contains an array of accounts, and proposes operations allowing the user to interact with his accounts. 
This class takes care of displaying a textual interface, creating / finding the right account, and calling the right operations on the accounts with the corresponding parameters.

For SavingAccount and HighCreditAccount, interest is managed at the time of deposit. So the Deposit functions of the two classes must be different, and the Deposit function of the parent class Account must become virtual, so that the correct Deposit function is called at runtime.

Transform Deposit into a virtual Function
`virtual void deposit(int amount);`

Different implementation dependitng on the type of Account:
For SavingAccount :

    void SavingAccount::deposit(int amount)
    {
    	Account::deposit(amount);
    	Account::deposit(amount * (m_interest / 100.0));
    }
For HighCreditAccount:

    void HighCreditAccount::deposit(int amount)
    {
    	SavingAccount::deposit(amount);
    	Account::deposit(amount * (m_specialInterestRate / 100.0));
    }

