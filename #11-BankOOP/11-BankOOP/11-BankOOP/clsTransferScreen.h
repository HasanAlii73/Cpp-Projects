#pragma once
#include<iostream>
#include  "clsScreen.h"

using namespace std;

class clsTransferScreen : protected clsDepositScreen
{

	static void _PrintClientTransfer(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}

public:

	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\t   Transfer Screen");

		cout << "The Client You Want to Transfer from : \n";
		string AccountNumber = _ReadAccountNumber();


		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
			AccountNumber = _ReadAccountNumber();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClientTransfer(Client1);

		cout << "The Client You Want to Transfer to : \n";
		AccountNumber = _ReadAccountNumber();


		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
			AccountNumber = _ReadAccountNumber();
		}

		clsBankClient Client2 = clsBankClient::Find(AccountNumber);
		_PrintClientTransfer(Client2);

		double Amount = 0;
		cout << "\nPlease enter transfer amount? ";
		Amount = clsInputValidate::ReadDblNumber();

		while (Amount > Client1.AccountBalance)
		{
			cout << "Amount Excessed the Total Balance, Enter another Amount : ";
			Amount = clsInputValidate::ReadDblNumber();
		}

		cout << "\nAre you sure you want to perform this transaction? ";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			Client1.Transfer(Amount, Client2, CurrentUser.UserName);
			cout << "\nAmount Transfered Successfully.\n";
			_PrintClientTransfer(Client1);
			_PrintClientTransfer(Client2);
		}
		else
		{
			cout << "\nOperation was cancelled.\n";
		}
	}

};

