#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsListCurrenciesScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"

using namespace std;
class clseCurrencyExchangeScreen:protected clsScreen
{
    enum enCurrencyMenue {
        eListCurrency = 1, eFindCurrency = 2, eUpdateRate = 3,
        eCurrencyCalculator = 4, eMainMenue = 5
    };

    static void _GoBackToMainMenue() {
        cout << "\nPress any key to go back to Main Menue...";
        system("pause>0");
        ShowCurrencyExchange();
    }

    static short _ReadMenueOption() {
        short choice = 0;
        choice = clsInputValidate::ReadShortNumberBetween(1, 5);
        return choice;
    }

    static void _ShowListCurrenciesScreen() {
        clsListCurrenciesScreen::ShowListCurrenciesScreen();
    }

    static void _ShowFindCurrencyScreen() {
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }

    static void _ShowUpdateRateScreen() {
        clsUpdateRateScreen::ShowUpdateRateScreen();
    }

    static void _ShowCurrencyCalculatorScreen() {
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }

    static void _PerformCurrencyExchangeMenueOption(enCurrencyMenue CurrencyMenue) {
        switch (CurrencyMenue)
        {
        case enCurrencyMenue::eListCurrency:
            system("cls");
            _ShowListCurrenciesScreen();
            _GoBackToMainMenue();
            break;
        case enCurrencyMenue::eFindCurrency:
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToMainMenue();
            break;
        case enCurrencyMenue::eUpdateRate:
            system("cls");
            _ShowUpdateRateScreen();
            _GoBackToMainMenue();
            break;
        case enCurrencyMenue::eCurrencyCalculator:
            system("cls");
            _ShowCurrencyCalculatorScreen();
            _GoBackToMainMenue();
            break;
        case enCurrencyMenue::eMainMenue:
            break;
        }
    }

public:
    static void ShowCurrencyExchange() {
        system("cls");
        _DrawScreenHeader("Currency Exchange Main Screen");

        cout << setw(37) << left << "" << "=====================================================\n";
        cout << setw(37) << left << "" << "\t\t\tCurrency Exchange Menue \n";
        cout << setw(37) << left << "" << "=====================================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies. \n";
        cout << setw(37) << left << "" << "\t[2] Find Currency. \n";
        cout << setw(37) << left << "" << "\t[3] Update Rate. \n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator. \n";
        cout << setw(37) << left << "" << "\t[5] Main Menue. \n";
        cout << setw(37) << left << "" << "=====================================================\n";
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Option = _ReadMenueOption();
        _PerformCurrencyExchangeMenueOption((enCurrencyMenue)Option);
    }



};

