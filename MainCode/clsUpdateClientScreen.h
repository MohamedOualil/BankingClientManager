#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;


class clsUpdateClientScreen:protected clsScreen
{
    static void _ReadClientInfo(clsBankClient& Client) {
        Client.FirstName = clsInputValidate::ReadString("Enter Your First Name? ");
        Client.LastName = clsInputValidate::ReadString("Enter Your Last Name? ");
        Client.Email = clsInputValidate::ReadString("Enter Your Email? ");
        Client.Phone = clsInputValidate::ReadString("Enter Your Phone? ");
        Client.PinCode = clsInputValidate::ReadString("Enter Your PinCode? ");
        cout << "\nEnter your Account Balance: ";
        Client.AccountBalance = clsInputValidate::ReadFloatNumber();
    }

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

    static void ShowUpdateClientScreen() {

        if (!CheckAccessRights(clsUsers::enPermissions::pUpdateClient)) {
            return;
        }

        _DrawScreenHeader("\tUpdate Client Screen");
        string AccountNumber = "";
        AccountNumber = clsInputValidate::ReadString("Please Enter Your AccountNumber? ");

        while (!clsBankClient::IsClientObjectExist(AccountNumber)) {
            cout << "Error This AccountNumber " << AccountNumber << " Not Found,\n";
            AccountNumber = clsInputValidate::ReadString("Please Enter Your AccountNumber? ");
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);

        cout << "----------------------------------------\n";
        cout << "\tUpdate Clients Info Screen \n";
        cout << "----------------------------------------\n";
        _ReadClientInfo(Client);

        clsBankClient::enSaveResult SaveResult;
        SaveResult = Client.Save();

        switch (SaveResult)
        {
        case clsBankClient::enSaveResult::svFailObjectEmpty:
            cout << "\n\nError account was not saved because it's Empty\n";
            break;
        case clsBankClient::enSaveResult::svSuccessed:
            cout << "\nClient Updated Successefuly:-( \n";
            break;
        case clsBankClient::enSaveResult::svErorrAccNumberExist:
            break;
        default:
            break;
        }


    }



};

