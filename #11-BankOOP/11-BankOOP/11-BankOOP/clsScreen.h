#pragma once
#include <iostream>
#include "Global.h"
#include "clsDate.h"
using namespace std;

class clsScreen
{
protected:

    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        cout << "\t\t\t\t\t\tUser : " << CurrentUser.GetUserName();
        clsDate DateNow;
        cout << "\n\t\t\t\t\t\tDate : " << clsDate::DateToString(DateNow) << endl;
    }

    static bool ChekcAccessRights(clsUser::enPermissions permission)
    {
        if (!CurrentUser.CheckAccessPermission(permission))
        {
            cout << "\t\t\t\t\t---------------------------------------------------\n";
            cout << "\n\t\t\t\t\t\tAccess Denied !\n\n";
            cout << "\t\t\t\t\t---------------------------------------------------\n";
            return false;
        }
        else
            return true;
    }
};

