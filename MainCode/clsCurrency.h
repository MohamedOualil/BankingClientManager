#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsString.h"
#include "clsDate.h"

class clsCurrency
{
    enum enMode { EmptyMode = 0, UpdateMode = 1 };
    enMode _Mode;

    string _Country;
    string _CurrencyCode;
    string _CurrencyName;
    float _Rate;
    
    static clsCurrency _ConvertLineToCurrencyObject(string Line) {
        vector <string> vCurrency = clsString::SplitString(Line, "#//#");
        return clsCurrency(enMode::UpdateMode, vCurrency[0], vCurrency[1], vCurrency[2],
             stoi(vCurrency[3]));
    }

    static string _ConvertCurrencyObjectToLine(clsCurrency Currency, string Seperator = "#//#") {
        string stCurrencyObject = "";

        stCurrencyObject += Currency.Country() + Seperator;
        stCurrencyObject += Currency.CurrencyCode() + Seperator;
        stCurrencyObject += Currency.CurrencyName() + Seperator;
        stCurrencyObject += to_string(Currency.Rate());

        return stCurrencyObject;
    }

    static vector <clsCurrency> _LordDataFromFile(string FileName) {
        vector <clsCurrency> vCurrency;

        fstream MyFile;
        MyFile.open(FileName, ios::in);//Read Mode 

        if (MyFile.is_open()) {

            string line;

            while (getline(MyFile, line)) {
                clsCurrency Currency = _ConvertLineToCurrencyObject(line);
                vCurrency.push_back(Currency);

            }

            MyFile.close();
        }
        return vCurrency;
    }

    static clsCurrency _GetEmptyObject() {
        return clsCurrency(enMode::EmptyMode,"", "", "", 0);
    }

    void _SaveCurrencyDataToFile(string FileName, vector <clsCurrency>& vUsers) {
        fstream MyFile;
        MyFile.open(FileName, ios::out);//write Mode

        string DateLine;
        if (MyFile.is_open()) {

            for (clsCurrency& User : vUsers) {
                
                DateLine = _ConvertCurrencyObjectToLine(User);

                MyFile << DateLine << endl;
                
            }
            MyFile.close();
        }
    }

    void _Update() {

        vector <clsCurrency> _vCurrency = _LordDataFromFile("Currencies.txt");


        for (clsCurrency& Currency : _vCurrency) {

            if (Currency.CurrencyCode() == _CurrencyCode) {

                Currency = *this;
                break;
            }
        }
        _SaveCurrencyDataToFile("Currencies.txt", _vCurrency);



    }
public:

    clsCurrency(enMode Mode,string Country,string CurrencyCode,string CurrencyName,float Rate) {
        _Mode = Mode;
        _Country = Country;
        _CurrencyCode = CurrencyCode;
        _CurrencyName = CurrencyName;
        _Rate = Rate;
    }

    bool IsEmpty() {
        return  (_Mode == enMode::EmptyMode);
    }


    string Country() {
        return _Country;
    }
    string CurrencyCode() {
        return _CurrencyCode;
    }
    string CurrencyName() {
        return _CurrencyName;
    }

    float Rate() {
        return _Rate;
    }

    void UpdateRate(float UpdateRate) {
        _Rate = UpdateRate;
        _Update();
    }

    static vector <clsCurrency> GetCurrencyList(string FileName) {
        return _LordDataFromFile(FileName);
    }

    static clsCurrency FindByCurrencyCode(string CurrencyCode) {

        CurrencyCode = clsString::UpperAllString(CurrencyCode);
        fstream File;
        File.open("Currencies.txt", ios::in); //ReadMode

        if (File.is_open()) {
            string Line;

            while (getline(File, Line)) {
                clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
                if (Currency.CurrencyCode() == CurrencyCode) {
                    File.close();
                    return Currency;

                }

            }
            File.close();

        }
        return _GetEmptyObject();
    }

    static clsCurrency FindByCountry(string Country) {

        Country = clsString::UpperAllString(Country);
        fstream File;
        File.open("Currencies.txt", ios::in); //ReadMode

        if (File.is_open()) {
            string Line;

            while (getline(File, Line)) {
                clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
                if (clsString::UpperAllString(Currency.Country()) == Country) {
                    File.close();
                    return Currency;

                }

            }
            File.close();

        }

    }

    static bool IsCurrencyExist(string Name) {
        clsCurrency Currency = clsCurrency::FindByCurrencyCode(Name);
        return (!Currency.IsEmpty());
    }

    float ConvertToUSD(float Amount) {
        return (float)(Amount / Rate());
    }

    float ConvertToOtherCurrency(float Amount, clsCurrency Currecny2) {
        float AmountInUSD = ConvertToUSD(Amount);

        if (Currecny2.CurrencyCode() == "USD") {
            return AmountInUSD;
        }

        return (float)(AmountInUSD * Currecny2.Rate());
    }

};