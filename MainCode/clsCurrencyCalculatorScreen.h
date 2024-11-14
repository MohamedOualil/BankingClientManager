#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsCurrency.h"


using namespace std;
class clsCurrencyCalculatorScreen:protected clsScreen
{
    static float _ReadAmount() {
        cout << "\nEnter Amount to Exchange: ";
        float Amount = clsInputValidate::ReadFloatNumber();
        return Amount;
    }

    static void _PrintCurrency(clsCurrency& Currency,string Message) {

        cout << "\n"<< Message;
        cout << "\n_______________________\n";
        cout << "\nCountry : " << Currency.Country();
        cout << "\nCode : " << Currency.CurrencyCode();
        cout << "\nName : " << Currency.CurrencyName();
        cout << "\nRate(1$) : " << Currency.Rate();
        cout << "\n_______________________\n";
    }

    static clsCurrency _GetCurrency(string Title) {

        cout << Title << endl;
        string Code = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExist(Code)) {
            cout << "\nError this Currency Not Found !!";
            Code = clsInputValidate::ReadString("\nPlease Choose another one: ");
        }

        clsCurrency Currency = clsCurrency::FindByCurrencyCode(Code);
        return Currency;
    }

    static void _PrintCalculationsResults(float Amount, clsCurrency Currency1 , clsCurrency Currency2) {
        
        _PrintCurrency(Currency1,"Convert From: ");

        float AmountInUSD = Currency1.ConvertToUSD(Amount);
        cout << endl << Amount << " " << Currency1.CurrencyCode()
            << " = " << AmountInUSD << " USD";
        

        if (Currency2.CurrencyCode() == "USD") {
            return;
        }
        else {
  
            _PrintCurrency(Currency1, "\nConvert From USD to: ");
            float AmountInCurrency2 = Currency1.ConvertToOtherCurrency(Amount, Currency2);

            cout << endl << Amount << " " << Currency1.CurrencyCode()
                << " = " << AmountInCurrency2 << " " << Currency2.CurrencyCode();
        }

    }

public:
    static void ShowCurrencyCalculatorScreen() {
        char Answer = 'n';

        while (true) {
            system("cls");
            _DrawScreenHeader("Update Currency Screen");

            clsCurrency Currency1 = _GetCurrency("\nPlease Enter Currency1 Code: ");
          
            clsCurrency Currency2 = _GetCurrency("\nPlease Enter Currency2 Code: ");
             
            float Amount = _ReadAmount();
            

            _PrintCalculationsResults(Amount,Currency1, Currency2);
            cout << "\n\nDo you want to perform another calculation? y/n ?";
            cin >> Answer;
            if (Answer == 'n' || Answer == 'N')
                break;
        } 
       
    }


};

