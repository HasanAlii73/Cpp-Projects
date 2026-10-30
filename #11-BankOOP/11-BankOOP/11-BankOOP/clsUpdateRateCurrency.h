#pragma once
#include "clsFindCurrencyScreen.h"

class clsUpdateRateCurrency : protected clsFindCurrencyScreen
{


public:

	static void ShowUpdatRateCurrencyScreen()
	{
		clsScreen::_DrawScreenHeader("Update Currency Rate");

		string Code;
		cout << "Please Enter Currency Code : ";
		Code = clsInputValidate::ReadString();

		clsCurrency Currency = clsCurrency::FindByCode(Code);

		_PrintCurrenncyCard(Currency);

		cout << "Are you sure you want to update the rate of this currency ? (y/n)";
		char ans; cin >> ans;

		if (ans == 'y' || ans == 'Y')
		{
			cout << "Update Currency Rate : \n";
			cout << "========================\n\n";
			cout << "Enter New Rate : ";
			float Rate; cin >> Rate;
			Currency.UpdateRate(Rate);

			cout << "Currency Rate Updated Succefully :)\n\n";
			_PrintCurrenncyCard(Currency);
		}

	}

};

