#pragma once
#include <iostream>
#include <iomanip>
#include "clsUsers.h"
#include "Globle.h"
#include "clsDate.h"
using namespace std;

class clsScreen

{
protected:

	static void _DrawScreenHeader(string Title,string SubTitle ="") {

		cout << "\n\t\t\t\t\t" << "_______________________________________";				 
		cout << "\n\n\t\t\t\t\t\t" << Title << endl;
		if (SubTitle != "") {

			cout << "\t\t\t\t\t\t" << SubTitle << endl;
		}
		cout << "\t\t\t\t\t" <<"_______________________________________\n\n";

		cout << "\t\t\t\t\t\tDate: " << clsDate::DateToString(clsDate());
		
		cout << "\n\t\t\t\t\t\tUser: " << CurrentUser.UserName << endl;
	}

	static bool CheckAccessRights(clsUsers::enPermissions Permission) {

		if (!CurrentUser.CheckAccessPermissions(Permission)) {

			cout << "\t\t\t\t\t----------------------------------------";
			cout << "\n\n\t\t\t\t\t Access Denied, \n";
			cout << "\t\t\t\t\tYou don't Have Permission To Do this, \n";
			cout << "\t\t\t\t\tPlesase Conact Your Admin, \n";
			cout << "\t\t\t\t\t----------------------------------------\n";
			return false;
		}
		else {
			return true;
		}
	}


};

