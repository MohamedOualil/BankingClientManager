#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUsers.h"
#include "clsMainScreen.h"
#include "Globle.h"

using namespace std;
class clsShowLoginScreen:protected clsScreen
{
    
    static bool _ReadLoginInfo() {
        string UserName, Password;

        cout << "\n\t\t\t\t\tEnter UserName: ";
        cin >> UserName;

        cout << "\n\t\t\t\t\tEnter Password: ";
        cin >> Password;
        
        CurrentUser = clsUsers::Find(UserName, Password);
        return CurrentUser.IsEmpty();
    }

    static bool _Login() {

        bool LoginFaild = false;
        short Trials = 0;

        do {
            system("cls");
            _DrawScreenHeader("\tLogin Screen");

            if (LoginFaild) {
                Trials++;
                cout << "\t\t\t\t\tInvalid UserName/Password!";
                cout << "\n\t\t\t\t\tYou have " << (3 - Trials) << " To login.\n";
            }

            if (Trials == 3) {
                cout << "\n\t\t\t\t    Your are Locked After 3 faild Trials.\n";
                return false;
            }

            LoginFaild = _ReadLoginInfo();

        } while (LoginFaild);

        CurrentUser.RegisterLogin();
        clsMainScreen::ShowMainMenue();
        return true;
    }

public:

    static bool ShowLoginScreen() 
    {
        return _Login();
    }


};

