#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "clsDate.h"
#include "clsString.h"

using namespace std;


class clsInputValidate
{
public:

	static bool IsNumberBetween(int Number, int From, int To) {
		return ((Number >= From) && (Number <= To));
	}

	static bool IsNumberBetween(double Number, double From, double To) {
		return ((Number >= From) && (Number < To));
	}

	static bool IsNumberBetween(float Number, float From, float To) {
		return ((Number >= From) && (Number < To));
	}

	static bool IsDataBetween(clsDate Date, clsDate From, clsDate To) {

		if (clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsData1EqualDate2(Date, From)
			&&
			clsDate::IsData1BeforeDate2(Date, To) == clsDate::IsData1EqualDate2(Date, To)) {
			return true;
		}

		if (clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsData1EqualDate2(Date, To)
			&&
			clsDate::IsData1BeforeDate2(Date, From) == clsDate::IsData1EqualDate2(Date, From)) {
			return true;
		}

		return false;

	}

	static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter again\n") {
		int Number;

		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits < streamsize>::max(), '\n');

			cout << ErrorMessage;
			
		}
		return Number;
	}

	static float ReadFloatNumber(string ErrorMessage = "Invalid Number, Enter again\n") {
		float Number;

		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits < streamsize>::max(), '\n');

			cout << ErrorMessage;

		}
		return Number;
	}

	static double ReadDoubleNumber(string ErrorMessage = "Invalid Number, Enter again\n") {
		double Number;

		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits < streamsize>::max(), '\n');

			cout << ErrorMessage;
			cin >> Number;
		}
		return Number;
	}

	static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Invalid Number, Enter again\n") {
		int Number = ReadIntNumber();
		

		while (!IsNumberBetween(Number, From, To)) {
			cout << ErrorMessage;
			Number = ReadIntNumber();

		} 
		return Number;
		
	}

	static short ReadShortNumberBetween(int From, int To, string ErrorMessage = "Invalid Number, Enter again\n") {
		short Number = ReadIntNumber();


		while (!IsNumberBetween(Number, From, To)) {
			cout << ErrorMessage;
			Number = ReadIntNumber();

		}
		return Number;

	}

	static double ReadDoubleNumberBetween(double From, double To, string ErrorMessage) {
		double Number = ReadDoubleNumber();
		

		while (!IsNumberBetween(Number, From, To)) {

			cout << ErrorMessage;
			Number = ReadDoubleNumber();

		}
		return Number;

	}

	static bool IsValidDate(clsDate Date) {
		return clsDate::IsValiedDay(Date);
	}

	static string ReadString(string Message) {
		string YourString;
		cout << Message;
		getline(cin >> ws, YourString);

		return YourString;
	}

	static string ReadString() {
		string YourString;
		getline(cin >> ws, YourString);

		return YourString;
	}

};

