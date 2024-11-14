#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;


class clsAddNewScreen:protected clsScreen
{
    static void _ReadClientInfo(clsBankClient& Client) {
        Client.FirstName = clsInputValidate::ReadString("Enter Your First Name? ");
        Client.LastName = clsInputValidate::ReadString("Enter Your Last Name? ");
        Client.Email = clsInputValidate::ReadString("Enter Your Email? ");
        Client.Phone = clsInputValidate::ReadString("Enter Your Phone? ");
        Client.PinCode = clsInputValidate::ReadString("Enter Your PinCode? ");
        cout << "\nEnter your Account Balance: ";
        Client.AccountBalance = clsInputValidate::ReadIntNumber();
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

    static void AddNewClient() {

        if (!CheckAccessRights(clsUsers::enPermissions::pAddClient)) {
            return;
        }

        string Title = "Add New Screen";
        _DrawScreenHeader(Title);

        string AccountNumber;
        AccountNumber = clsInputValidate::ReadString("Please Enter Your AccountNumber? ");

        while (clsBankClient::IsClientObjectExist(AccountNumber)) {

            cout << "Error This AccountNumber " << AccountNumber << " Not Already Exist,\n";
            getline(cin >> ws, AccountNumber);
        }
        clsBankClient NewClient = clsBankClient::GetAddNewAccountNumber(AccountNumber);
        _ReadClientInfo(NewClient);

        clsBankClient::enSaveResult SaveResult;
        SaveResult = NewClient.Save();
        switch (SaveResult)
        {
        case clsBankClient::enSaveResult::svFailObjectEmpty:
            cout << "\n\nError account was not saved because it's Empty\n";
            break;
        case clsBankClient::enSaveResult::svSuccessed:
            cout << "\nClient Added Successefuly:-( \n";
            _PrintClient(NewClient);
            break;
        case clsBankClient::enSaveResult::svErorrAccNumberExist:
            cout << "\nError account was not saved because account number is used!\n";
            break;
        
        }

        

    }

};

