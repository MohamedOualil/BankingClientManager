#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUsers.h"

using namespace std;
class clsShowListUsers : protected clsScreen
{
    static void _PrintUsersList(clsUsers& User) {

        cout << "| " << setw(15) << left << User.UserName;
        cout << "| " << setw(20) << left << User.FullName();
        cout << "| " << setw(20) << left << User.Email;
        cout << "| " << setw(12) << left << User.Phone;
        cout << "| " << setw(10) << left << User.Password;
        cout << "| " << setw(10) << left << User.Permissions;


        cout << endl;
    }



public:

    static void ShowUserList() {

        
        vector <clsUsers>vUsers = clsUsers::GetUsersList("Users.txt");
        string Title = "\t User List Screen";
        string SubTitle = "\t List (" + to_string(vUsers.size()) + ") User(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << "\n_____________________________________________________";
        cout << "______________________________________________________\n\n";

        cout << "| " << left << setw(15) << "UserName";
        cout << "| " << left << setw(20) << "User Name";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(10) << "Permissions";

        cout << "\n_____________________________________________________";
        cout << "______________________________________________________\n\n";

        if (vUsers.size() == 0) {

            cout << "\t\t\tNo User Available In the System!";
        }
        for (clsUsers& User : vUsers) {

            _PrintUsersList(User);

        }
        cout << "\n_____________________________________________________";
        cout << "______________________________________________________\n";
    }



};

