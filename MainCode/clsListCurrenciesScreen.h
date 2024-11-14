#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsCurrency.h"

using namespace std;
class clsListCurrenciesScreen:protected clsScreen
{

    static void _PrintCurrencyList(clsCurrency& Currency) {

        cout << "| " << setw(30) << left << Currency.Country();
        cout << "| " << setw(8) << left << Currency.CurrencyCode();
        cout << "| " << setw(37) << left << Currency.CurrencyName();
        cout << "| " << setw(8) << left << Currency.Rate();


        cout << endl;
    }



public:


    static void ShowListCurrenciesScreen() {


        vector <clsCurrency>vCurrency = clsCurrency::GetCurrencyList("Currencies.txt");
        string Title = "\t Currencies List Screen";
        string SubTitle = "\t List (" + to_string(vCurrency.size()) + ") Currency.";

        _DrawScreenHeader(Title, SubTitle);

        cout << "\n_____________________________________________________";
        cout << "______________________________________________________\n\n";

        cout << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(8) << "Code";
        cout << "| " << left << setw(37) << "Name";
        cout << "| " << left << setw(8) << "Rate/ (1$)";

        cout << "\n_____________________________________________________";
        cout << "______________________________________________________\n\n";

        if (vCurrency.size() == 0) {

            cout << "\t\t\tNo Currency Available In the System!";
        }
        for (clsCurrency& Currency : vCurrency) {

            _PrintCurrencyList(Currency);

        }
        cout << "\n_____________________________________________________";
        cout << "______________________________________________________\n";
    }
};

