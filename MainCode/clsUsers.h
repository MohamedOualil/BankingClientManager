#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsPerson.h"
#include "clsDate.h"
#include "clsUtil.h"

class clsUsers : public clsPerson
{
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;
    string _UserName;
    string _Password;
    int _Permissions ;
    bool _MarkForDelete = false;

	static clsUsers _ConvertLineToUserObject(string Line) {
		vector <string> vUsers = clsString::SplitString(Line, "#//#");
		return clsUsers(enMode::UpdateMode, vUsers[0], vUsers[1], vUsers[2], 
			vUsers[3], vUsers[4], clsUtil::Descryption(vUsers[5]), stoi(vUsers[6]));
	}

	static string _ConvertUserObjectToLine(clsUsers User, string Seperator = "#//#") {
		string stUserObject = "";

		stUserObject += User.FirstName + Seperator;
		stUserObject += User.LastName + Seperator;
		stUserObject += User.Email + Seperator;
		stUserObject += User.Phone + Seperator;
		stUserObject += User.UserName + Seperator;
		stUserObject += clsUtil::Encryption(User.Password) + Seperator;
		stUserObject += to_string(User.Permissions);

		return stUserObject;
	}

	static vector <clsUsers> _LordDataFromFile(string FileName) {
		vector <clsUsers> vUsers;

		fstream MyFile;
		MyFile.open(FileName, ios::in);//Read Mode 

		if (MyFile.is_open()) {

			string line;

			while (getline(MyFile, line)) {
				clsUsers Client = _ConvertLineToUserObject(line);
				vUsers.push_back(Client);

			}

			MyFile.close();
		}
		return vUsers;
	}

