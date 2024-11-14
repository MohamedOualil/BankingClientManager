#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDate.h"

class clsTransferScreen:protected clsScreen
{
    static void _PrintClient(clsBankClient Client) {

        cout << "\nClient Card: ";
        cout << "\n_______________________\n";
        cout << "\nFull Name : " << Client.FullName();
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nBalance : " << Client.AccountBalance;
        cout << "\n_______________________\n";
    }

    static string _ReadClientAccNubmer(string Message) {
        string AccountNumber =
            clsInputValidate::ReadString(Message);
        while (!clsBankClient::IsClientObjectExist(AccountNumber)) {
            cout << "Error This AccountNumber " << AccountNumber << " Not Found,\n";
            AccountNumber =
                clsInputValidate::ReadString("Please Enter Account Number? ");
        }
        return AccountNumber;
    }

    static float _ReadAmount(clsBankClient SourceClient) {
        cout << "\nPlease Enter Transfer Amount? ";
        float Amount = clsInputValidate::ReadFloatNumber();

        while (Amount > SourceClient.AccountBalance) {

            cout << "\nAmount Excesseds the available Balance,Enter another Amount ?: ";
            Amount = clsInputValidate::ReadFloatNumber();
        }
        return Amount;
    }

public:

    static void ShowTransderScreen() {
        _DrawScreenHeader("\tTransder Screen");

        string AccountNumberFrom = _ReadClientAccNubmer
        ("\nPlease Enter Your Account Number To Transfer From? ");

        clsBankClient SourceClient = clsBankClient::Find(AccountNumberFrom);
        _PrintClient(SourceClient);

        string AccountNumberTo = _ReadClientAccNubmer
        ("Please Enter Your Account Number To Transfer To? ");

        while (AccountNumberFrom == AccountNumberTo){
            cout << "\nCannot Tranfer to the Same Account!! ";
            AccountNumberTo = _ReadClientAccNubmer
            ("\n Please Enter anothor Account Number To Transfer To? : ");
        } 

        clsBankClient ClientTo = clsBankClient::Find(AccountNumberTo);
        _PrintClient(ClientTo);
        

        float Amount = _ReadAmount(SourceClient);

        char Answer = 'n';

        cout << "\n\nAre you sure you want perform this transaction? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y') {

            if (SourceClient.Transfer(ClientTo, Amount,CurrentUser.UserName)) {
                cout << "\n\nDone Successfully " << endl;
                
            }
            else {
                cout << "\nTransfer Faild. \n";
            }
 

        }
        else {
            cout << "\nTransfer was Cancelled. \n";
        }
        _PrintClient(SourceClient);
        _PrintClient(ClientTo);

        
        
    }

};

