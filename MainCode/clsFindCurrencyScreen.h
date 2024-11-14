#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsCurrency.h"

using namespace std;

class clsFindCurrencyScreen:protected clsScreen
{

    static void _PrintCurrency(clsCurrency Currency) {

        cout << "\nCurrency Card: ";
        cout << "\n_______________________\n";
        cout << "\nCountry : " << Currency.Country();
        cout << "\nCode : " << Currency.CurrencyCode();
        cout << "\nName : " << Currency.CurrencyName();
        cout << "\nRate(1$) : " << Currency.Rate();
        cout << "\n_______________________\n";
    }

    static void _ShowResult(clsCurrency Currency) {

        if (!Currency.IsEmpty()) {
            cout << "\nCurrency Found: -) \n";
            _PrintCurrency(Currency);
        }
        else {
            cout << "\nCurrency Was Not Found: -(\n";
        }
    }

public:

    static void ShowFindCurrencyScreen() {

        _DrawScreenHeader("Find Currency Screen");

        cout << "\nFind By: [1] Code or [2] Country ?: ";
        short Answer = clsInputValidate::ReadIntNumberBetween(1, 2);

        if (Answer == 1) {
            string Code;
            Code = clsInputValidate::ReadString
            ("\nPlease Enter Your Currency Code? ");
            clsCurrency Currency = clsCurrency::FindByCurrencyCode(Code);
            _ShowResult(Currency);
        }
        else {
            string CountryName;
            CountryName = clsInputValidate::ReadString
            ("\nPlease Enter Your Currency Code? ");
            clsCurrency Currency = clsCurrency::FindByCountry(CountryName);
            _ShowResult(Currency);
        }

    }

};

