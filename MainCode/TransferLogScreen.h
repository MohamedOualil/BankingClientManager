#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"
using namespace std;

class TransferLogScreen:protected clsScreen
{

    static void _PrintTransferLogList(clsBankClient::stTransferLog& Log) {

        cout << setw(8)<< left << "" << "| " << setw(23) << left << Log.DateTime;
        cout << "| " << setw(10) << left << Log.AccountNumberFrom;
        cout << "| " << setw(10) << left << Log.AccountNumberTo;
        cout << "| " << setw(12) << left << Log.Amount;
        cout << "| " << setw(10) << left << Log.AccountBalanceFrom;
        cout << "| " << setw(10) << left << Log.AccountBalanceTo;
        cout << "| " << setw(10) << left << Log.UserName;


        cout << endl;
    }

public:

    static void ShowTransferLogList() {

  

        vector <clsBankClient::stTransferLog>vLogs = clsBankClient::GetTransferLogList();
        string Title = "Transfer Log List Screen";
        string SubTitle = "List (" + to_string(vLogs.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_____________________________________________________";
        cout << "______________________________________________________\n\n";

        cout << setw(8) << left << "" << "| " << left << setw(25) << "Date/Time";
        cout << "| " << left << setw(10) << "s.Acct";
        cout << "| " << left << setw(10) << "d.Acct";
        cout << "| " << left << setw(12) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(10) << "User";

        cout << setw(8) << left << "" << "\n\t_____________________________________________________";
        cout << "______________________________________________________\n\n";

        if (vLogs.size() == 0) {

            cout << "\t\t\tNo Record Available In the System!";
        }
        for (clsBankClient::stTransferLog& C : vLogs) {

            _PrintTransferLogList(C);

        }
        cout << setw(8) << left << "" << "\n\t_____________________________________________________";
        cout << "______________________________________________________\n";
    }


};

