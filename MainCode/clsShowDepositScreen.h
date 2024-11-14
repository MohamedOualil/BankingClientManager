#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;

class clsShowDepositScreen:protected clsScreen
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

    static void ShowDepositScreen() {
        _DrawScreenHeader("\tDeposit Screen");

        vector <clsBankClient> vClients = clsBankClient::GetClientList();
        string AccountNumber;
        AccountNumber = clsInputValidate::ReadString("Please Enter Your AccountNumber? ");

        while (!clsBankClient::IsClientObjectExist(AccountNumber)) {
            cout << "\nClient with Account Number (" << AccountNumber << ") Not Exist !\n";
            AccountNumber = clsInputValidate::ReadString("Please Enter Your AccountNumber? ");
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);

        double Amount = 0;
        cout << "\nPlease enter deposit amount? ";
        Amount = clsInputValidate::ReadDoubleNumber();

        char Answer = 'n';

        cout << "\n\nAre you sure you want perform this transaction? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y') {
            Client.Deposit(Amount);
            cout << "\n\nDone Successfully.New Balance is " << Client.AccountBalance << endl;

        }
        else {
            cout << "\nOperation was Cancelled. \n";
        }
        
    }



};

