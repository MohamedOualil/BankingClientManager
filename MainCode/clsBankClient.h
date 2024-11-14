#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsPerson.h"
#include "clsDate.h"

using namespace std;
class clsBankClient : public clsPerson
{
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MakeforDelete = false;

	static clsBankClient _ConvertLineToClientObject(string Line) {
		vector <string> vClient = clsString::SplitString(Line, "#//#");
		return clsBankClient(enMode::UpdateMode, vClient[0], vClient[1], vClient[2], vClient[3],
			vClient[4], vClient[5], stof(vClient[6]));
	}

	static string _ConvertClientObjectToLine(clsBankClient Client, string Seperator = "#//#") {
		string stClientObject = "";

		stClientObject += Client.FirstName + Seperator;
		stClientObject += Client.LastName + Seperator;
		stClientObject += Client.Email + Seperator;
		stClientObject += Client.Phone + Seperator;
		stClientObject += Client._AccountNumber + Seperator;
		stClientObject += Client.PinCode + Seperator;
		stClientObject += to_string(Client.AccountBalance);

		return stClientObject;
	}

	static clsBankClient _GetEmptyObject() {
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static vector <clsBankClient> _LordDataFromFile() {
		vector <clsBankClient> vClient;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//Read Mode

		if (MyFile.is_open()) {

			string line;

			while (getline(MyFile, line)) {
				clsBankClient Client = _ConvertLineToClientObject(line);
				vClient.push_back(Client);

			}

			MyFile.close();
		}
		return vClient;
	}

	static void _AddLineToFile(string FileName,string stDataLine) {
		fstream MyFile;
		MyFile.open(FileName, ios::out | ios::app);//append Mode

		if (MyFile.is_open()) {
			MyFile << stDataLine << endl;


			MyFile.close();
		}
	}

	void _SaveClientDataToFile(vector <clsBankClient>& vClient) {
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);//write Mode

		string DateLine;
		if (MyFile.is_open()) {

			for (clsBankClient& C : vClient) {

				if (C._MakeforDelete == false) {
					DateLine = _ConvertClientObjectToLine(C);

					MyFile << DateLine << endl;
				}
			}
			MyFile.close();
		}
	}

	void _Update() {

		vector <clsBankClient> _vClients = _LordDataFromFile();
		

		for (clsBankClient& C : _vClients) {

			if (C.AccountNumber() == AccountNumber()) {

				C = *this;
				break;
			}
		}
		_SaveClientDataToFile(_vClients);
			
		

	}

	void _AddNewOne() {
		_AddLineToFile("Clients.txt",_ConvertClientObjectToLine(*this));
	}

	struct stTransferLog;

	static string _PrepareTransferLogRecord(stTransferLog TransferLog, string Seperator = "#//#") {
		string Log = "";

		Log += TransferLog.DateTime + Seperator;
		Log += TransferLog.AccountNumberFrom + Seperator;
		Log += TransferLog.AccountNumberTo + Seperator;
		Log += to_string(TransferLog.Amount) + Seperator;
		Log += to_string(TransferLog.AccountBalanceFrom) + Seperator;
		Log += to_string(TransferLog.AccountBalanceTo) + Seperator;
		Log += TransferLog.UserName ;
		return Log;
	}

	static stTransferLog _ConvertTransferLogLineToRecord(string Line) {
		stTransferLog Log;
		vector <string>vLogs = clsString::SplitString(Line, "#//#");
		Log.DateTime = vLogs[0];
		Log.AccountNumberFrom = vLogs[1];
		Log.AccountNumberTo = vLogs[2];
		Log.Amount = stof(vLogs[3]);
		Log.AccountBalanceFrom = stof(vLogs[4]);
		Log.AccountBalanceTo = stof(vLogs[5]);
		Log.UserName = vLogs[6];
		return Log;
	}

	void _RegisterTransferLog(clsBankClient& To, float Amount,string UserName
		,string Seperator = "#//#") {
		string TransferLogRecord = "";

		TransferLogRecord += clsDate::DateToString(clsDate()) + " - " + clsDate::GetSystemTime() + Seperator;
		TransferLogRecord += AccountNumber() + Seperator;
		TransferLogRecord += To.AccountNumber() + Seperator;
		TransferLogRecord += to_string(Amount) + Seperator;
		TransferLogRecord += to_string(AccountBalance) + Seperator;
		TransferLogRecord += to_string(To.AccountBalance) + Seperator;
		TransferLogRecord += UserName;

		_AddLineToFile("TransferLog.txt", TransferLogRecord);
	}
public:

