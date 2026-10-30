#include <iostream>
#include "clsLoginScreen.h"

int main()

{
    bool x = true;
    while (x)
    {
        x = clsLoginScreen::ShowLoginScreen();
    }
    system("pause>0");
    return 0;
}