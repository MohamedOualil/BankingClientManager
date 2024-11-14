#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsShowDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "TransferLogScreen.h"
using namespace std;

class clsTransactionsScreen:protected clsScreen
{

    enum enTransactions {
        eDeposit = 1,
        eWithdraw = 2,
        eTotalBalance = 3,
        eTransfer = 4,
        eTransferLog = 5,
        eMainMenue = 6
    };

    static short _ReadTransactionsMenueOption() {

        cout << "Choose what do you want to do? [1 to 6]? ";
        short Option = clsInputValidate::ReadIntNumberBetween(1, 6, 
            "Invalid! Please Enter Number In The Menu ?");
        return Option;
    }

    static void _GoBackToTransactionsMenue() {
        cout << "\nPress any key to go back to Main Menue...";
        system("pause>0");
        ShowTransactionsMenue();
    }
   
    static void _ShowDepositScreen() {
        clsShowDepositScreen::ShowDepositScreen();
    }
     
    static void _ShowWithdrawScreen() {
        clsWithdrawScreen::ShowWithdrawScreen();
    }
     
    static void _ShowTotalBalances() {
        
        clsTotalBalancesScreen::ShowTotalBalanceScreen();
    }

    static void _TransferScreen() {
        clsTransferScreen::ShowTransderScreen();
    }

    static void _TransferLogScreen() {
        TransferLogScreen::ShowTransferLogList();
    }
    
    static void _PerformTransactionsMenueOption(enTransactions Transactions) {
        switch (Transactions)
        {
        case enTransactions::eDeposit:
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenue();
            break;
        case enTransactions::eWithdraw:
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenue();
            break;
        case enTransactions::eTotalBalance:
            system("cls");
            _ShowTotalBalances();
            _GoBackToTransactionsMenue();
            break;
        case enTransactions::eTransfer:
            system("cls");
            _TransferScreen();
            _GoBackToTransactionsMenue();
            break;
        case enTransactions::eTransferLog:
            system("cls");
            _TransferLogScreen();
            _GoBackToTransactionsMenue();
            break;
        case enTransactions::eMainMenue:
        {

        }

        }
    }

public:

    static void ShowTransactionsMenue() {
        if (!CheckAccessRights(clsUsers::enPermissions::pTransactions)) {
            return;
        }
        system("cls");

        _DrawScreenHeader("\tTransactions Screen");
        cout <<setw(37) << left << "" << "=====================================================\n";
        cout <<setw(37) << left << "" << "\t\tTransactions Menue \n";
        cout <<setw(37) << left << "" << "=====================================================\n";
        cout <<setw(37) << left << "" << "\t[1] Deposit. \n";
        cout <<setw(37) << left << "" << "\t[2] Withdraw. \n";
        cout <<setw(37) << left << "" << "\t[3] Total Balances. \n";
        cout <<setw(37) << left << "" << "\t[4] Transfer. \n";
        cout <<setw(37) << left << "" << "\t[5] TransferLog. \n";
        cout <<setw(37) << left << "" << "\t[6] Main Menue. \n";
        cout <<setw(37) << left << "" << "=====================================================\n";

        short Option = _ReadTransactionsMenueOption();
        _PerformTransactionsMenueOption((enTransactions)Option);
        
        
    }



};