	struct stTransferLog {
		string DateTime;
		string AccountNumberFrom ;
		string AccountNumberTo;
		float Amount;
		float AccountBalanceFrom;
		float AccountBalanceTo;
		string UserName;
	};
	
	clsBankClient(enMode Mode,string FirstName,string LastName,string Email,string Phone,string AccountNumber,string Pincode,float AccountBalance)
	: clsPerson(FirstName,LastName,Email,Phone)
	{	
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = Pincode;
		_AccountBalance = AccountBalance;


	}

	bool IsEmpty() {
		return  (_Mode == enMode::EmptyMode);
	}

	string AccountNumber() {
		return _AccountNumber;
	}

	void SetPinCode(string PinCode) {
		_PinCode = PinCode;
	}

	string GetPinCode() {
		return _PinCode;
	}

	__declspec(property(get = GetPinCode, put = SetPinCode))string PinCode;

	void SetAccountBalance(float Balance) {
		_AccountBalance = Balance;
	}

	float GetAccountBalance() {
		return _AccountBalance;
	}

	__declspec(property(get = GetAccountBalance, put = SetAccountBalance))float AccountBalance;

	//void Print() No Uia in The object;

	static clsBankClient Find(string AccountNumber) {
		fstream File;
		File.open("Clients.txt", ios::in); //ReadMode

		if (File.is_open()) {
			string Line;

			while (getline(File, Line)) {
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber) {
					File.close();
					return Client;

				}
				
			}
			File.close();
			
		}
		return _GetEmptyObject();
	}

	static clsBankClient Find(string AccountNumber, string Password) {

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);//Read Mode

		if (MyFile.is_open()) {

			string line;

			while (getline(MyFile, line)) {
				clsBankClient Client = _ConvertLineToClientObject(line);

				if ((Client.AccountNumber() == AccountNumber) && (Client.PinCode == Password)) {
					MyFile.close();
					return Client;
				}


			}

			MyFile.close();
		}
		return _GetEmptyObject();

	}

	static bool IsClientObjectExist(string AccountNumber) {
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		return (!Client.IsEmpty());
	}

	enum enSaveResult{svFailObjectEmpty = 0 ,svSuccessed = 1,svErorrAccNumberExist =2 };

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
			if (IsClientObjectExist(_AccountNumber)) {
				return enSaveResult::svErorrAccNumberExist;
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

	static clsBankClient GetAddNewAccountNumber(string AccountNumber) {
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	bool Delete() {
		vector < clsBankClient> vClients = _LordDataFromFile();

		for (clsBankClient& C : vClients) {
			if (C.AccountNumber() == _AccountNumber) {
				C._MakeforDelete = true;

				_SaveClientDataToFile(vClients);
				*this = _GetEmptyObject();
				return true;
			}
		}
		return false;
	}

	static vector<clsBankClient> GetClientList() {
		return _LordDataFromFile();
		
	}

	static double GetTotalBalance() {
		double TotalBalance = 0;
		vector<clsBankClient> vClients = _LordDataFromFile();

		for (clsBankClient &Client : vClients) {

			TotalBalance += Client.AccountBalance;
		}
		return TotalBalance;
	}

	void Deposit(double Amount) {
		_AccountBalance += Amount;
		Save();

	}

	bool Withdraw(double Amount) {
		if (Amount > AccountBalance) {
			return false;
		}
		else {
			_AccountBalance -= Amount;
			Save();

		}

	}

	static bool Transfer(clsBankClient &From, clsBankClient &To,float Amount) {
		if (Amount > From.AccountBalance) {
			return false;
		}
		else {
			From.AccountBalance -= Amount;
			To.AccountBalance += Amount;
			From.Save();
			To.Save();
		}
	}

	bool Transfer(clsBankClient& To, float Amount,string UserName) {
		if (Amount > AccountBalance) {
			return false;
		}
		
		Withdraw(Amount);
		To.Deposit(Amount);
		_RegisterTransferLog(To, Amount, UserName);
		return true;
		
	}

	static vector <stTransferLog> GetTransferLogList() {
		vector <stTransferLog> vLogs;
		
		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::in);//Read Mode

		if (MyFile.is_open()) {

			string line;
			stTransferLog TransferRecord;

			while (getline(MyFile, line)) {
				TransferRecord = _ConvertTransferLogLineToRecord(line);
				vLogs.push_back(TransferRecord);

			}

			MyFile.close();
		}
		return vLogs;
	}
};