	static clsUsers _GetEmptyObject() {
		return clsUsers(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static void _AddLineToFile(string FileName,string stDataLine) {
		fstream MyFile;
		MyFile.open(FileName, ios::out | ios::app);//append Mode

		if (MyFile.is_open()) {
			MyFile << stDataLine << endl;


			MyFile.close();
		}
	}

	void _SaveUsersDataToFile(string FileName,vector <clsUsers>& vUsers) {
		fstream MyFile;
		MyFile.open(FileName, ios::out);//write Mode

		string DateLine;
		if (MyFile.is_open()) {

			for (clsUsers& User : vUsers) {

				if (User._MarkForDelete == false) {
					DateLine = _ConvertUserObjectToLine(User);

					MyFile << DateLine << endl;
				}
			}
			MyFile.close();
		}
	}

	void _Update() {

		vector <clsUsers> _vUsers = _LordDataFromFile("Users.txt");


		for (clsUsers& User : _vUsers) {

			if (User.UserName == _UserName) {

				User = *this;
				break;
			}
		}
		_SaveUsersDataToFile("Users.txt",_vUsers);



	}

	void _AddNewOne() {
		_AddLineToFile("Users.txt",_ConvertUserObjectToLine(*this));
	}

	string _PrepereLoginRecord(string Seperator = "#//#") {
		string DateLine = clsDate::DateToString(clsDate()) + " - "
			+ clsDate::GetSystemTime();

		return DateLine + Seperator + UserName + Seperator +
			clsUtil::Encryption(Password) + Seperator + to_string(Permissions);
		 
	}

	struct stLoginResiterRecord;

	static stLoginResiterRecord _ConvertLoginRecordToObject(string Line) {
		vector <string> vUsers = clsString::SplitString(Line, "#//#");

		stLoginResiterRecord LoginR;

		LoginR.DateTime = vUsers[0];
		LoginR.UserName = vUsers[1];
		LoginR.Password = clsUtil::Descryption(vUsers[2]);
		LoginR.Permissions = stoi(vUsers[3]);
		return LoginR;

	}



public:

	struct stLoginResiterRecord {
		string DateTime;
		string UserName;
		string Password;
		int Permissions;


	};

	

	enum enPermissions {
		pAll = -1,
		pClientList = 1,       // 0001
		pAddClient = 2,      // 0010
		pDeleteClient = 4,      // 0100
		pUpdateClient = 8,      // 1000
		pFindClient = 16,       // 10000
		pTransactions = 32,     // 100000
		pManageUser = 64,       // 1000000
		pLoginRegister = 128
	};

	clsUsers(enMode Mode,string FirstName,string LastName,string Email,
		string Phone, string UserName,string Password,int Permission):
		clsPerson(FirstName,LastName,Email,Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permission;
		
	}

	bool IsEmpty() {
		return  (_Mode == enMode::EmptyMode);
	}

	bool MarkForDelete() {
		return _MarkForDelete;
	}


	void SetUserName(string UserName) {
		_UserName = UserName;
	}

	string GetUserName() {
		return _UserName;
	}
    __declspec(property(get = GetUserName, put = SetUserName))string UserName;

	void SetPassword(string Password) {
		_Password = Password;
    }

    string GetPassword() {
        return _Password;
    }

	__declspec(property(get = GetPassword, put = SetPassword))string Password;

	void SetPermission(int Permission) {
		_Permissions = Permission;
	}
	
	int GetPermission() {
		return _Permissions;
	}
	__declspec(property(get = GetPermission, put = SetPermission))int Permissions;

	static clsUsers Find(string UserName) {
		fstream File;
		File.open("Users.txt", ios::in); //ReadMode

		if (File.is_open()) {
			string Line;

			while (getline(File, Line)) {
				clsUsers Client = _ConvertLineToUserObject(Line);
				if (Client.UserName == UserName) {
					File.close();
					return Client;

				}

			}
			File.close();
			
		}
		return _GetEmptyObject();
	}

	static clsUsers Find(string UserName, string Password) {

		fstream MyFile;
		MyFile.open("Users.txt", ios::in);//Read Mode

		if (MyFile.is_open()) {

			string line;

			while (getline(MyFile, line)) {
				clsUsers Client = _ConvertLineToUserObject(line);
				
				if ((Client.UserName == UserName) && (Client.Password == Password)) {
					MyFile.close();
					return Client;
				}


			}

			MyFile.close();
		}
		return _GetEmptyObject();

	}

	static bool IsUserObjectExist(string UserName) {
		clsUsers User = clsUsers::Find(UserName);
		return (!User.IsEmpty());
	}

	enum enSaveResult { svFailObjectEmpty = 0, svSuccessed = 1, svErorrUserNameExist = 2 };

	enSaveResult Save() {
		switch (_Mode)
		{
		case enMode::EmptyMode:
			if (IsEmpty()) {
				return enSaveResult::svFailObjectEmpty;
			}
			break;
		case enMode::UpdateMode:
			_Update();
			return enSaveResult::svSuccessed;
			break;
		case enMode::AddNewMode:
			if (IsUserObjectExist(_UserName)) {
				return enSaveResult::svErorrUserNameExist;
			}
			else {
				_AddNewOne();
				_Mode = enMode::UpdateMode;
				return enSaveResult::svSuccessed;
			}
		default:
			break;
		}
	}

	static clsUsers GetAddNewUserObject(string UserName) {
		return clsUsers(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}

	bool Delete() {
		vector < clsUsers> vUsers = _LordDataFromFile("Users.txt");

		for (clsUsers& User : vUsers) {
			if (User.UserName == _UserName) {

				User._MarkForDelete = true;

				_SaveUsersDataToFile("Users.txt",vUsers);
				*this = _GetEmptyObject();
				return true;
			}
		}
		return false;
	}

	static vector<clsUsers> GetUsersList(string FileName) {
		return _LordDataFromFile(FileName);

	}

	bool CheckAccessPermissions(enPermissions Permissions) {

		if (this->Permissions == enPermissions::pAll) {
			return true;
		}
		if ((Permissions & this->Permissions) == Permissions) {
			return true;
		}
		else
			return false;

	}

	void RegisterLogin() {
		_AddLineToFile("LoginRegister.txt", _PrepereLoginRecord());
	}

	static vector <stLoginResiterRecord> GetLoginList(string FileName) {
		vector <stLoginResiterRecord> vUsers;

		fstream MyFile;
		MyFile.open(FileName, ios::in);//Read Mode 

		if (MyFile.is_open()) {

			string line;
			stLoginResiterRecord Login;
			while (getline(MyFile, line)) {
				Login = _ConvertLoginRecordToObject(line);

				vUsers.push_back(Login);

			}

			MyFile.close();
		}
		return vUsers;
	}


};

