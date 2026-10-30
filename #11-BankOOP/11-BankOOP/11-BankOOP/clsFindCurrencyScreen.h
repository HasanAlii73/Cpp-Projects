#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"

class clsFindCurrencyScreen : protected clsScreen
{
protected:

	enum enFindBy{enCode = 1, enCountry = 2};

	static void _PrintCurrenncyCard(clsCurrency Currency)
	{
		cout << "Currency Card\n";
		cout << "\n=================================\n\n";
		cout << "Country  : " << Currency.Country() << endl;
		cout << "Code     : " << Currency.CurrencyCode() << endl;
		cout << "Name     : " << Currency.CurrencyName() << endl;
		cout << "Rate(1$) : " << Currency.Rate() << endl;
		cout << "\n=================================\n\n";
	}

public:

	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("Find Currency Screen");

		cout << "Find Currency By : [1] Code, [2] Country ? ";
		short Choice = clsInputValidate::
			ReadShortNumberBetween(1, 2);

		if (Choice == enCode)
		{
			string Code;
			cout << "Please Enter Currency Code :";
			Code = clsInputValidate::ReadString();

				clsCurrency Currency = clsCurrency::FindByCode(Code);

			if (!Currency.IsEmpty())
			{
				cout << "\nCurrenncy Found :)\n\n";
				_PrintCurrenncyCard(Currency);
			}
			else
			{
				cout << "\nCurrenncy Not Found :(\n\n";
			}
		}
		else
		{
			string Country;
			cout << "Please Enter Currency Code :";
			Country = clsInputValidate::ReadString();

			clsCurrency Currency = clsCurrency::FindByCountry(Country);

			if (!Currency.IsEmpty())
			{
				cout << "\nCurrenncy Found :)\n\n";
				_PrintCurrenncyCard(Currency);
			}
			else
			{
				cout << "\nCurrenncy Not Found :(\n\n";
			}

		}
	}
};

