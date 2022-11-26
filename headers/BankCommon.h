#ifndef BANK_H
#define BANK_H

const int MAX_ACCOUNTS = 100;
const int MAX_NAME_LEN = 50;


// Create BANK enum
enum BANK
{
	MAKE = 1,
	DEPOSIT,
	WITHDRAW,
	SHOW,
	EXIT
};

#endif