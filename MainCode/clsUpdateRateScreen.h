#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsCurrency.h"


using namespace std;
class clsUpdateRateScreen:protected clsScreen
{

    static void _PrintCurrency(clsCurrency& Currency) {

        cout << "\nCurrency Card: ";
        cout << "\n_______________________\n";
        cout << "\nCountry : " << Currency.Country();
        cout << "\nCode : " << Currency.CurrencyCode();
        cout << "\nName : " << Currency.CurrencyName();
        cout << "\nRate(1$) : " << Currency.Rate();
        cout << "\n_______________________\n";
    }

    static float _ReadRate() {
        float NewRate = 0;
        cout << "\n\nEnter New Rate: ";
        NewRate = clsInputValidate::ReadFloatNumber();
        return NewRate;
    }

public:

	static void ShowUpdateRateScreen() {
		_DrawScreenHeader("Update Currency Screen");

		string Code = clsInputValidate::ReadString("\nPlease Enter Currency Code: ");
        while (!clsCurrency::IsCurrencyExist(Code)) {
            cout << "\nError this Currency Not Found !!";
            Code = clsInputValidate::ReadString("\nPlease Enter Currency Code: ");
        }

        clsCurrency Currency = clsCurrency::FindByCurrencyCode(Code);
        _PrintCurrency(Currency);

        char Answer = 'n';
        cout << "\nAre you sure you want to update the rate of this Currency y/n? ";
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y') {
            
            cout << "\nUpdate Currency Rate:";
            cout << "\n_______________________"; 

            Currency.UpdateRate(_ReadRate());

            cout << "\n\nCureency Rate Updated Successfully : -) ";
            _PrintCurrency(Currency);


        }




	}
};

