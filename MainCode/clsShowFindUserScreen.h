#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUsers.h"

using namespace std;
class clsShowFindUserScreen :protected clsScreen
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

    static void ShowFindUserScreen() {

        _DrawScreenHeader("\tFind User Screen");
        string UserName =
            clsInputValidate::ReadString("Please Enter Your UserName? ");
        while (!clsUsers::IsUserObjectExist(UserName)) {
            cout << "Error This UserName " << UserName << " Not Found,\n";
            UserName =
                clsInputValidate::ReadString("Please Enter Your UserName? ");
        }

        clsUsers User = clsUsers::Find(UserName);

        if (!User.IsEmpty()) {
            cout << "\nUser Found: -) \n";
        }
        else {
            cout << "\nUser Was Not Found: -(\n";
        }

        _PrintUser(User);

    }


};

