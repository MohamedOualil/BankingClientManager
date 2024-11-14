#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsUtil.h"
#include "clsInputValidate.h"
using namespace std;


class clsTotalBalancesScreen:protected clsScreen
{

    static void _PrintTotalBalances(vector <clsBankClient>& vClients) {
        for (clsBankClient& C : vClients) {

            cout << "| " << setw(15) << left << C.AccountNumber();
            cout << "| " << setw(20) << left << C.FullName();
            cout << "| " << setw(10) << left << C.AccountBalance;


            cout << endl;

        }
    }



public:
	

    static void ShowTotalBalanceScreen() {
        vector <clsBankClient>vClients = clsBankClient::GetClientList();

        string title = "Total Balance Screen";
        string Subtitle = "List (" + to_string(vClients.size())+") Client(s).";
        _DrawScreenHeader(title,Subtitle);
        
        cout << "\n_____________________________________________________";
        cout << "______________________________________________________\n\n";

        cout << "| " << left << setw(15) << "Account Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(10) << "Account Balance";

        cout << "\n_____________________________________________________";
        cout << "______________________________________________________\n\n";

        double TotalBalance = clsBankClient::GetTotalBalance();
        if (vClients.size() == 0) {
            cout << "\t\t\tNo Client Available In the System!";
        }
        _PrintTotalBalances(vClients);
        cout << "\n_____________________________________________________";
        cout << "______________________________________________________\n";
        cout << "\n\t\t\t\t\tTotalBalance = " << TotalBalance << endl;
        cout << "\n\t\t\t\t\t(" << clsUtil::NumberToText(TotalBalance) << ")" << endl;

    }


};

