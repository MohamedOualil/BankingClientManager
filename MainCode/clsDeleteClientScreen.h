#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

using namespace std;

class clsDeleteClientScreen:protected clsScreen
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

    static void ShowDeleteClientScreen() {
        if (!CheckAccessRights(clsUsers::enPermissions::pDeleteClient)) {
            return;
        }
        
        _DrawScreenHeader("\tDelete Client Screen");

        string AccountNumber = "";
        AccountNumber = clsInputValidate::ReadString("Please Enter Your AccountNumber? ");

        while (!clsBankClient::IsClientObjectExist(AccountNumber)) {
            cout << "Error This AccountNumber " << AccountNumber << " Not Found,\n";
            AccountNumber = clsInputValidate::ReadString("Please Enter Your AccountNumber? ");
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);
        char Answer = 'n';
        cout << "\n\nAre you sure you want delete this User ? y/n ?";
        cin >> Answer;

        if (toupper(Answer) == 'Y') {

            if (Client.Delete()) {
                cout << "\nClient Deleted Successfully: -)\n";
                _PrintClient(Client);
            }
            else {
                cout << "\nError Client Was not Deleted\n";
            }
        }

    }



};

