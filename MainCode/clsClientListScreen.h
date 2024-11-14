#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"
using namespace std;
class clsClientListScreen : protected clsScreen
{
    static void _PrintClientList(clsBankClient &Client) {

        cout << "| " << setw(15) << left << Client.AccountNumber();
        cout << "| " << setw(20) << left << Client.FullName();
        cout << "| " << setw(20) << left << Client.Email;
        cout << "| " << setw(12) << left << Client.Phone;
        cout << "| " << setw(10) << left << Client.PinCode;
        cout << "| " << setw(10) << left << Client.AccountBalance;


        cout << endl;
    }

public:

    static void ShowClientList() {

        if (!CheckAccessRights(clsUsers::enPermissions::pClientList)) {
            return;
        }

        vector <clsBankClient>vClients = clsBankClient::GetClientList();
        string Title = "\t Client List Screen";
        string SubTitle = "\t List (" + to_string(vClients.size()) + ") Client(s).";

        _DrawScreenHeader(Title, SubTitle);
  
        cout << "\n_____________________________________________________";
        cout << "______________________________________________________\n\n";

        cout << "| " << left << setw(15) << "Account Number";
        cout << "| " << left << setw(20) << "Client Name";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(10) << "PinCode";
        cout << "| " << left << setw(10) << "Account Balance";

        cout << "\n_____________________________________________________";
        cout << "______________________________________________________\n\n";

        if (vClients.size() == 0) {

            cout << "\t\t\tNo Client Available In the System!";
        }
        for (clsBankClient& C : vClients) {

            _PrintClientList(C);

        }
        cout << "\n_____________________________________________________";
        cout << "______________________________________________________\n";
    }
};

