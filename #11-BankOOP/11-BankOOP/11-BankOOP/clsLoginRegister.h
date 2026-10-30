#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsScreen.h"

using namespace std;

class clsLoginRegister : public clsScreen
{

private:

    static void PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord User)
    {
        cout << setw(8) << left << "" << "| " << setw(35) << left << User.DateTime;
        cout << "| " << setw(20) << left << User.UserName;
        cout << "| " << setw(20) << left << User.Password;
        cout << "| " << setw(10) << left << User.Permissions;
    }

public:


	static void ShowManageUsersMenue()
	{
        if (!ChekcAccessRights(clsUser::enPermissions::pLoginRegister))
        {
            return;
        }

        vector <clsUser::stLoginRegisterRecord> vUsers = clsUser::GetLoginRegisterList();
        string Title = "\t  Login Register Screen";
        string SubTitle = "\t    (" + to_string(vUsers.size()) + ") Login Register(s).";

        clsScreen::_DrawScreenHeader(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(35) << "Date Time";
        cout << "| " << left << setw(20) << "User Name";
        cout << "| " << left << setw(20) << "Password";
        cout << "| " << left << setw(10) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vUsers.size() == 0)
            cout << "\t\t\t\tNo Logins Available In The System yet!";
        else

            for (clsUser::stLoginRegisterRecord User : vUsers)
            {

                PrintLoginRegisterRecordLine(User);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
	}
};

