#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUsers.h"

using namespace std;

class clsShowLoginRegisterScreen :protected clsScreen
{

    static void _PrintUsersList(clsUsers::stLoginResiterRecord& LoginR) {

        cout << "\t"<<"| " << setw(25) << left << LoginR.DateTime;
        cout << "\t"<<"| " << setw(15) << left << LoginR.UserName;
        cout << "\t"<<"| " << setw(10) << left << LoginR.Password;
        cout << "\t"<<"| " << setw(10) << left << LoginR.Permissions;


        cout << endl;
    }



public:

    static void ShowLoginRegisterList() {

        if (!CheckAccessRights(clsUsers::enPermissions::pLoginRegister)) {
            return;
        }

        vector <clsUsers::stLoginResiterRecord>LoginR = clsUsers::GetLoginList("LoginRegister.txt");
        string Title = "Login Register List Screen";
        string SubTitle = "List (" + to_string(LoginR.size()) + ") Login Register(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << "\n\t_____________________________________________________";
        cout << "______________________________________________________\n\n";

        cout << "\t"<< "| " << left << setw(30) << "Date";
        cout << "\t"<< "| " << left << setw(15) << "UserName";
        cout << "\t"<< "| " << left << setw(10) << "Password";
        cout << "\t"<< "| " << left << setw(10) << "Permissions";

        cout << "\n\t_____________________________________________________";
        cout << "______________________________________________________\n\n";

        if (LoginR.size() == 0) {

            cout << "\t\t\tNo Login Register Available In the System!";
        }
        for (clsUsers::stLoginResiterRecord& User : LoginR) {

            _PrintUsersList(User);

        }
        cout << "\n\t_____________________________________________________";
        cout << "______________________________________________________\n";
    }



};

