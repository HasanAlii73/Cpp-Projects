#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"
#include "clsInputValidate.h"

class clsLoginScreen :protected clsScreen
{

private:

    static  bool _Login()
    {
        bool LoginFaild = false;

        string Username, Password;
        short trials = 3;
        do
        {
            if (LoginFaild)
            {
                trials--;
                cout << "\nInvlaid Username/Password!\n";
                cout << "You Have  " << trials << "  Trials to Login.\n\n";
                if (trials == 0)
                {
                    cout << "You are Locked After 3 Failed Trials\n\n";
                    return false;
                }
            }

            cout << "Enter Username? ";
            Username = clsInputValidate::ReadString();

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);

        CurrentUser.RegisterLogin();
        clsMainScreen::ShowMainMenue();
        return true;

    }

public:


    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        return _Login();
    }

};