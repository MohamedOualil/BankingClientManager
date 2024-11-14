#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

class clsFindClientScreen :protected clsScreen
{

    static void _PrintClient(clsBankClient Client) {

        cout << "\nClient Card: ";
        cout << "\n_______________________\n";
        cout << "\nFirst Name : " << Client.FirstName;
        cout << "\nLast Name : " << Client.LastName;
        cout << "\nFull Name : " << Client.FullName();
        cout << "\nEmail : " << Client.Email;
        cout << "\nPhone : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword : " << Client.PinCode;
        cout << "\nBalance : " << Client.AccountBalance;
        cout << "\n_______________________\n";
    }

public:

    static void ShowFindClientScreen() {
        if (!CheckAccessRights(clsUsers::enPermissions::pFindClient)) {
            return;
        }
        _DrawScreenHeader("\tFind Client Screen");
        string AccountNumber =
            clsInputValidate::ReadString("Please Enter Your AccountNumber? ");
        while (!clsBankClient::IsClientObjectExist(AccountNumber)) {
            cout << "Error This AccountNumber " << AccountNumber << " Not Found,\n";
            AccountNumber =
                clsInputValidate::ReadString("Please Enter Your AccountNumber? ");
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);

        if (!Client.IsEmpty()) {
            cout << "\nClient Found: -) \n";
        }
        else {
            cout << "\n Client Was Not Found: -(\n";
        }

        _PrintClient(Client);

    }



};

