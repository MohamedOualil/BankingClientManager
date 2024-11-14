#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsClientListScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsAddNewScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsMangeUserScreen.h"
#include "clsShowLoginRegisterScreen.h"
#include "clseCurrencyExchangeScreen.h"
#include "Globle.h"
using namespace std;
class clsMainScreen : protected clsScreen
{
    enum enMenue {
        eShowClient = 1,
        eAddClient = 2,
        eDeleteClient = 3,
        eUpdateClient = 4,
        eFindClient = 5,
        eTransactions = 6,
        eManageUser = 7,
        eLoginRegister = 8,
        eCurrencyExchange = 9,
        eLogout = 10
    };


    static void _Logout() {
        CurrentUser = clsUsers::Find("", "");
    }

    static void _GoBackToMainMenue() {
        cout << "\nPress any key to go back to Main Menue...";
        system("pause>0");
        ShowMainMenue();
    }

    static void _ShowClientList() {
    
        clsClientListScreen::ShowClientList();
        
    }

    static void _AddNewClient() {
        clsAddNewScreen::AddNewClient();
    }

    static void _DeleteClient() {
        clsDeleteClientScreen::ShowDeleteClientScreen();
    }

    static void _UpdateClient() {
        clsUpdateClientScreen::ShowUpdateClientScreen();
    }

    static void _FindClient() {
        clsFindClientScreen::ShowFindClientScreen();
    }

    static void _ShowTransactionsScreen() {
        clsTransactionsScreen::ShowTransactionsMenue();
    }

    static void _ShowMangeUserScreen() {
        clsMangeUserScreen::ShowUsersMenueScreen();
    }

    static void _ShowLoginRegisterScreen() {
        clsShowLoginRegisterScreen::ShowLoginRegisterList();
    }

    static void _ShowCurrencyExchangeScreen() {
        clseCurrencyExchangeScreen::ShowCurrencyExchange();
    }

    static void _PerformMainMenueOption(enMenue Menue) {

        switch (Menue)
        {
        case enMenue::eShowClient:
            system("cls");
            _ShowClientList();
            _GoBackToMainMenue();
            break;
        case enMenue::eAddClient:
            system("cls");
            _AddNewClient();
            _GoBackToMainMenue();
            break;
        case enMenue::eDeleteClient:
            system("cls");
            _DeleteClient();
            _GoBackToMainMenue();
            break;
        case enMenue::eUpdateClient:
            system("cls");
            _UpdateClient();
            _GoBackToMainMenue();
            break;
        case enMenue::eFindClient:
            system("cls");
            _FindClient();
            _GoBackToMainMenue();
            break;
        case enMenue::eTransactions:
            system("cls");
            _ShowTransactionsScreen();
            _GoBackToMainMenue();
            /*ShowEndScreen();*/
            break;
        case enMenue::eManageUser:
            system("cls");
            _ShowMangeUserScreen();
            _GoBackToMainMenue();
            break;
        case enMenue::eLoginRegister:
            system("cls");
            _ShowLoginRegisterScreen();
            _GoBackToMainMenue();
            break;
        case enMenue::eCurrencyExchange:
            system("cls");
            _ShowCurrencyExchangeScreen();
            _GoBackToMainMenue();
            break;
        case enMenue::eLogout:
            system("cls");
            _Logout();
            break;
        default:
            break;
        }
    }

public:

    static void ShowMainMenue() {
        system("cls");
        _DrawScreenHeader("Main Screen");

        cout <<setw(37)  << left << "" << "=====================================================\n";
        cout <<setw(37)  << left << "" <<"\t\t\tMain Menue \n";
        cout <<setw(37)  << left << "" <<"=====================================================\n";
        cout <<setw(37)  << left << "" <<"\t[1] Show Client List. \n";
        cout <<setw(37)  << left << "" <<"\t[2] Add New Client. \n";
        cout <<setw(37)  << left << "" <<"\t[3] Delete Client. \n";
        cout <<setw(37)  << left << "" <<"\t[4] Update Client Info. \n";
        cout <<setw(37)  << left << "" <<"\t[5] Find Client. \n";
        cout <<setw(37)  << left << "" << "\t[6] Transactions. \n";
        cout <<setw(37)  << left << "" << "\t[7] Manage Users. \n";
        cout <<setw(37)  << left << "" << "\t[8] Login Register . \n";
        cout <<setw(37)  << left << "" << "\t[9] Currency Exchange . \n";
        cout <<setw(37)  << left << "" << "\t[10] Logout. \n";
        cout <<setw(37)  << left << "" <<"=====================================================\n";
        cout <<setw(37)  << left << "" <<"Choose what do you want to do? [1 to 10]? ";
        short Option = clsInputValidate::ReadIntNumberBetween(1, 10, "Invalid! Please Enter Number In The Menu ?");
        _PerformMainMenueOption((enMenue)Option);
    }


};

