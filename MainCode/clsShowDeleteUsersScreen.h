#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUsers.h"

using namespace std;
class clsShowDeleteUsersScreen:protected clsScreen
{


    static void _PrintUser(clsUsers User) {

        cout << "\nUser Card: ";
        cout << "\n_______________________\n";
        cout << "\nFirst Name : " << User.FirstName;
        cout << "\nLast Name : " << User.LastName;
        cout << "\nFull Name : " << User.FullName();
        cout << "\nEmail : " << User.Email;
        cout << "\nPhone : " << User.Phone;
        cout << "\nUserName : " << User.UserName;
        cout << "\nPassword : " << User.Password;
        cout << "\nPermission : " << User.Permissions;
        cout << "\n_______________________\n";
    }


public:

    static void ShowDeleteUserScreen() {


        _DrawScreenHeader("\tDelete User Screen");

        string UserName = "";
        UserName = clsInputValidate::ReadString("Please Enter Your UserName? ");

        while (!clsUsers::IsUserObjectExist(UserName)) {
            cout << "Error This User " << UserName << " Not Found,\n";
            UserName = clsInputValidate::ReadString("Please Enter Your UserName? ");
        }

        if (UserName == "Admin") {
            cout << "\nYou cannot Delete this User!\n";
            return;
        }

        clsUsers User = clsUsers::Find(UserName);
        _PrintUser(User);
        char Answer = 'n';
        cout << "\n\nAre you sure you want delete this User ? y/n ?";
        cin >> Answer;

        if (toupper(Answer) == 'Y') {

            if (User.Delete()) {
                cout << "\nUser Deleted Successfully: -)\n";
                _PrintUser(User);
            }
            else {
                cout << "\nError User Was not Deleted\n";
            }
        }

    }


};

