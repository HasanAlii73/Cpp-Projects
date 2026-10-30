#pragma once
#include "clsScreen.h"
#include "clsListCurrency.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateRateCurrency.h"
#include "clsCurrencyClaculator.h"

class clsCurrenciesExchange : protected clsScreen
{
    enum enCurrencyExchangeMenueOptions
    {
        enListCurrencies = 1, enFindCurrnecy = 2,
        enUpdateRate = 3, enCurrencyCalcualtor = 4,
        enMainMenue = 5
    };

    static short ReadCurrncyExchangeMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5 ? ");
        return Choice;
    }

    static void _GoBackToCurrenciesExchangeMenue()
    {
        cout << "\n\nPress any key to go back to Manage Users Menue...";
        system("pause>0");
        ShowCurrenciesExchangeMenue();
    }

    static void _ShowListCurrencyScreen()
    {
        clsListCurrency::ShowCurrenciesListScreen();
    }

    static void _ShowFindCurrencyScreen()
    {
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }

    static void _ShowUpdateRateScreen()
    {
        clsUpdateRateCurrency::ShowUpdatRateCurrencyScreen();
    }

    static void _ShowCurrencyClacualtorScreen()
    {
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }

    static void _PerformCurrncyExchangeMenueOption(enCurrencyExchangeMenueOptions option)
    {
        switch (option)
        {
        case(enListCurrencies):
        {
            system("cls");
            _ShowListCurrencyScreen();
            _GoBackToCurrenciesExchangeMenue();
            break;
        }

        case(enFindCurrnecy):
        {
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToCurrenciesExchangeMenue();
            break;
        }

        case(enUpdateRate):
        {
            system("cls");
            _ShowUpdateRateScreen();
            _GoBackToCurrenciesExchangeMenue();
            break;
        }

        case(enCurrencyCalcualtor):
        {
            system("cls");
            _ShowCurrencyClacualtorScreen();
            _GoBackToCurrenciesExchangeMenue();
            break;
        }

        case(enMainMenue):
        {

        }


        }
    }

public:

	static void ShowCurrenciesExchangeMenue()
	{
        //if (!ChekcAccessRights(clsUser::enPermissions::pManageUsers))
        //{
        //    return;
        //}

        system("cls");
        _DrawScreenHeader("\t Currency Exchange Main Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Currency Exchange Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currnecy.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calcualtor.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

       _PerformCurrncyExchangeMenueOption((enCurrencyExchangeMenueOptions)ReadCurrncyExchangeMenueOption());
    }

};